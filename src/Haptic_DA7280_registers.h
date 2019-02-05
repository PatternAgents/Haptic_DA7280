/*
 * Haptic_DA7280_registers.h - Haptics REGISTERS for DA7280
 * Copyright (c) 2017 Dialog Semiconductor.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __HAPTIC_DA7280_REGISTERS_H
#define __HAPTIC_DA7280_REGISTERS_H

#define DA7280_I2C_ADDR			0x4A    // Seven Bit address = (0x94 >> 1)

#define DA7280_VOLT_RATE_MAX	6000
#define DA7280_VOLT_STEP_uV		23400
#define DA7280_NOM_VOLT_DFT		0x6B

#define DA7280_IMAX_STEP		7200

#define DA7280_MIN_RESONAT_FREQ	50
#define DA7280_MAX_RESONAT_FREQ	300

#define DA7280_MIN_PWM_FREQ_kHz	10000
#define DA7280_MAX_PWM_FREQ_kHz	250000

#define DA7280_IMPD_MAX			50000   // Impedance Range, milliOhm unit
#define DA7280_IMPD_MIN			4000
#define DA7280_IMAX_LIMIT		252

#define DA7280_SNP_MEM_SIZE		100
#define DA7280_SNP_MEM_MAX		DA7280_SNP_MEM_99
#define DA7280_DELAY			0xFE	// generic delay term

#define DA7280_CHIP_REV                       0x00
#define DA7280_IRQ_EVENT1                     0x03
#define DA7280_IRQ_EVENT_WARNING_DIAG         0x04
#define DA7280_IRQ_EVENT_PAT_DIAG             0x05
#define DA7280_IRQ_STATUS1                    0x06
#define DA7280_IRQ_MASK1                      0x07
#define DA7280_CIF_I2C1                       0x08
#define DA7280_FRQ_LRA_PER_H                  0x0A
#define DA7280_FRQ_LRA_PER_L                  0x0B
#define DA7280_ACTUATOR1                      0x0C
#define DA7280_ACTUATOR2                      0x0D
#define DA7280_ACTUATOR3                      0x0E
#define DA7280_CALIB_V2I_H                    0x0F
#define DA7280_CALIB_V2I_L                    0x10
#define DA7280_CALIB_IMP_H                    0x11
#define DA7280_CALIB_IMP_L                    0x12
#define DA7280_TOP_CFG1                       0x13
#define DA7280_TOP_CFG2                       0x14
#define DA7280_TOP_CFG3                       0x15
#define DA7280_TOP_CFG4                       0x16
#define DA7280_TOP_INT_CFG1                   0x17
#define DA7280_TOP_INT_CFG6_H                 0x1C
#define DA7280_TOP_INT_CFG6_L                 0x1D
#define DA7280_TOP_INT_CFG7_H                 0x1E
#define DA7280_TOP_INT_CFG7_L                 0x1F
#define DA7280_TOP_INT_CFG8                   0x20
#define DA7280_TOP_CTL1                       0x22
#define DA7280_TOP_CTL2                       0x23
#define DA7280_SEQ_CTL1                       0x24
#define DA7280_SWG_C1                         0x25
#define DA7280_SWG_C2                         0x26
#define DA7280_SWG_C3                         0x27
#define DA7280_SEQ_CTL2                       0x28
#define DA7280_GPI_0_CTL                      0x29
#define DA7280_GPI_1_CTL                      0x2A
#define DA7280_GPI_2_CTL                      0x2B
#define DA7280_MEM_CTL1                       0x2C
#define DA7280_MEM_CTL2                       0x2D
#define DA7280_ADC_DATA_H1                    0x2E
#define DA7280_ADC_DATA_L1                    0x2F
#define DA7280_POLARITY                       0x43
#define DA7280_LRA_AVR_H                      0x44
#define DA7280_LRA_AVR_L                      0x45
#define DA7280_FRQ_LRA_PER_ACT_H              0x46
#define DA7280_FRQ_LRA_PER_ACT_L              0x47
#define DA7280_FRQ_PHASE_H                    0x48
#define DA7280_FRQ_PHASE_L                    0x49
#define DA7280_FRQ_CTL                        0x4C
#define DA7280_TRIM3                          0x5F
#define DA7280_TRIM4                          0x60
#define DA7280_TRIM6                          0x62
#define DA7280_IRQ_EVENT_ACTUATOR_FAULT       0x81
#define DA7280_IRQ_STATUS2                    0x82
#define DA7280_IRQ_MASK2                      0x83
#define DA7280_SNP_MEM_0                      0x84
#define DA7280_SNP_MEM_1                      0x85
#define DA7280_SNP_MEM_2                      0x86
#define DA7280_SNP_MEM_3                      0x87
#define DA7280_SNP_MEM_4                      0x88
#define DA7280_SNP_MEM_5                      0x89
#define DA7280_SNP_MEM_6                      0x8A
#define DA7280_SNP_MEM_7                      0x8B
#define DA7280_SNP_MEM_8                      0x8C
#define DA7280_SNP_MEM_9                      0x8D
#define DA7280_SNP_MEM_10                     0x8E
#define DA7280_SNP_MEM_11                     0x8F
#define DA7280_SNP_MEM_12                     0x90
#define DA7280_SNP_MEM_13                     0x91
#define DA7280_SNP_MEM_14                     0x92
#define DA7280_SNP_MEM_15                     0x93
#define DA7280_SNP_MEM_16                     0x94
#define DA7280_SNP_MEM_17                     0x95
#define DA7280_SNP_MEM_18                     0x96
#define DA7280_SNP_MEM_19                     0x97
#define DA7280_SNP_MEM_20                     0x98
#define DA7280_SNP_MEM_21                     0x99
#define DA7280_SNP_MEM_22                     0x9A
#define DA7280_SNP_MEM_23                     0x9B
#define DA7280_SNP_MEM_24                     0x9C
#define DA7280_SNP_MEM_25                     0x9D
#define DA7280_SNP_MEM_26                     0x9E
#define DA7280_SNP_MEM_27                     0x9F
#define DA7280_SNP_MEM_28                     0xA0
#define DA7280_SNP_MEM_29                     0xA1
#define DA7280_SNP_MEM_30                     0xA2
#define DA7280_SNP_MEM_31                     0xA3
#define DA7280_SNP_MEM_32                     0xA4
#define DA7280_SNP_MEM_33                     0xA5
#define DA7280_SNP_MEM_34                     0xA6
#define DA7280_SNP_MEM_35                     0xA7
#define DA7280_SNP_MEM_36                     0xA8
#define DA7280_SNP_MEM_37                     0xA9
#define DA7280_SNP_MEM_38                     0xAA
#define DA7280_SNP_MEM_39                     0xAB
#define DA7280_SNP_MEM_40                     0xAC
#define DA7280_SNP_MEM_41                     0xAD
#define DA7280_SNP_MEM_42                     0xAE
#define DA7280_SNP_MEM_43                     0xAF
#define DA7280_SNP_MEM_44                     0xB0
#define DA7280_SNP_MEM_45                     0xB1
#define DA7280_SNP_MEM_46                     0xB2
#define DA7280_SNP_MEM_47                     0xB3
#define DA7280_SNP_MEM_48                     0xB4
#define DA7280_SNP_MEM_49                     0xB5
#define DA7280_SNP_MEM_50                     0xB6
#define DA7280_SNP_MEM_51                     0xB7
#define DA7280_SNP_MEM_52                     0xB8
#define DA7280_SNP_MEM_53                     0xB9
#define DA7280_SNP_MEM_54                     0xBA
#define DA7280_SNP_MEM_55                     0xBB
#define DA7280_SNP_MEM_56                     0xBC
#define DA7280_SNP_MEM_57                     0xBD
#define DA7280_SNP_MEM_58                     0xBE
#define DA7280_SNP_MEM_59                     0xBF
#define DA7280_SNP_MEM_60                     0xC0
#define DA7280_SNP_MEM_61                     0xC1
#define DA7280_SNP_MEM_62                     0xC2
#define DA7280_SNP_MEM_63                     0xC3
#define DA7280_SNP_MEM_64                     0xC4
#define DA7280_SNP_MEM_65                     0xC5
#define DA7280_SNP_MEM_66                     0xC6
#define DA7280_SNP_MEM_67                     0xC7
#define DA7280_SNP_MEM_68                     0xC8
#define DA7280_SNP_MEM_69                     0xC9
#define DA7280_SNP_MEM_70                     0xCA
#define DA7280_SNP_MEM_71                     0xCB
#define DA7280_SNP_MEM_72                     0xCC
#define DA7280_SNP_MEM_73                     0xCD
#define DA7280_SNP_MEM_74                     0xCE
#define DA7280_SNP_MEM_75                     0xCF
#define DA7280_SNP_MEM_76                     0xD0
#define DA7280_SNP_MEM_77                     0xD1
#define DA7280_SNP_MEM_78                     0xD2
#define DA7280_SNP_MEM_79                     0xD3
#define DA7280_SNP_MEM_80                     0xD4
#define DA7280_SNP_MEM_81                     0xD5
#define DA7280_SNP_MEM_82                     0xD6
#define DA7280_SNP_MEM_83                     0xD7
#define DA7280_SNP_MEM_84                     0xD8
#define DA7280_SNP_MEM_85                     0xD9
#define DA7280_SNP_MEM_86                     0xDA
#define DA7280_SNP_MEM_87                     0xDB
#define DA7280_SNP_MEM_88                     0xDC
#define DA7280_SNP_MEM_89                     0xDD
#define DA7280_SNP_MEM_90                     0xDE
#define DA7280_SNP_MEM_91                     0xDF
#define DA7280_SNP_MEM_92                     0xE0
#define DA7280_SNP_MEM_93                     0xE1
#define DA7280_SNP_MEM_94                     0xE2
#define DA7280_SNP_MEM_95                     0xE3
#define DA7280_SNP_MEM_96                     0xE4
#define DA7280_SNP_MEM_97                     0xE5
#define DA7280_SNP_MEM_98                     0xE6
#define DA7280_SNP_MEM_99                     0xE7

/* DA7280_CHIP_REV (Address 0x0000) */
#define DA7280_CHIP_REV_MAJOR_SHIFT                           0
#define DA7280_CHIP_REV_MAJOR_MASK                            (15 << 0)
#define DA7280_CHIP_REV_MINOR_SHIFT                           4
#define DA7280_CHIP_REV_MINOR_MASK                            (15 << 4)

