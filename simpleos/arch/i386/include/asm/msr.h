/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_MSR_H__
#define __SIMPLEOS_MSR_H__

// IA-32 Architectural MSRs

// Register addresses
#define IA32_P5_MC_ADDR                 0x0000
#define IA32_P5_MC_TYPE                 0x0001
#define IA32_MONITOR_FILTER_SIZE        0x0006
#define IA32_TIME_STAMP_COUNTER         0x0010
#define IA32_PLATFORM_ID                0x0017
#define IA32_APIC_BASE                  0x001B
#define IA32_FEATURE_CONTROL            0x003A
#define IA32_TSC_ADJUST                 0x003B
#define IA32_BIOS_UPDT_TRIG             0x0079
#define IA32_BIOS_SIGN_ID               0x008B
#define IA32_SGXLEPUBKEYHASH0           0x008C
#define IA32_SGXLEPUBKEYHASH1           0x008D
#define IA32_SGXLEPUBKEYHASH2           0x008E
#define IA32_SGXLEPUBKEYHASH3           0x008F
#define IA32_SMM_MONITOR_CTL            0x009B
#define IA32_SMBASE                     0x009E
#define IA32_PMC0                       0x00C1
#define IA32_PMC1                       0x00C2
#define IA32_PMC2                       0x00C3
#define IA32_PMC3                       0x00C4
#define IA32_PMC4                       0x00C5
#define IA32_PMC5                       0x00C6
#define IA32_PMC6                       0x00C7
#define IA32_PMC7                       0x00C8
#define IA32_MPERF                      0x00E7
#define IA32_APERF                      0x00EB
#define IA32_MTRRCAP                    0x00FE
#define IA32_SYSENTER_CS                0x0174
#define IA32_SYSENTER_ESP               0x0175
#define IA32_SYSENTER_EIP               0x0176
#define IA32_MCG_CAP                    0x0179
#define IA32_MCG_STATUS                 0x017A
#define IA32_MCG_CTL                    0x017B
#define IA32_PERFEVTSEL0                0x0186
#define IA32_PERFEVTSEL1                0x0187
#define IA32_PERFEVTSEL2                0x0188
#define IA32_PERFEVTSEL3                0x0189
#define IA32_PERF_STATUS                0x0198
#define IA32_PERF_CTL                   0x0199
#define IA32_CLOCK_MODULATION           0x019A
#define IA32_THERM_INTERRUPT            0x019B
#define IA32_THERM_STATUS               0x019C
#define IA32_MISC_ENABLE                0x01A0
#define IA32_ENERGY_PERF_BIAS           0x01B0
#define IA32_PACKAGE_THERM_STATUS       0x01B1
#define IA32_PACKAGE_THERM_INTERRUPT    0x01B2
#define IA32_DEBUGCTL                   0x01D9
#define IA32_SMRR_PHYSBASE              0x01F2
#define IA32_SMRR_PHYSMASK              0x01F3
#define IA32_PLATFORM_DCA_CAP           0x01F8
#define IA32_CPU_DCA_CAP                0x01F9
#define IA32_DCA_0_CAP                  0x01FA
#define IA32_MTRR_PHYSBASE0             0x0200
#define IA32_MTRR_PHYSMASK0             0x0201
#define IA32_MTRR_PHYSBASE1             0x0202
#define IA32_MTRR_PHYSMASK1             0x0203
#define IA32_MTRR_PHYSBASE2             0x0204
#define IA32_MTRR_PHYSMASK2             0x0205
#define IA32_MTRR_PHYSBASE3             0x0206
#define IA32_MTRR_PHYSMASK3             0x0207
#define IA32_MTRR_PHYSBASE4             0x0208
#define IA32_MTRR_PHYSMASK4             0x0209
#define IA32_MTRR_PHYSBASE5             0x020A
#define IA32_MTRR_PHYSMASK5             0x020B
#define IA32_MTRR_PHYSBASE6             0x020C
#define IA32_MTRR_PHYSMASK6             0x020D
#define IA32_MTRR_PHYSBASE7             0x020E
#define IA32_MTRR_PHYSMASK7             0x020F
#define IA32_MTRR_PHYSBASE8             0x0210
#define IA32_MTRR_PHYSMASK8             0x0211
#define IA32_MTRR_PHYSBASE9             0x0212
#define IA32_MTRR_PHYSMASK9             0x0213
#define IA32_MTRR_FIX64K_00000          0x0250
#define IA32_MTRR_FIX16K_80000          0x0258
#define IA32_MTRR_FIX16K_A0000          0x0259
#define IA32_MTRR_FIX4K_C0000           0x0268
#define IA32_MTRR_FIX4K_C8000           0x0269
#define IA32_MTRR_FIX4K_D0000           0x026A
#define IA32_MTRR_FIX4K_D8000           0x026B
#define IA32_MTRR_FIX4K_E0000           0x026C
#define IA32_MTRR_FIX4K_E8000           0x026D
#define IA32_MTRR_FIX4K_F0000           0x026E
#define IA32_MTRR_FIX4K_F8000           0x026F
#define IA32_PAT                        0x0277
#define IA32_MC0_CTL2                   0x0280
#define IA32_MC1_CTL2                   0x0281
#define IA32_MC2_CTL2                   0x0282
#define IA32_MC3_CTL2                   0x0283
#define IA32_MC4_CTL2                   0x0284
#define IA32_MC5_CTL2                   0x0285
#define IA32_MC6_CTL2                   0x0286
#define IA32_MC7_CTL2                   0x0287
#define IA32_MC8_CTL2                   0x0288
#define IA32_MC9_CTL2                   0x0289
#define IA32_MC16_CTL2                  0x0290
#define IA32_MC17_CTL2                  0x0291
#define IA32_MC18_CTL2                  0x0292
#define IA32_MC19_CTL2                  0x0293
#define IA32_MC20_CTL2                  0x0294
#define IA32_MC21_CTL2                  0x0295
#define IA32_MC22_CTL2                  0x0296
#define IA32_MC23_CTL2                  0x0297
#define IA32_MC24_CTL2                  0x0298
#define IA32_MC25_CTL2                  0x0299
#define IA32_FIXED_CTR0                 0x0309
#define IA32_PERF_CAPABILITIES          0x0345
#define IA32_PERF_GLOBAL_OVF_CTRL       0x0390
#define IA32_PERF_GLOBAL_STATUS_RESET   0x0390
#define IA32_PERF_GLOBAL_STATUS_SET     0x0391
#define IA32_PERF_GLOBAL_INUSE          0x0392
#define IA32_MC0_CTL                    0x0400
#define IA32_MC0_STATUS                 0x0401
#define IA32_MC0_ADDR1                  0x0402
#define IA32_MC0_MISC                   0x0403
#define IA32_MC1_CTL                    0x0404
#define IA32_MC1_STATUS                 0x0405
#define IA32_MC1_ADDR2                  0x0406
#define IA32_MC1_MISC                   0x0407
#define IA32_MC2_CTL                    0x0408
#define IA32_MC2_STATUS                 0x0409
#define IA32_MC4_CTL                    0x0410
#define IA32_MC4_STATUS                 0x0411
#define IA32_MC4_ADDR1                  0x0412
#define IA32_MC4_MISC                   0x0413
#define IA32_MC5_CTL                    0x0414
#define IA32_MC5_STATUS                 0x0415
#define IA32_MC5_ADDR1                  0x0416
#define IA32_MC5_MISC                   0x0417
#define IA32_MC6_CTL                    0x0418
#define IA32_MC12_CTL                   0x0430
#define IA32_MC12_STATUS                0x0431
#define IA32_MC12_ADDR1                 0x0432
#define IA32_MC12_MISC                  0x0433
#define IA32_MC13_CTL                   0x0434
#define IA32_MC13_STATUS                0x0435
#define IA32_MC13_ADDR1                 0x0436
#define IA32_MC13_MISC                  0x0437
#define IA32_MC14_CTL                   0x0438
#define IA32_MC14_STATUS                0x0439
#define IA32_MC16_CTL                   0x0440
#define IA32_MC16_STATUS                0x0441
#define IA32_MC16_ADDR1                 0x0442
#define IA32_MC16_MISC                  0x0443
#define IA32_MC17_CTL                   0x0444
#define IA32_MC17_STATUS                0x0445
#define IA32_MC17_ADDR1                 0x0446
#define IA32_MC17_MISC                  0x0447
#define IA32_MC18_CTL                   0x0448
#define IA32_MC18_STATUS                0x0449
#define IA32_MC20_CTL                   0x0450
#define IA32_MC20_STATUS                0x0451
#define IA32_MC20_ADDR1                 0x0452
#define IA32_MC20_MISC                  0x0453
#define IA32_MC21_CTL                   0x0454
#define IA32_MC21_STATUS                0x0455
#define IA32_MC21_ADDR1                 0x0456
#define IA32_MC21_MISC                  0x0457
#define IA32_MC22_CTL                   0x0458
#define IA32_MC22_STATUS                0x0459
#define IA32_MC24_CTL                   0x0460
#define IA32_MC24_STATUS                0x0461
#define IA32_MC24_ADDR1                 0x0462
#define IA32_MC24_MISC                  0x0463
#define IA32_MC25_CTL                   0x0464
#define IA32_MC25_STATUS                0x0465
#define IA32_MC25_ADDR1                 0x0466
#define IA32_MC25_MISC                  0x0467
#define IA32_MC26_CTL                   0x0468
#define IA32_MC26_STATUS                0x0469
#define IA32_MC28_CTL                   0x0470
#define IA32_MC28_STATUS                0x0471
#define IA32_MC28_ADDR1                 0x0472
#define IA32_MC28_MISC                  0x0473
#define IA32_VMX_BASIC                  0x0480
#define IA32_VMX_PINBASED_CTLS          0x0481
#define IA32_VMX_PROCBASED_CTLS         0x0482
#define IA32_VMX_EXIT_CTLS              0x0483
#define IA32_VMX_ENTRY_CTLS             0x0484
#define IA32_VMX_MISC                   0x0485
#define IA32_VMX_CR0_FIXED0             0x0486
#define IA32_VMX_CR0_FIXED1             0x0487
#define IA32_VMX_CR4_FIXED0             0x0488
#define IA32_VMX_CR4_FIXED1             0x0489
#define IA32_VMX_TRUE_ENTRY_CTLS        0x0490
#define IA32_VMX_VMFUNC                 0x0491
#define IA32_SGX_SVN_STATUS             0x0500
#define IA32_RTIT_OUTPUT_BASE           0x0560
#define IA32_RTIT_OUTPUT_MASK_PTRS      0x0561
#define IA32_RTIT_CTL                   0x0570
#define IA32_RTIT_STATUS                0x0571
#define IA32_RTIT_CR3_MATCH             0x0572
#define IA32_RTIT_ADDR0_A               0x0580
#define IA32_RTIT_ADDR0_B               0x0581
#define IA32_RTIT_ADDR1_A               0x0582
#define IA32_RTIT_ADDR1_B               0x0583
#define IA32_RTIT_ADDR2_A               0x0584
#define IA32_RTIT_ADDR2_B               0x0585
#define IA32_RTIT_ADDR3_A               0x0586
#define IA32_RTIT_ADDR3_B               0x0587
#define IA32_DS_AREA                    0x0600
#define IA32_PM_ENABLE                  0x0770
#define IA32_HWP_CAPABILITIES           0x0771
#define IA32_HWP_INTERRUPT              0x0773
#define IA32_HWP_REQUEST                0x0774
#define IA32_HWP_STATUS                 0x0777
#define IA32_X2APIC_APICID              0x0802
#define IA32_X2APIC_VERSION             0x0803
#define IA32_X2APIC_TPR                 0x0808
#define IA32_X2APIC_ISR0                0x0810
#define IA32_X2APIC_ISR1                0x0811
#define IA32_X2APIC_ISR2                0x0812
#define IA32_X2APIC_ISR3                0x0813
#define IA32_X2APIC_ISR4                0x0814
#define IA32_X2APIC_ISR5                0x0815
#define IA32_X2APIC_ISR6                0x0816
#define IA32_X2APIC_ISR7                0x0817
#define IA32_X2APIC_TMR0                0x0818
#define IA32_X2APIC_TMR1                0x0819
#define IA32_X2APIC_IRR0                0x0820
#define IA32_X2APIC_IRR1                0x0821
#define IA32_X2APIC_IRR2                0x0822
#define IA32_X2APIC_IRR3                0x0823
#define IA32_X2APIC_IRR4                0x0824
#define IA32_X2APIC_IRR5                0x0825
#define IA32_X2APIC_IRR6                0x0826
#define IA32_X2APIC_IRR7                0x0827
#define IA32_X2APIC_ESR                 0x0828
#define IA32_X2APIC_ICR                 0x0830
#define IA32_X2APIC_LVT_TIMER           0x0832
#define IA32_X2APIC_LVT_THERMAL         0x0833
#define IA32_X2APIC_LVT_PMI             0x0834
#define IA32_X2APIC_LVT_LINT0           0x0835
#define IA32_X2APIC_LVT_LINT1           0x0836
#define IA32_X2APIC_LVT_ERROR           0x0837
#define IA32_X2APIC_INIT_COUNT          0x0838
#define IA32_X2APIC_CUR_COUNT           0x0839


