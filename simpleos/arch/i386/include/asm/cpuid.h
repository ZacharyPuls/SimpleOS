#ifndef __SIMPLEOS_CPUID_H__
#define __SIMPLEOS_CPUID_H__

#include <stdbool.h>
#include <stdint.h>

typedef struct __cpuid {
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
} __cpuid_t;

/*******************************
 * CPUID Instruction Arguments *
 *******************************/

/*
 * Basic CPUID Information, Version, Brand, CLFLUSH line size, Max addressable IDs, Initial APIC ID, and Feature Information
 * 
 * Input: EAX = 0x01
 * Output: EAX = bits 0-3: Stepping ID, 
 *               bits 4-7: Model ID,
 *               bits 8-11: Family ID,
 *               bits 12-13: Processor Type, 
 *               bits 14-15: Reserved,
 *               bits 16-19: Extended Model ID,
 *               bits 20-27: Extended Family ID,
 *               bits 28-31: Reserved
 *         EBX = bits 0-7: Brand Index, 
 *               bits 8-15: CLFLUSH line size (in bits),
 *               bits 16-23: Max # of addressable IDs,
 *               bits 24-31: Initial APIC ID
 *         ECX = Feature Information
 *         EDX = Feature Information
 * 
 * Processor Type
 *  0x0 = Original OEM Processor
 *  0x1 = Intel OverDrive Processor
 *  0x2 = Dual Processor (N/A for i486 processors)
 *  0x3 = Reserved
 * 
 * Processor Family
 *  Extended Family ID is used when Family ID == 0xF (Family = Extended Family ID + Family ID)
 *  Right-justify and zero-extend 4-bit field.
 * 
 * Processor Model
 *  Extended Model ID is used when Family ID == 0x6 or 0xF (Model = Extended Model ID << 4 + Model ID)
 *  Right-justify and zero-extend 4-bit field.
 * 
 * ECX Feature Information (bit set == feature supported)
 *  bit  0: SSE3                    (SSE3 Extensions)
 *  bit  1: PCLMULQDQ               (Carryless Multiplication)
 *  bit  2: DTES64                  (64-bit DS Area)
 *  bit  3: MONITOR                 (MONITOR/MWAIT)
 *  bit  4: DS-CPL                  (CPL Qualified Debug Store)
 *  bit  5: VMX                     (Virtual Machine Extensions)
 *  bit  6: SMX                     (Safer Mode Extensions)
 *  bit  7: EIST                    (Enhanced Intel SpeedStep Technlogy)
 *  bit  8: TM2                     (Thermal Monitor 2)
 *  bit  9: SSSE3                   (SSSE3 Extensions)
 *  bit 10: CNXT-ID                 (L1 Context ID, IA32_MISC_ENABLE_MSR bit 24)
 *  bit 11: SDBG                    (Silicon Debug, IA32_DEBUG_INTERFACE_MSR)
 *  bit 12: FMA                     (Fused Multiply Add)
 *  bit 13: CMPXCHG16B
 *  bit 14: xTPR Update Control     (IA32_MISC_ENABLE bit 23)
 *  bit 15: PDCM                    (Perf/Debug Capability MSR, IA32_PERF_CAPABILITIES)
 *  bit 16: Reserved
 *  bit 17: PCID                    (Process-Context Identifiers, CR4.PCIDE)
 *  bit 18: DCA                     (Direct Cache Access, prefetch from memory-mapped device)
 *  bit 19: SSE4_1                  (SSE 4.1)
 *  bit 20: SSE4_2                  (SSE 4.2)
 *  bit 21: x2APIC
 *  bit 22: MOVBE
 *  bit 23: POPCNT
 *  bit 24: TSC-Deadline
 *  bit 25: AESNI
 *  bit 26: XSAVE                   (XSAVE/XRSTOR extended states, XSETBV/XGETBV instructions, and XCR0)
 *  bit 27: OSXSAVE                 (O/S has set CR4.OSXSAVE[bit 18] to enable XSETBV/XGETBV instructions to access XCR0, enable extended processor state management)
 *  bit 28: AVX
 *  bit 29: F16C
 *  bit 30: RDRAND
 *  bit 31: Unused, Always 0
 * 
 * EDX Feature Information (bit set == feature supported)
 *  bit  0: FPU                     (x87 FPU is on-chip)
 *  bit  1: VME                     (Virtual 8086 mode enhancements, CR4.VME controls feature, CR4.PVI protected-mode virtual interrupts, software interrupt indirection, expansion of TSS, EFLAGS.VIF/EFLAGS.VIP)
 *  bit  2: DE                      (Debugging Extensions, support for I/O breakpoints, CR4.DE controls feature, optional trapping of accesses to DR4/DR5)
 *  bit  3: PSE                     (Page Size Extension, support for large pages of size 4MB, CR4.PSE controls feature, dirty bit in PDE, optional reserved bit trapping in CR3/PDEs/PTEs)
 *  bit  4: TSC                     (Time Stamp Counter, RDTSC instruction is supported, CR4.TSD controls privilege)
 *  bit  5: MSR                     (Model-Specific Registers, support for RDMSR/WRMSR instructions)
 *  bit  6: PAE                     (Physical Address Extension, support for addresses greater than 32-bit, extended page table entry formats, extra level in page translation tables, 2MB pages are supported instead of 4MB pages if PAE bit is 1)
 *  bit  7: MCE                     (Machine Check Exception, support for Exception 18 [MCE], CR4.MCE controls feature)
 *  bit  8: CX8                     (Compare-and-exchange 8 bytes, support for CMPXCHG8B instruction, implicitly locked and atomic)
 *  bit  9: APIC                    (APIC is on-chip, processor contains an Advanced Programable Interrupt Controller, responding to memory-mapped command in the address range 0xFFFE0000 to 0xFFFE0FFF [by default, some processors permit relocation of APIC address space])
 *  bit 10: Reserved
 *  bit 11: SEP                     (SYSENTER/SYSEXIT, support for SYSENTER/SYSEXIT instructions and associated MSRs)
 *  bit 12: MTRR                    (Memory Type Range Registers, support for MTRRs, MTRRcap MSR contains feature bits that describe what memory types are supported, how many variable MTRRs are supported, and whether fixed MTRRs are supported)
 *  bit 13: PGE                     (Page Global Bit, support for PGE in paging-structure entries that map a page, CR4.PGE controls feature, PGE indicates TLB entries that are common to different processes and do not need to be flushed)
 *  bit 14: MCA                     (Machine Check Architecture, support for MCA of reporting machine errors, MCG_CAP MSR contains feature bits describing how many banks of error reporting MSRs are supported)
 *  bit 15: CMOV                    (Conditional Move Instructions, support for CMOV instruction, support for FCOMI/FCMOV instructions is an x87 FPU is present on-chip [bit 1, CPUID.FPU])
 *  bit 16: PAT                     (Page Attribute Table, support for PAT, which augments the MTRRs, allowing an O/S to specify attributes of memory accessed through a linear address on a 4KB granularity)
 *  bit 17: PSE-36                  (36-Bit Page Size Extension, support for 4MB pages addressing physical memory beyond 4GB, upper bits of the physical address of a 4MB page are encoded in bits 13-20 of the Page-Directory Entry, addresses are limited by MAXPHYADDR, up to 40bits in size)
 *  bit 18: PSN                     (Processor Serial Number, support for 96-bit processor identification number, feature is already enabled)
 *  bit 19: CLFSH                   (CLFLUSH Instruction, support for CLFLUSH instruction)
 *  bit 20: Reserved
 *  bit 21: DS                      (Debug Store, support for the ability to write debug information into a memory-resident buffer, used by branch trace store [BTS] and processor event-based sampling [PEBS])
 *  bit 22: ACPI                    (Thermal Monitor and Software-Controlled Clock Facilities, support for internal MSRs that the processor uses to regulate clock speed in response to temp increase [i.e. thermal throttling])
 *  bit 23: MMX                     (MMX, support for MMX)
 *  bit 24: FXSR                    (Fast Save/Restore of Floating Point Context, support for FXSAVE/FXRSTOR instructions, feature controlled by CR4.OSFXSR)
 *  bit 25: SSE                     (SSE)
 *  bit 26: SSE2                    (SSE2)
 *  bit 27: SS                      (Self-Snoop, support for management of conflicting memory types, done by performing a snoop of its own cache structure for transactions issued to the bus)
 *  bit 28: HTT                     (Max APIC IDs reserved field is Valid, 0 == only one logical processor in package, 1 == more than one, described by "Max # of addressable IDs" [bits 16-23] in EBX)
 *  bit 29: TM                      (Thermal Monitor, support for thermal monitor automatic control circuitry [TCC])
 *  bit 30: Reserved
 *  bit 31: PBE                     (Pending Break Enable, support for the use of the FERR#/PBE# pin when the processor is in the stop-clock state [STPCLK# is asserted], which signals the processor that an interrupt is pending and that the processor should return to normal operation to handle it, IA32_MISC_ENABLE MSR [bit 10/PBE enable] controls feature)
 */