/* DA7280_IRQ_EVENT1 (Address 0x0003) */
#define DA7280_E_SEQ_CONTINUE_SHIFT                         0
#define DA7280_E_SEQ_CONTINUE_MASK                          (1 << 0)
#define DA7280_E_UVLO_VBAT_OK_SHIFT                         1
#define DA7280_E_UVLO_VBAT_OK_MASK                          (1 << 1)
#define DA7280_E_PAT_DONE_SHIFT                             2
#define DA7280_E_PAT_DONE_MASK                              (1 << 2)
#define DA7280_E_OVERTEMP_CRIT_SHIFT                        3
#define DA7280_E_OVERTEMP_CRIT_MASK                         (1 << 3)
#define DA7280_E_PAT_FAULT_SHIFT                            4
#define DA7280_E_PAT_FAULT_MASK                             (1 << 4)
#define DA7280_E_WARNING_SHIFT                              5
#define DA7280_E_WARNING_MASK                               (1 << 5)
#define DA7280_E_ACTUATOR_FAULT_SHIFT                       6
#define DA7280_E_ACTUATOR_FAULT_MASK                        (1 << 6)
#define DA7280_E_OC_FAULT_SHIFT                             7
#define DA7280_E_OC_FAULT_MASK                              (1 << 7)

/* DA7280_IRQ_EVENT_WARNING_DIAG (Address 0x0004) */
#define DA7280_E_OVERTEMP_WARN_SHIFT            3
#define DA7280_E_OVERTEMP_WARN_MASK             (1 << 3)
#define DA7280_E_MEM_TYPE_SHIFT                 4
#define DA7280_E_MEM_TYPE_MASK                  (1 << 4)
#define DA7280_E_LIM_DRIVE_ACC_SHIFT            6
#define DA7280_E_LIM_DRIVE_ACC_MASK             (1 << 6)
#define DA7280_E_LIM_DRIVE_SHIFT                7
#define DA7280_E_LIM_DRIVE_MASK                 (1 << 7)

