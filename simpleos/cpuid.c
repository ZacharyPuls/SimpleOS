
#include "cpuid.h"

/*
 * Set the 21st bit of the EFLAGS register (ID bit), then read it back and 
 * verify it has been changed. If it has, then the CPUID instruction is
 * supported on this processor.
 */
bool __cpuid_supported() {
    uint32_t __eax;
    uint32_t __ebx;
    __asm__ __volatile__(
        "pushf\n"
        "pushf\n"
        "pop %0\n"
        "mov %0, %1\n"
        "xor %2, %0\n"
        "push %0\n"
        "popf\n"
        "pushf\n"
        "pop %0\n"
        "popf\n"
        : "=&r" (__eax), "=&r" (__ebx)
        : "i" (0x00200000)
        :
    );

    return ((__eax ^ __ebx) & 0x00200000);
}

/*
 * Call the CPUID instruction with EAX set to {command}, and return the output
 * in a __cpuid_t struct. CPUID returns its result into the EAX, EBX, ECX, and
 * EDX registers. 
 */
__cpuid_t __get_cpuid(const uint32_t command) {
    __cpuid_t cpuid_info = { 0 };
    cpuid_info.eax = command;

    __asm__ __volatile__(
        "cpuid\n"
        : "+&a" (cpuid_info.eax), "=&b" (cpuid_info.ebx), "=&c" (cpuid_info.ecx), "=&d" (cpuid_info.edx)
        : 
        :
    );

    return cpuid_info;
}

uint32_t __get_cpuid_max_extended_input_value() {
    return __get_cpuid(__CPUID_OPERATION_EXTENDED_INFORMATION__).eax;
}

char *__parse_brandinfo_segment(uint32_t segment) {
    char buf[4] = {
        segment & 0x000000FF,
        segment & 0x0000FF00,
        segment & 0x00FF0000,
        segment & 0xFF000000
    };
    return buf;
}

char *__get_cpuid_brandinfo() {
    char brandinfo[48];
    uint32_t maxinput = __get_cpuid_max_extended_input_value();
    if (maxinput & __CPUID_OPERATION_EXTENDED_INFORMATION__) {
        // Brand string method supported.
        __cpuid_t string = __get_cpuid(__CPUID_OPERATION_BRAND_STRING_A__);
        __strapp(brandinfo, __parse_brandinfo_segment(string.eax), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ebx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ecx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.edx), 4);
        string = __get_cpuid(__CPUID_OPERATION_BRAND_STRING_B__);
        __strapp(brandinfo, __parse_brandinfo_segment(string.eax), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ebx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ecx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.edx), 4);
        string = __get_cpuid(__CPUID_OPERATION_BRAND_STRING_C__);
        __strapp(brandinfo, __parse_brandinfo_segment(string.eax), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ebx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.ecx), 4);
        __strapp(brandinfo, __parse_brandinfo_segment(string.edx), 4);
    } else {
        // Brand string method unsupported, TODO: fall back to brand index table.
    }
    return brandinfo;
}

__cpuinfo_t __get_cpuinfo() {
    __cpuid_t cpuid_info = __get_cpuid(__CPUID_OPERATION_VERSION_AND_FEATURE_INFORMATION__);
    __cpuinfo_t cpuinfo = {
        .stepping_id = cpuid_info.eax & __CPUID_VERSION_STEPPING_ID__,
        .model_id = __CPUID_MODEL_ID__((cpuid_info.eax & __CPUID_VERSION_MODEL_ID__), (cpuid_info.eax & __CPUID_VERSION_EXTENDED_MODEL_ID__)),
        .family_id = __CPUID_FAMILY_ID__((cpuid_info.eax & __CPUID_VERSION_FAMILY_ID__), (cpuid_info.eax & __CPUID_VERSION_EXTENDED_FAMILY_ID__)),
        .type = (__processor_type_t)(cpuid_info.eax & __CPUID_VERSION_TYPE__),
        .brand_index = cpuid_info.ebx & __CPUID_VERSION_BRAND_INDEX__,
        .brand_string = __get_cpuid_brandinfo(),
        .clflush_line_size = cpuid_info.ebx & __CPUID_VERSION_CLFLUSH_LINE_SIZE__,
        .max_addressable_ids = cpuid_info.ebx & __CPUID_VERSION_ADDRESSABLE_IDS__,
        .initial_apic_id = cpuid_info.ebx & __CPUID_VERSION_INITIAL_APIC_ID__,
        .supported_features = cpuid_info.ecx,
        .supported_features_ext = cpuid_info.edx
    };    
    return cpuinfo;
}