#define __CPUID_OPERATION_VERSION_AND_FEATURE_INFORMATION__ 0x00000001
#define __CPUID_OPERATION_EXTENDED_INFORMATION__            0x80000000
#define __CPUID_OPERATION_BRAND_STRING_A__                  0x80000002
#define __CPUID_OPERATION_BRAND_STRING_B__                  0x80000003
#define __CPUID_OPERATION_BRAND_STRING_C__                  0x80000004

#define __CPUID_VERSION_STEPPING_ID__           0x0000000F
#define __CPUID_VERSION_MODEL_ID__              0x000000F0
#define __CPUID_VERSION_FAMILY_ID__             0x00000F00
#define __CPUID_VERSION_TYPE__                  0x00003000
#define __CPUID_VERSION_EXTENDED_MODEL_ID__     0x000F0000
#define __CPUID_VERSION_EXTENDED_FAMILY_ID__    0x00F00000

typedef enum __processor_type {
    ORIGINAL_OEM =      0x0,
    INTEL_OVERDRIVE =   0x1,
    DUAL_PROCESSOR =    0x2,
    RESERVED =          0x3
} __processor_type_t;

#define __CPUID_FAMILY_ID__(familyid, familyid_ext) \
        (familyid == 0xF ? (familyid_ext + familyid) : familyid)