/* DA7280_IRQ_EVENT_PAT_DIAG (Address 0x0005) */
#define DA7280_E_PWM_FAULT_SHIFT                    5
#define DA7280_E_PWM_FAULT_MASK                     (1 << 5)
#define DA7280_E_MEM_FAULT_SHIFT                    6
#define DA7280_E_MEM_FAULT_MASK                     (1 << 6)
#define DA7280_E_SEQ_ID_FAULT_SHIFT                 7
#define DA7280_E_SEQ_ID_FAULT_MASK                  (1 << 7)

/* DA7280_IRQ_STATUS1 (Address 0x0006) */
#define DA7280_STA_SEQ_CONTINUE_SHIFT                      0
#define DA7280_STA_SEQ_CONTINUE_MASK                       (1 << 0)
#define DA7280_STA_UVLO_VBAT_OK_SHIFT                      1
#define DA7280_STA_UVLO_VBAT_OK_MASK                       (1 << 1)
#define DA7280_STA_PAT_DONE_SHIFT                          2
#define DA7280_STA_PAT_DONE_MASK                           (1 << 2)
#define DA7280_STA_OVERTEMP_CRIT_SHIFT                     3
#define DA7280_STA_OVERTEMP_CRIT_MASK                      (1 << 3)
#define DA7280_STA_PAT_FAULT_SHIFT                         4
#define DA7280_STA_PAT_FAULT_MASK                          (1 << 4)
#define DA7280_STA_WARNING_SHIFT                           5
#define DA7280_STA_WARNING_MASK                            (1 << 5)
#define DA7280_STA_ACTUATOR_SHIFT                          6
#define DA7280_STA_ACTUATOR_MASK                           (1 << 6)
#define DA7280_STA_OC_SHIFT                                7
#define DA7280_STA_OC_MASK                                 (1 << 7)