// Register values

/**
 * Lock bit (R/WO): (1 = locked). When set, locks this MSR from being written;
 * writes to this bit will result in GP(0).
 *
 * Note: Once the Lock bit is set, the contents of this register cannot be
 * modified. Therefore the lock bit must be set after configuring support for
 * Intel Virtualization Technology and prior to transferring control to an
 * option ROM or the OS. Hence, once the Lock bit is set, the entire
 * IA32_FEATURE_CONTROL contents are preserved across RESET when PWRGOOD is not
 * deasserted.
 */
#define IA32_FEATURE_CONTROL_LOCKBIT            0x0000
/**
 * Enable VMX inside SMX operation (R/WL): This bit enables a system executive
 * to use VMX in conjunction with SMX to support Intel® Trusted Execution
 * Technology. BIOS must set this bit only when the CPUID function 1 returns VMX
 * feature flag and SMX feature flag set (ECX bits 5 and 6 respectively).
 */
#define IA32_FEATURE_CONTROL_VMX_INSIDE_SMX     0x0001
/**
 * Enable VMX outside SMX operation (R/WL): This bit enables VMX for a system
 * executive that does not require SMX. BIOS must set this bit only when the
 * CPUID function 1 returns the VMX feature flag set (ECX bit 5).
 */
#define IA32_FEATURE_CONTROL_VMX_OUTSIDE_SMX    0x0002
//      IA32_FEATURE_CONTROL_RESERVED           0x00F8

#endif  // __SIMPLEOS_MSR_H__