#define __CPUID_MODEL_ID__(modelid, modelid_ext) \
        (modelid == 0x6 || modelid == 0xF ? ((modelid_ext << 4) + modelid) : modelid)


#define __CPUID_VERSION_BRAND_INDEX__       0x000000FF
#define __CPUID_VERSION_CLFLUSH_LINE_SIZE__ 0x0000FF00
#define __CPUID_VERSION_ADDRESSABLE_IDS__   0x00FF0000
#define __CPUID_VERSION_INITIAL_APIC_ID__   0xFF000000

#define __CPUID_FEATURE_SSE3_               0x00000001
#define __CPUID_FEATURE_PCLMULQDQ__         0x00000002
#define __CPUID_FEATURE_DTES64__            0x00000004
#define __CPUID_FEATURE_MONITOR__           0x00000008
#define __CPUID_FEATURE_DS_CPL__            0x00000010
#define __CPUID_FEATURE_VMX__               0x00000020
#define __CPUID_FEATURE_SMX__               0x00000040
#define __CPUID_FEATURE_EIST__              0x00000080
#define __CPUID_FEATURE_TM2__               0x00000100
#define __CPUID_FEATURE_SSSE3__             0x00000200
#define __CPUID_FEATURE_CNXT_ID__           0x00000400
#define __CPUID_FEATURE_SDBG__              0x00000800
#define __CPUID_FEATURE_FMA__               0x00001000
#define __CPUID_FEATURE_CMPXCHG16B__        0x00002000
#define __CPUID_FEATURE_XTPR__              0x00004000
#define __CPUID_FEATURE_PDCM__              0x00008000
#define __CPUID_FEATURE_PCID__              0x00020000
#define __CPUID_FEATURE_DCA__               0x00040000
#define __CPUID_FEATURE_SSE4_1__            0x00080000
#define __CPUID_FEATURE_SSE4_2__            0x00100000
#define __CPUID_FEATURE_x2APIC__            0x00200000
#define __CPUID_FEATURE_MOVBE__             0x00400000
#define __CPUID_FEATURE_POPCNT__            0x00800000
#define __CPUID_FEATURE_TSC_DEADLINE__      0x01000000
#define __CPUID_FEATURE_AESNI__             0x02000000
#define __CPUID_FEATURE_XSAVE__             0x04000000
#define __CPUID_FEATURE_OSXSAVE__           0x08000000
#define __CPUID_FEATURE_AVX__               0x10000000
#define __CPUID_FEATURE_F16C__              0x20000000
#define __CPUID_FEATURE_RDRAND__            0x40000000