/* DA7280_IRQ_MASK1 (Address 0x0007) */
#define DA7280_SEQ_CONTINUE_M_SHIFT                          0
#define DA7280_SEQ_CONTINUE_M_MASK                           (1 << 0)
#define DA7280_UVLO_VBAT_OK_M_SHIFT                          1
#define DA7280_UVLO_VBAT_OK_M_MASK                           (1 << 1)
#define DA7280_PAT_DONE_M_SHIFT                              2
#define DA7280_PAT_DONE_M_MASK                               (1 << 2)
#define DA7280_OVERTEMP_CRIT_M_SHIFT                         3
#define DA7280_OVERTEMP_CRIT_M_MASK                          (1 << 3)
#define DA7280_PAT_FAULT_M_SHIFT                             4
#define DA7280_PAT_FAULT_M_MASK                              (1 << 4)
#define DA7280_WARNING_M_SHIFT                               5
#define DA7280_WARNING_M_MASK                                (1 << 5)
#define DA7280_ACTUATOR_M_SHIFT                              6
#define DA7280_ACTUATOR_M_MASK                               (1 << 6)
#define DA7280_OC_M_SHIFT                                    7
#define DA7280_OC_M_MASK                                     (1 << 7)

/* DA7280_CIF_I2C1 (Address 0x0008) */
#define DA7280_I2C_TO_ENABLE_SHIFT                            6
#define DA7280_I2C_TO_ENABLE_MASK                             (1 << 6)
#define DA7280_I2C_WR_MODE_SHIFT                              7
#define DA7280_I2C_WR_MODE_MASK                               (1 << 7)

