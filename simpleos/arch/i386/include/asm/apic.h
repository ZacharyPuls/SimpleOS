/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_APIC_H__
#define __SIMPLEOS_APIC_H__

//      APIC_RESERVED_REGISTER                              0x0000
//      APIC_RESERVED_REGISTER                              0x0010
#define APIC_ID_REGISTER                                    0x0020
#define APIC_VERSION_REGISTER                               0x0030
//      APIC_RESERVED_REGISTER                              0x0040
//      APIC_RESERVED_REGISTER                              0x0050
//      APIC_RESERVED_REGISTER                              0x0060
//      APIC_RESERVED_REGISTER                              0x0070
#define APIC_TASK_PRIORITY_REGISTER                         0x0080
#define APIC_ARBITRATION_PRIORITY_REGISTER                  0x0090
#define APIC_PROCESSOR_PRIORITY_REGISTER                    0x00A0
#define APIC_EOI_REGISTER                                   0x00B0
#define APIC_REMOTE_READ_REGISTER                           0x00C0
#define APIC_LOGICAL_DESTINATION_REGISTER                   0x00D0
#define APIC_DESTINATION_FORMAT_REGISTER                    0x00E0
#define APIC_SPURIOUS_INTERRUPT_VECTOR_REGISTER             0x00F0
#define APIC_IN_SERVICE_REGISTER_A                          0x0100
#define APIC_IN_SERVICE_REGISTER_B                          0x0110
#define APIC_IN_SERVICE_REGISTER_C                          0x0120
#define APIC_IN_SERVICE_REGISTER_D                          0x0130
#define APIC_IN_SERVICE_REGISTER_E                          0x0140
#define APIC_IN_SERVICE_REGISTER_F                          0x0150
#define APIC_IN_SERVICE_REGISTER_G                          0x0160
#define APIC_IN_SERVICE_REGISTER_H                          0x0170
#define APIC_TRIGGER_MODE_REGISTER_A                        0x0180
#define APIC_TRIGGER_MODE_REGISTER_B                        0x0190
#define APIC_TRIGGER_MODE_REGISTER_C                        0x01A0
#define APIC_TRIGGER_MODE_REGISTER_D                        0x01B0
#define APIC_TRIGGER_MODE_REGISTER_E                        0x01C0
#define APIC_TRIGGER_MODE_REGISTER_F                        0x01D0
#define APIC_TRIGGER_MODE_REGISTER_G                        0x01E0
#define APIC_TRIGGER_MODE_REGISTER_H                        0x01F0
#define APIC_INTERRUPT_REQUEST_REGISTER_A                   0x0200
#define APIC_INTERRUPT_REQUEST_REGISTER_B                   0x0210
#define APIC_INTERRUPT_REQUEST_REGISTER_C                   0x0220
#define APIC_INTERRUPT_REQUEST_REGISTER_D                   0x0230
#define APIC_INTERRUPT_REQUEST_REGISTER_E                   0x0240
#define APIC_INTERRUPT_REQUEST_REGISTER_F                   0x0250
#define APIC_INTERRUPT_REQUEST_REGISTER_G                   0x0260
#define APIC_INTERRUPT_REQUEST_REGISTER_H                   0x0270
#define APIC_ERROR_STATUS_REGISTER                          0x0280
//      APIC_RESERVED_REGISTER                              0x0290
//      APIC_RESERVED_REGISTER                              0x02A0
//      APIC_RESERVED_REGISTER                              0x02B0
//      APIC_RESERVED_REGISTER                              0x02C0
//      APIC_RESERVED_REGISTER                              0x02D0
//      APIC_RESERVED_REGISTER                              0x02E0
#define APIC_LVT_CORRECTED_MACHINE_CHECK_REGISTER           0x02F0
#define APIC_INTERRUPT_COMMAND_REGISTER_A                   0x0300
#define APIC_INTERRUPT_COMMAND_REGISTER_B                   0x0310
#define APIC_LVT_TIMER_REGISTER                             0x0320
#define APIC_LVT_THERMAL_SENSOR_REGISTER                    0x0330
#define APIC_LVT_PERFORMANCE_MONITORING_COUNTERS_REGISTER   0x0340
#define APIC_LVT_LINT0_REGISTER                             0x0350
#define APIC_LVT_LINT1_REGISTER                             0x0360
#define APIC_LVT_ERROR_REGISTER                             0x0370
#define APIC_TIMER_INITIAL_COUNT_REGISTER                   0x0380
#define APIC_TIMER_CURRENT_COUNT_REGISTER                   0x0390
//      APIC_RESERVED_REGISTER                              0x03A0
//      APIC_RESERVED_REGISTER                              0x03B0
//      APIC_RESERVED_REGISTER                              0x03C0
//      APIC_RESERVED_REGISTER                              0x03D0
#define APIC_TIMER_DIVIDE_CONFIGURATION_REGISTER            0x03E0
//      APIC_RESERVED_REGISTER                              0x03F0

#endif  // __SIMPLEOS_APIC_H__