#define __CPUID_FEATURE_FPU__               0x00000001
#define __CPUID_FEATURE_VME__               0x00000002
#define __CPUID_FEATURE_DE__                0x00000004
#define __CPUID_FEATURE_PSE__               0x00000008
#define __CPUID_FEATURE_TSC__               0x00000010
#define __CPUID_FEATURE_MSR__               0x00000020
#define __CPUID_FEATURE_PAE__               0x00000040
#define __CPUID_FEATURE_MCE__               0x00000080
#define __CPUID_FEATURE_CX8__               0x00000100
#define __CPUID_FEATURE_APIC__              0x00000200
#define __CPUID_FEATURE_SEP__               0x00000800
#define __CPUID_FEATURE_MTRR__              0x00001000
#define __CPUID_FEATURE_PGE__               0x00002000
#define __CPUID_FEATURE_MCA__               0x00004000
#define __CPUID_FEATURE_CMOV__              0x00008000
#define __CPUID_FEATURE_PAT__               0x00010000
#define __CPUID_FEATURE_PSE_36__            0x00020000
#define __CPUID_FEATURE_PSN__               0x00040000
#define __CPUID_FEATURE_CLFSH__             0x00080000
#define __CPUID_FEATURE_DS__                0x00200000
#define __CPUID_FEATURE_ACPI__              0x00400000
#define __CPUID_FEATURE_MMX__               0x00800000
#define __CPUID_FEATURE_FXSR__              0x01000000
#define __CPUID_FEATURE_SSE__               0x02000000
#define __CPUID_FEATURE_SSE2__              0x04000000
#define __CPUID_FEATURE_SS__                0x08000000
#define __CPUID_FEATURE_HTT__               0x10000000
#define __CPUID_FEATURE_TM__                0x20000000
#define __CPUID_FEATURE_PBE__               0x80000000

#define __CPUID_FEATURE_SUPPORTED__(x, feature) \
    ((bool)(x & feature ? true : false))

#define __CPUID_BRAND_STRING_FREQUENCY_MULTIPLIER__(x) \
    ((x == "zHM") ? 1e6 : (x == "zHG") ? 1e9 : (x == "zHT") ? 1e12 : 0)

typedef struct __cpuinfo {
    uint8_t stepping_id;
    uint8_t model_id;
    uint8_t family_id;
    __processor_type_t type;
    uint8_t brand_index;
    char *brand_string;
    uint8_t clflush_line_size;
    uint8_t max_addressable_ids;
    uint8_t initial_apic_id;
    uint32_t supported_features;
    uint32_t supported_features_ext;
} __cpuinfo_t;

extern bool __cpuid_supported();
extern __cpuid_t __get_cpuid(const uint32_t);
extern __cpuinfo_t __get_cpuinfo();

#endif