/* DA7280_FRQ_LRA_PER_H (Address 0x000a) */
#define DA7280_LRA_PER_H_SHIFT                           0
#define DA7280_LRA_PER_H_MASK                            (255 << 0)

/* DA7280_FRQ_LRA_PER_L (Address 0x000b) */
#define DA7280_LRA_PER_L_SHIFT                           0
#define DA7280_LRA_PER_L_MASK                            (127 << 0)

/* DA7280_ACTUATOR1 (Address 0x000c) */
#define DA7280_ACTUATOR_NOMMAX_SHIFT                         0
#define DA7280_ACTUATOR_NOMMAX_MASK                          (255 << 0)

/* DA7280_ACTUATOR2 (Address 0x000d) */
#define DA7280_ACTUATOR_ABSMAX_SHIFT                         0
#define DA7280_ACTUATOR_ABSMAX_MASK                          (255 << 0)

/* DA7280_ACTUATOR3 (Address 0x000e) */
#define DA7280_IMAX_SHIFT                                    0
#define DA7280_IMAX_MASK                                     (31 << 0)

/* DA7280_CALIB_V2I_H (Address 0x000f) */
#define DA7280_V2I_FACTOR_H_SHIFT                          0
#define DA7280_V2I_FACTOR_H_MASK                           (255 << 0)

/* DA7280_CALIB_V2I_L (Address 0x0010) */
#define DA7280_V2I_FACTOR_L_SHIFT                          0
#define DA7280_V2I_FACTOR_L_MASK                           (255 << 0)

/* DA7280_CALIB_IMP_H (Address 0x0011) */
#define DA7280_IMPEDANCE_H_SHIFT                           0
#define DA7280_IMPEDANCE_H_MASK                            (255 << 0)

/* DA7280_CALIB_IMP_L (Address 0x0012) */
#define DA7280_IMPEDANCE_L_SHIFT                           0
#define DA7280_IMPEDANCE_L_MASK                            (3 << 0)

/* DA7280_TOP_CFG1 (Address 0x0013) */
#define DA7280_AMP_PID_EN_SHIFT                               0
#define DA7280_AMP_PID_EN_MASK                                (1 << 0)
#define DA7280_RAPID_STOP_EN_SHIFT                            1
#define DA7280_RAPID_STOP_EN_MASK                             (1 << 1)
#define DA7280_ACCELERATION_EN_SHIFT                          2
#define DA7280_ACCELERATION_EN_MASK                           (1 << 2)
#define DA7280_FREQ_TRACK_EN_SHIFT                            3
#define DA7280_FREQ_TRACK_EN_MASK                             (1 << 3)
#define DA7280_BEMF_SENSE_EN_SHIFT                           4
#define DA7280_BEMF_SENSE_EN_MASK                            (1 << 4)
#define DA7280_ACTUATOR_TYPE_SHIFT                            5
#define DA7280_ACTUATOR_TYPE_MASK                             (1 << 5)
#define DA7280_EMBEDDED_MODE_SHIFT                            7
#define DA7280_EMBEDDED_MODE_MASK                             (1 << 7)

/* DA7280_TOP_CFG2 (Address 0x0014) */
#define DA7280_FULL_BRAKE_THR_SHIFT                           0
#define DA7280_FULL_BRAKE_THR_MASK                            (15 << 0)
#define DA7280_MEM_DATA_SIGNED_SHIFT                          4
#define DA7280_MEM_DATA_SIGNED_MASK                           (1 << 4)

/* DA7280_TOP_CFG3 (Address 0x0015) */
#define DA7280_VBAT_MARGIN_SHIFT                              0
#define DA7280_VBAT_MARGIN_MASK                               (15 << 0)

