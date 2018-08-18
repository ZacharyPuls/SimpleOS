
#include "cpuid.h"

/*
 * Set the 31st bit of the EFLAGS register (ID bit), then read it back and 
 * verify it has been changed. If it has, then the CPUID instruction is
 * supported on this processor.
 */
bool cpuid_supported() {
    uint32_t __eax;
    uint32_t __ebx;
    __asm__ __volatile__(
        "pushfd\n"
        "pop %%eax\n"
        "mov %%eax, %ebx\n"
        "xor %%eax, $0x200000\n"
        "push %%eax\n"
        "popfd\n"
        "pushfd\n"
        "pop %%eax\n"
        "popfd\n"
        : "=&a" (__eax), "=&b" (__ebx)
        :
        : "eax", "ebx"
    );

    return ((__eax ^ __ebx) & 0x00200000);
}

/*
 * Call the CPUID instruction with EAX set to {command}, and return the output
 * in a __cpuid_t struct. CPUID returns its result into the EAX, EBX, ECX, and
 * EDX registers. 
 */
__cpuid_t cpuid(const uint32_t command) {
    __cpuid_t cpuid_info = { 0 };

    __asm__ __volatile__(
        "mov %4, %%eax\n"
        "cpuid\n"
        : "=&a" (cpuid_info.eax), "=b" (cpuid_info.ebx), "=c" (cpuid_info.ecx), "=d" (cpuid_info.edx)
        : "r" (command) 
        : "eax", "ebx", "ecx", "edx"
    );

    return cpuid_info;
}

__cpuinfo_t cpuinfo() {
    __cpuid_t cpuid_info = cpuid(__CPUID_OPERATION_VERSION_AND_FEATURE_INFORMATION__);
    __cpuinfo_t cpuinfo = {
        .stepping_id = cpuid_info.eax & __CPUID_VERSION_STEPPING_ID__,
        .model_id = __CPUID_MODEL_ID__(cpuid_info.eax & __CPUID_VERSION_MODEL_ID__, cpuid_info.eax & __CPUID_VERSION_EXTENDED_MODEL_ID__),
        .family_id = __CPUID_FAMILY_ID__(cpuid_info.eax & __CPUID_VERSION_FAMILY_ID__, cpuid_info.eax & __CPUID_VERSION_EXTENDED_FAMILY_ID__),
        .type = (__processor_type_t)(cpuid_info.eax & __CPUID_VERSION_TYPE__),
        .brand_index = cpuid_info.ebx & __CPUID_VERSION_BRAND_INDEX__,
        .clflush_line_size = cpuid_info.ebx & __CPUID_VERSION_CLFLUSH_LINE_SIZE__,
        .max_addressable_ids = cpuid_info.ebx & __CPUID_VERSION_ADDRESSABLE_IDS__,
        .initial_apic_id = cpuid_info.ebx & __CPUID_VERSION_INITIAL_APIC_ID__,
        .supported_features = cpuid_info.ecx,
        .supported_features_ext = cpuid_info.edx
    };    
    return cpuinfo;
}