/* DA7280_TOP_CFG4 (Address 0x0016) */
#define DA7280_TST_CALIB_IMPEDANCE_DIS_SHIFT                  6
#define DA7280_TST_CALIB_IMPEDANCE_DIS_MASK                   (1 << 6)
#define DA7280_V2I_FACTOR_FREEZE_SHIFT                        7
#define DA7280_V2I_FACTOR_FREEZE_MASK                         (1 << 7)

/* DA7280_TOP_INT_CFG1 (Address 0x0017) */
#define DA7280_BEMF_FAULT_LIM_SHIFT                       0
#define DA7280_BEMF_FAULT_LIM_MASK                        (3 << 0)
#define DA7280_FRQ_LOCKED_LIM_SHIFT                       2
#define DA7280_FRQ_LOCKED_LIM_MASK                        (63 << 2)

/* DA7280_TOP_INT_CFG6_H (Address 0x001c) */
#define DA7280_FRQ_PID_KP_H_SHIFT                       0
#define DA7280_FRQ_PID_KP_H_MASK                        (255 << 0)

/* DA7280_TOP_INT_CFG6_L (Address 0x001d) */
#define DA7280_FRQ_PID_KP_L_SHIFT                       0
#define DA7280_FRQ_PID_KP_L_MASK                        (255 << 0)

/* DA7280_TOP_INT_CFG7_H (Address 0x001e) */
#define DA7280_FRQ_PID_KI_H_SHIFT                       0
#define DA7280_FRQ_PID_KI_H_MASK                        (255 << 0)

/* DA7280_TOP_INT_CFG7_L (Address 0x001f) */
#define DA7280_FRQ_PID_KI_L_SHIFT                       0
#define DA7280_FRQ_PID_KI_L_MASK                        (255 << 0)

/* DA7280_TOP_INT_CFG8 (Address 0x0020) */
#define DA7280_TST_FRQ_TRACK_BEMF_LIM_SHIFT               0
#define DA7280_TST_FRQ_TRACK_BEMF_LIM_MASK                (15 << 0)
#define DA7280_TST_AMP_RAPID_STOP_LIM_SHIFT               4
#define DA7280_TST_AMP_RAPID_STOP_LIM_MASK                (7 << 4)

/* DA7280_TOP_CTL1 (Address 0x0022) */
#define DA7280_OPERATION_MODE_SHIFT                           0
#define DA7280_OPERATION_MODE_MASK                            (7 << 0)
#define DA7280_STANDBY_EN_SHIFT                    3
#define DA7280_STANDBY_EN_MASK                     (1 << 3)
#define DA7280_SEQ_START_SHIFT                                4
#define DA7280_SEQ_START_MASK                                 (1 << 4)

/* DA7280_TOP_CTL2 (Address 0x0023) */
#define DA7280_OVERRIDE_VAL_SHIFT                             0
#define DA7280_OVERRIDE_VAL_MASK                              (255 << 0)

/* DA7280_SEQ_CTL1 (Address 0x0024) */
#define DA7280_SEQ_CONTINUE_SHIFT                             0
#define DA7280_SEQ_CONTINUE_MASK                              (1 << 0)
#define DA7280_WAVEGEN_MODE_SHIFT                             1
#define DA7280_WAVEGEN_MODE_MASK                              (1 << 1)
#define DA7280_FREQ_WAVEFORM_TIMEBASE_SHIFT                   2
#define DA7280_FREQ_WAVEFORM_TIMEBASE_MASK                    (1 << 2)

/* DA7280_SWG_C1 (Address 0x0025) */
#define DA7280_CUSTOM_WAVE_GEN_COEFF1_SHIFT                     0
#define DA7280_CUSTOM_WAVE_GEN_COEFF1_MASK                      (255 << 0)

/* DA7280_SWG_C2 (Address 0x0026) */
#define DA7280_CUSTOM_WAVE_GEN_COEFF2_SHIFT                     0
#define DA7280_CUSTOM_WAVE_GEN_COEFF2_MASK                      (255 << 0)

/* DA7280_SWG_C3 (Address 0x0027) */
#define DA7280_CUSTOM_WAVE_GEN_COEFF3_SHIFT                     0
#define DA7280_CUSTOM_WAVE_GEN_COEFF3_MASK                      (255 << 0)

/* DA7280_SEQ_CTL2 (Address 0x0028) */
#define DA7280_PS_SEQ_ID_SHIFT                                0
#define DA7280_PS_SEQ_ID_MASK                                 (15 << 0)
#define DA7280_PS_SEQ_LOOP_SHIFT                              4
#define DA7280_PS_SEQ_LOOP_MASK                               (15 << 4)

/* DA7280_GPIO_0_CTL (Address 0x0029) */
#define DA7280_GPI0_POLARITY_SHIFT                         0
#define DA7280_GPI0_POLARITY_MASK                          (3 << 0)
#define DA7280_GPI0_MODE_SHIFT                             2
#define DA7280_GPI0_MODE_MASK                              (1 << 2)
#define DA7280_GPI0_SEQUENCE_ID_SHIFT                      3
#define DA7280_GPI0_SEQUENCE_ID_MASK                       (15 << 3)

/* DA7280_GPIO_1_CTL (Address 0x002a) */
#define DA7280_GPI1_POLARITY_SHIFT                         0
#define DA7280_GPI1_POLARITY_MASK                          (3 << 0)
#define DA7280_GPI1_MODE_SHIFT                             2
#define DA7280_GPI1_MODE_MASK                              (1 << 2)
#define DA7280_GPI1_SEQUENCE_ID_SHIFT                      3
#define DA7280_GPI1_SEQUENCE_ID_MASK                       (15 << 3)

/* DA7280_GPIO_2_CTL (Address 0x002b) */
#define DA7280_GPI2_POLARITY_SHIFT                         0
#define DA7280_GPI2_POLARITY_MASK                          (3 << 0)
#define DA7280_GPI2_MODE_SHIFT                             2
#define DA7280_GPI2_MODE_MASK                              (1 << 2)
#define DA7280_GPI2_SEQUENCE_ID_SHIFT                      3
#define DA7280_GPI2_SEQUENCE_ID_MASK                       (15 << 3)

/* DA7280_MEM_CTL1 (Address 0x002c) */
#define DA7280_PATTERN_BASE_ADDR_SHIFT                        0
#define DA7280_PATTERN_BASE_ADDR_MASK                         (255 << 0)

/* DA7280_MEM_CTL2 (Address 0x002d) */
#define DA7280_PATTERN_MEM_LOCK_SHIFT                         7
#define DA7280_PATTERN_MEM_LOCK_MASK                          (1 << 7)

/* DA7280_ADC_DATA_H1 (Address 0x002e) */
#define DA7280_ADC_VBAT_H_SHIFT                            0
#define DA7280_ADC_VBAT_H_MASK                             (255 << 0)

/* DA7280_ADC_DATA_L1 (Address 0x002f) */
#define DA7280_ADC_VBAT_L_SHIFT                            0
#define DA7280_ADC_VBAT_L_MASK                             (127 << 0)

/* DA7280_POLARITY (Address 0x0043) */
#define DA7280_POLARITY_SHIFT                                 0
#define DA7280_POLARITY_MASK                                  (1 << 0)

/* DA7280_LRA_AVR_H (Address 0x0044) */
#define DA7280_LRA_PER_AVERAGE_H_SHIFT                       0
#define DA7280_LRA_PER_AVERAGE_H_MASK                        (255 << 0)

/* DA7280_LRA_AVR_L (Address 0x0045) */
#define DA7280_LRA_PER_AVERAGE_L_SHIFT                       0
#define DA7280_LRA_PER_AVERAGE_L_MASK                        (127 << 0)

/* DA7280_FRQ_LRA_PER_ACT_H (Address 0x0046) */
#define DA7280_LRA_PER_ACTUAL_H_SHIFT                0
#define DA7280_LRA_PER_ACTUAL_H_MASK                 (255 << 0)

/* DA7280_FRQ_LRA_PER_ACT_L (Address 0x0047) */
#define DA7280_LRA_PER_ACTUAL_L_SHIFT                0
#define DA7280_LRA_PER_ACTUAL_L_MASK                 (127 << 0)

/* DA7280_FRQ_PHASE_H (Address 0x0048) */
#define DA7280_PHASE_SHIFT_H_SHIFT                         0
#define DA7280_PHASE_SHIFT_H_MASK                          (255 << 0)

/* DA7280_FRQ_PHASE_L (Address 0x0049) */
#define DA7280_PHASE_SHIFT_L_SHIFT                         0
#define DA7280_PHASE_SHIFT_L_MASK                          (7 << 0)
#define DA7280_PHASE_SHIFT_FREEZE_SHIFT                    7
#define DA7280_PHASE_SHIFT_FREEZE_MASK                     (1 << 7)

/* DA7280_FRQ_CTL (Address 0x004c) */
#define DA7280_FREQ_TRACKING_FORCE_ON_SHIFT                    0
#define DA7280_FREQ_TRACKING_FORCE_ON_MASK                     (1 << 0)
#define DA7280_FREQ_TRACKING_AUTO_ADJ_SHIFT                    1
#define DA7280_FREQ_TRACKING_AUTO_ADJ_MASK                     (1 << 1)

/* DA7280_TRIM3 (Address 0x005f) */
#define DA7280_REF_UVLO_THRES_SHIFT                              3
#define DA7280_REF_UVLO_THRES_MASK                               (3 << 3)
#define DA7280_LOOP_FILT_LOW_BW_SHIFT                            5
#define DA7280_LOOP_FILT_LOW_BW_MASK                             (1 << 5)
#define DA7280_LOOP_IDAC_DOUBLE_RANGE_SHIFT                      6
#define DA7280_LOOP_IDAC_DOUBLE_RANGE_MASK                       (1 << 6)

/* DA7280_TRIM4 (Address 0x0060) */
#define DA7280_LOOP_FILT_RES_TRIM_SHIFT                          0
#define DA7280_LOOP_FILT_RES_TRIM_MASK                           (3 << 0)
#define DA7280_LOOP_FILT_CAP_TRIM_SHIFT                          2
#define DA7280_LOOP_FILT_CAP_TRIM_MASK                           (3 << 2)

/* DA7280_TRIM6 (Address 0x0062) */
#define DA7280_HBRIDGE_ERC_HS_TRIM_SHIFT                         0
#define DA7280_HBRIDGE_ERC_HS_TRIM_MASK                          (3 << 0)
#define DA7280_HBRIDGE_ERC_LS_TRIM_SHIFT                         2
#define DA7280_HBRIDGE_ERC_LS_TRIM_MASK                          (3 << 2)

/* DA7280_IRQ_EVENT_ACTUATOR_FAULT (Address 0x0081) */
#define DA7280_E_TEST_ADC_SAT_FAULT_SHIFT     2
#define DA7280_E_TEST_ADC_SAT_FAULT_MASK      (1 << 2)

/* DA7280_IRQ_STATUS2 (Address 0x0082) */
#define DA7280_STA_TEST_ADC_SAT_SHIFT                      7
#define DA7280_STA_TEST_ADC_SAT_MASK                       (1 << 7)

/* DA7280_IRQ_MASK2 (Address 0x0083) */
#define DA7280_TEST_ADC_SAT_M_SHIFT                          7
#define DA7280_TEST_ADC_SAT_M_MASK                           (1 << 7)

/* DA7280_SNP_MEM_XX (Address 0x0084 ~ 0x00e7) */
#define DA7280_SNP_MEM_SHIFT                               0
#define DA7280_SNP_MEM_MASK                                (255 << 0)
#define DA7280_DEV_NONE			0xFF
#define DA7280_OPMODE_NONE		0xFF

#endif /* __HAPTIC_DA7280_REGISTERS_H */
