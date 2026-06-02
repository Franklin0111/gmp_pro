/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// ANALOG -> IRIS_ANALOG_PinMux Pinmux
//

//
// CANA -> IRIS_CAN Pinmux
//
//
// CANA_RX - GPIO Settings
//
#define GPIO_PIN_CANA_RX 30
#define IRIS_CAN_CANRX_GPIO 30
#define IRIS_CAN_CANRX_PIN_CONFIG GPIO_30_CANA_RX
//
// CANA_TX - GPIO Settings
//
#define GPIO_PIN_CANA_TX 31
#define IRIS_CAN_CANTX_GPIO 31
#define IRIS_CAN_CANTX_PIN_CONFIG GPIO_31_CANA_TX

//
// EPWM2 -> IRIS_EPWM1 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define IRIS_EPWM1_EPWMA_GPIO 2
#define IRIS_EPWM1_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define IRIS_EPWM1_EPWMB_GPIO 3
#define IRIS_EPWM1_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM1 -> IRIS_EPWM2 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define IRIS_EPWM2_EPWMA_GPIO 0
#define IRIS_EPWM2_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define IRIS_EPWM2_EPWMB_GPIO 1
#define IRIS_EPWM2_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM4 -> IRIS_EPWM3 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 22
#define IRIS_EPWM3_EPWMA_GPIO 22
#define IRIS_EPWM3_EPWMA_PIN_CONFIG GPIO_22_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 7
#define IRIS_EPWM3_EPWMB_GPIO 7
#define IRIS_EPWM3_EPWMB_PIN_CONFIG GPIO_7_EPWM4_B

//
// EPWM3 -> IRIS_EPWM4 Pinmux
//
//
// EPWM3_A - GPIO Settings
//
#define GPIO_PIN_EPWM3_A 4
#define IRIS_EPWM4_EPWMA_GPIO 4
#define IRIS_EPWM4_EPWMA_PIN_CONFIG GPIO_4_EPWM3_A
//
// EPWM3_B - GPIO Settings
//
#define GPIO_PIN_EPWM3_B 5
#define IRIS_EPWM4_EPWMB_GPIO 5
#define IRIS_EPWM4_EPWMB_PIN_CONFIG GPIO_5_EPWM3_B

//
// EPWM8 -> IRIS_EPWM5 Pinmux
//
//
// EPWM8_A - GPIO Settings
//
#define GPIO_PIN_EPWM8_A 14
#define IRIS_EPWM5_EPWMA_GPIO 14
#define IRIS_EPWM5_EPWMA_PIN_CONFIG GPIO_14_EPWM8_A
//
// EPWM8_B - GPIO Settings
//
#define GPIO_PIN_EPWM8_B 15
#define IRIS_EPWM5_EPWMB_GPIO 15
#define IRIS_EPWM5_EPWMB_PIN_CONFIG GPIO_15_EPWM8_B

//
// EPWM7 -> IRIS_EPWM6 Pinmux
//
//
// EPWM7_A - GPIO Settings
//
#define GPIO_PIN_EPWM7_A 28
#define IRIS_EPWM6_EPWMA_GPIO 28
#define IRIS_EPWM6_EPWMA_PIN_CONFIG GPIO_28_EPWM7_A
//
// EPWM7_B - GPIO Settings
//
#define GPIO_PIN_EPWM7_B 29
#define IRIS_EPWM6_EPWMB_GPIO 29
#define IRIS_EPWM6_EPWMB_PIN_CONFIG GPIO_29_EPWM7_B

//
// EQEP1 -> IRIS_EQEP1 Pinmux
//
//
// EQEP1_A - GPIO Settings
//
#define GPIO_PIN_EQEP1_A 20
#define IRIS_EQEP1_EQEPA_GPIO 20
#define IRIS_EQEP1_EQEPA_PIN_CONFIG GPIO_20_EQEP1_A
//
// EQEP1_B - GPIO Settings
//
#define GPIO_PIN_EQEP1_B 21
#define IRIS_EQEP1_EQEPB_GPIO 21
#define IRIS_EQEP1_EQEPB_PIN_CONFIG GPIO_21_EQEP1_B
//
// EQEP1_INDEX - GPIO Settings
//
#define GPIO_PIN_EQEP1_INDEX 13
#define IRIS_EQEP1_EQEPINDEX_GPIO 13
#define IRIS_EQEP1_EQEPINDEX_PIN_CONFIG GPIO_13_EQEP1_INDEX

//
// EQEP2 -> IRIS_EQEP2 Pinmux
//
//
// EQEP2_A - GPIO Settings
//
#define GPIO_PIN_EQEP2_A 24
#define IRIS_EQEP2_EQEPA_GPIO 24
#define IRIS_EQEP2_EQEPA_PIN_CONFIG GPIO_24_EQEP2_A
//
// EQEP2_B - GPIO Settings
//
#define GPIO_PIN_EQEP2_B 33
#define IRIS_EQEP2_EQEPB_GPIO 33
#define IRIS_EQEP2_EQEPB_PIN_CONFIG GPIO_33_EQEP2_B
//
// EQEP2_INDEX - GPIO Settings
//
#define GPIO_PIN_EQEP2_INDEX 26
#define IRIS_EQEP2_EQEPINDEX_GPIO 26
#define IRIS_EQEP2_EQEPINDEX_PIN_CONFIG GPIO_26_EQEP2_INDEX

//
// FSIRXA -> myBoardFSI0_FSIRX Pinmux
//
//
// FSIRXA_D0 - GPIO Settings
//
#define GPIO_PIN_FSIRXA_D0 52
#define myBoardFSI0_FSIRX_FSIRXD0_GPIO 52
#define myBoardFSI0_FSIRX_FSIRXD0_PIN_CONFIG GPIO_52_FSIRXA_D0
//
// FSIRXA_D1 - GPIO Settings
//
#define GPIO_PIN_FSIRXA_D1 53
#define myBoardFSI0_FSIRX_FSIRXD1_GPIO 53
#define myBoardFSI0_FSIRX_FSIRXD1_PIN_CONFIG GPIO_53_FSIRXA_D1
//
// FSIRXA_CLK - GPIO Settings
//
#define GPIO_PIN_FSIRXA_CLK 54
#define myBoardFSI0_FSIRX_FSIRXCLK_GPIO 54
#define myBoardFSI0_FSIRX_FSIRXCLK_PIN_CONFIG GPIO_54_FSIRXA_CLK

//
// FSITXA -> myBoardFSI0_FSITX Pinmux
//
//
// FSITXA_D0 - GPIO Settings
//
#define GPIO_PIN_FSITXA_D0 49
#define myBoardFSI0_FSITX_FSITXD0_GPIO 49
#define myBoardFSI0_FSITX_FSITXD0_PIN_CONFIG GPIO_49_FSITXA_D0
//
// FSITXA_D1 - GPIO Settings
//
#define GPIO_PIN_FSITXA_D1 50
#define myBoardFSI0_FSITX_FSITXD1_GPIO 50
#define myBoardFSI0_FSITX_FSITXD1_PIN_CONFIG GPIO_50_FSITXA_D1
//
// FSITXA_CLK - GPIO Settings
//
#define GPIO_PIN_FSITXA_CLK 51
#define myBoardFSI0_FSITX_FSITXCLK_GPIO 51
#define myBoardFSI0_FSITX_FSITXCLK_PIN_CONFIG GPIO_51_FSITXA_CLK
//
// GPIO58 - GPIO Settings
//
#define IRIS_GPIO1_GPIO_PIN_CONFIG GPIO_58_GPIO58
//
// GPIO23 - GPIO Settings
//
#define IRIS_GPIO2_GPIO_PIN_CONFIG GPIO_23_GPIO23
//
// GPIO40 - GPIO Settings
//
#define IRIS_GPIO3_GPIO_PIN_CONFIG GPIO_40_GPIO40
//
// GPIO44 - GPIO Settings
//
#define IRIS_GPIO4_GPIO_PIN_CONFIG GPIO_44_GPIO44
//
// GPIO34 - GPIO Settings
//
#define IRIS_GPIO5_GPIO_PIN_CONFIG GPIO_34_GPIO34
//
// GPIO47 - GPIO Settings
//
#define IRIS_GPIO6_GPIO_PIN_CONFIG GPIO_47_GPIO47
//
// GPIO61 - GPIO Settings
//
#define IRIS_LED1_GPIO_PIN_CONFIG GPIO_61_GPIO61
//
// GPIO59 - GPIO Settings
//
#define IRIS_LED2_GPIO_PIN_CONFIG GPIO_59_GPIO59
//
// GPIO55 - GPIO Settings
//
#define IRIS_GPIO_SPI_RST_GPIO_PIN_CONFIG GPIO_55_GPIO55

//
// I2CA -> IRIS_IIC Pinmux
//
//
// I2CA_SDA - GPIO Settings
//
#define GPIO_PIN_I2CA_SDA 56
#define IRIS_IIC_I2CSDA_GPIO 56
#define IRIS_IIC_I2CSDA_PIN_CONFIG GPIO_56_I2CA_SDA
//
// I2CA_SCL - GPIO Settings
//
#define GPIO_PIN_I2CA_SCL 57
#define IRIS_IIC_I2CSCL_GPIO 57
#define IRIS_IIC_I2CSCL_PIN_CONFIG GPIO_57_I2CA_SCL

//
// OTHER -> OTHER_PIN_DEFINITION Pinmux
//
//
// ADCSOCAO - GPIO Settings
//
#define GPIO_PIN_ADCSOCAO 8
#define OTHER_PIN_DEFINITION_ADCSOCAO_GPIO 8
#define OTHER_PIN_DEFINITION_ADCSOCAO_PIN_CONFIG GPIO_8_ADCSOCAO
//
// SYNCOUT - GPIO Settings
//
#define GPIO_PIN_SYNCOUT 6
#define OTHER_PIN_DEFINITION_SYNCOUT_GPIO 6
#define OTHER_PIN_DEFINITION_SYNCOUT_PIN_CONFIG GPIO_6_SYNCOUT
//
// XCLKOUT - GPIO Settings
//
#define GPIO_PIN_XCLKOUT 18
#define OTHER_PIN_DEFINITION_XCLKOUT_GPIO 18
#define OTHER_PIN_DEFINITION_XCLKOUT_PIN_CONFIG GPIO_18_XCLKOUT
//
// TDO - GPIO Settings
//
#define GPIO_PIN_TDO 37
#define OTHER_PIN_DEFINITION_TDO_GPIO 37
#define OTHER_PIN_DEFINITION_TDO_PIN_CONFIG GPIO_37_TDO
//
// TDI - GPIO Settings
//
#define GPIO_PIN_TDI 35
#define OTHER_PIN_DEFINITION_TDI_GPIO 35
#define OTHER_PIN_DEFINITION_TDI_PIN_CONFIG GPIO_35_TDI
//
// GPIO19 - GPIO Settings
//
#define GPIO_PIN_GPIO19 19
#define OTHER_PIN_DEFINITION_X1_GPIO 19
#define OTHER_PIN_DEFINITION_X1_PIN_CONFIG GPIO_19_GPIO19

//
// SCIA -> IRIS_UART_RS232 Pinmux
//
//
// SCIA_RX - GPIO Settings
//
#define GPIO_PIN_SCIA_RX 9
#define IRIS_UART_RS232_SCIRX_GPIO 9
#define IRIS_UART_RS232_SCIRX_PIN_CONFIG GPIO_9_SCIA_RX
//
// SCIA_TX - GPIO Settings
//
#define GPIO_PIN_SCIA_TX 48
#define IRIS_UART_RS232_SCITX_GPIO 48
#define IRIS_UART_RS232_SCITX_PIN_CONFIG GPIO_48_SCIA_TX

//
// SCIB -> IRIS_UART_USB Pinmux
//
//
// SCIB_RX - GPIO Settings
//
#define GPIO_PIN_SCIB_RX 41
#define IRIS_UART_USB_SCIRX_GPIO 41
#define IRIS_UART_USB_SCIRX_PIN_CONFIG GPIO_41_SCIB_RX
//
// SCIB_TX - GPIO Settings
//
#define GPIO_PIN_SCIB_TX 10
#define IRIS_UART_USB_SCITX_GPIO 10
#define IRIS_UART_USB_SCITX_PIN_CONFIG GPIO_10_SCIB_TX

//
// SPIA -> IRIS_SPI_FPGA_BRIDGE Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 16
#define IRIS_SPI_FPGA_BRIDGE_SPIPICO_GPIO 16
#define IRIS_SPI_FPGA_BRIDGE_SPIPICO_PIN_CONFIG GPIO_16_SPIA_SIMO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 17
#define IRIS_SPI_FPGA_BRIDGE_SPIPOCI_GPIO 17
#define IRIS_SPI_FPGA_BRIDGE_SPIPOCI_PIN_CONFIG GPIO_17_SPIA_SOMI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 12
#define IRIS_SPI_FPGA_BRIDGE_SPICLK_GPIO 12
#define IRIS_SPI_FPGA_BRIDGE_SPICLK_PIN_CONFIG GPIO_12_SPIA_CLK
//
// SPIA_PTE - GPIO Settings
//
#define GPIO_PIN_SPIA_PTE 11
#define IRIS_SPI_FPGA_BRIDGE_SPIPTE_GPIO 11
#define IRIS_SPI_FPGA_BRIDGE_SPIPTE_PIN_CONFIG GPIO_11_SPIA_STE

//
// SPIB -> IRIS_SPI_OUT Pinmux
//
//
// SPIB_PICO - GPIO Settings
//
#define GPIO_PIN_SPIB_PICO 60
#define IRIS_SPI_OUT_SPIPICO_GPIO 60
#define IRIS_SPI_OUT_SPIPICO_PIN_CONFIG GPIO_60_SPIB_SIMO
//
// SPIB_POCI - GPIO Settings
//
#define GPIO_PIN_SPIB_POCI 25
#define IRIS_SPI_OUT_SPIPOCI_GPIO 25
#define IRIS_SPI_OUT_SPIPOCI_PIN_CONFIG GPIO_25_SPIB_SOMI
//
// SPIB_CLK - GPIO Settings
//
#define GPIO_PIN_SPIB_CLK 32
#define IRIS_SPI_OUT_SPICLK_GPIO 32
#define IRIS_SPI_OUT_SPICLK_PIN_CONFIG GPIO_32_SPIB_CLK
//
// SPIB_PTE - GPIO Settings
//
#define GPIO_PIN_SPIB_PTE 27
#define IRIS_SPI_OUT_SPIPTE_GPIO 27
#define IRIS_SPI_OUT_SPIPTE_PIN_CONFIG GPIO_27_SPIB_STE

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define IRIS_ADCA_BASE ADCA_BASE
#define IRIS_ADCA_RESULT_BASE ADCARESULT_BASE
#define SIN_SOURCE ADC_SOC_NUMBER0
#define SIN_SOURCE_FORCE ADC_FORCE_SOC0
#define SIN_SOURCE_ADC_BASE ADCA_BASE
#define SIN_SOURCE_RESULT_BASE ADCARESULT_BASE
#define SIN_SOURCE_SAMPLE_WINDOW 75
#define SIN_SOURCE_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define SIN_SOURCE_CHANNEL ADC_CH_ADCIN6
#define INV_IA ADC_SOC_NUMBER1
#define INV_IA_FORCE ADC_FORCE_SOC1
#define INV_IA_ADC_BASE ADCA_BASE
#define INV_IA_RESULT_BASE ADCARESULT_BASE
#define INV_IA_SAMPLE_WINDOW 75
#define INV_IA_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_IA_CHANNEL ADC_CH_ADCIN8
#define INV_UA ADC_SOC_NUMBER2
#define INV_UA_FORCE ADC_FORCE_SOC2
#define INV_UA_ADC_BASE ADCA_BASE
#define INV_UA_RESULT_BASE ADCARESULT_BASE
#define INV_UA_SAMPLE_WINDOW 75
#define INV_UA_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UA_CHANNEL ADC_CH_ADCIN10
#define INV_UU ADC_SOC_NUMBER3
#define INV_UU_FORCE ADC_FORCE_SOC3
#define INV_UU_ADC_BASE ADCA_BASE
#define INV_UU_RESULT_BASE ADCARESULT_BASE
#define INV_UU_SAMPLE_WINDOW 75
#define INV_UU_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UU_CHANNEL ADC_CH_ADCIN6
#define INV_VBUS ADC_SOC_NUMBER4
#define INV_VBUS_FORCE ADC_FORCE_SOC4
#define INV_VBUS_ADC_BASE ADCA_BASE
#define INV_VBUS_RESULT_BASE ADCARESULT_BASE
#define INV_VBUS_SAMPLE_WINDOW 75
#define INV_VBUS_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_VBUS_CHANNEL ADC_CH_ADCIN11
void IRIS_ADCA_init();

#define IRIS_ADCB_BASE ADCB_BASE
#define IRIS_ADCB_RESULT_BASE ADCBRESULT_BASE
#define SIN_FS ADC_SOC_NUMBER0
#define SIN_FS_FORCE ADC_FORCE_SOC0
#define SIN_FS_ADC_BASE ADCB_BASE
#define SIN_FS_RESULT_BASE ADCBRESULT_BASE
#define SIN_FS_SAMPLE_WINDOW 75
#define SIN_FS_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define SIN_FS_CHANNEL ADC_CH_ADCIN2
#define INV_IB ADC_SOC_NUMBER1
#define INV_IB_FORCE ADC_FORCE_SOC1
#define INV_IB_ADC_BASE ADCB_BASE
#define INV_IB_RESULT_BASE ADCBRESULT_BASE
#define INV_IB_SAMPLE_WINDOW 75
#define INV_IB_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_IB_CHANNEL ADC_CH_ADCIN8
#define INV_UB ADC_SOC_NUMBER2
#define INV_UB_FORCE ADC_FORCE_SOC2
#define INV_UB_ADC_BASE ADCB_BASE
#define INV_UB_RESULT_BASE ADCBRESULT_BASE
#define INV_UB_SAMPLE_WINDOW 75
#define INV_UB_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UB_CHANNEL ADC_CH_ADCIN0
#define INV_UV ADC_SOC_NUMBER3
#define INV_UV_FORCE ADC_FORCE_SOC3
#define INV_UV_ADC_BASE ADCB_BASE
#define INV_UV_RESULT_BASE ADCBRESULT_BASE
#define INV_UV_SAMPLE_WINDOW 75
#define INV_UV_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UV_CHANNEL ADC_CH_ADCIN3
#define INV_IBUS ADC_SOC_NUMBER4
#define INV_IBUS_FORCE ADC_FORCE_SOC4
#define INV_IBUS_ADC_BASE ADCB_BASE
#define INV_IBUS_RESULT_BASE ADCBRESULT_BASE
#define INV_IBUS_SAMPLE_WINDOW 75
#define INV_IBUS_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_IBUS_CHANNEL ADC_CH_ADCIN12
void IRIS_ADCB_init();

#define IRIS_ADCC_BASE ADCC_BASE
#define IRIS_ADCC_RESULT_BASE ADCCRESULT_BASE
#define INV_IW ADC_SOC_NUMBER0
#define INV_IW_FORCE ADC_FORCE_SOC0
#define INV_IW_ADC_BASE ADCC_BASE
#define INV_IW_RESULT_BASE ADCCRESULT_BASE
#define INV_IW_SAMPLE_WINDOW 75
#define INV_IW_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_IW_CHANNEL ADC_CH_ADCIN4
#define INV_IC ADC_SOC_NUMBER1
#define INV_IC_FORCE ADC_FORCE_SOC1
#define INV_IC_ADC_BASE ADCC_BASE
#define INV_IC_RESULT_BASE ADCCRESULT_BASE
#define INV_IC_SAMPLE_WINDOW 75
#define INV_IC_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_IC_CHANNEL ADC_CH_ADCIN8
#define INV_UC ADC_SOC_NUMBER2
#define INV_UC_FORCE ADC_FORCE_SOC2
#define INV_UC_ADC_BASE ADCC_BASE
#define INV_UC_RESULT_BASE ADCCRESULT_BASE
#define INV_UC_SAMPLE_WINDOW 75
#define INV_UC_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UC_CHANNEL ADC_CH_ADCIN14
#define INV_UW ADC_SOC_NUMBER3
#define INV_UW_FORCE ADC_FORCE_SOC3
#define INV_UW_ADC_BASE ADCC_BASE
#define INV_UW_RESULT_BASE ADCCRESULT_BASE
#define INV_UW_SAMPLE_WINDOW 75
#define INV_UW_TRIGGER_SOURCE ADC_TRIGGER_EPWM1_SOCA
#define INV_UW_CHANNEL ADC_CH_ADCIN6
void IRIS_ADCC_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
#define IRIS_CAN_BASE CANA_BASE

#define IRIS_CAN_MessageObj1_ID 257
#define IRIS_CAN_MessageObj2_ID 258
#define IRIS_CAN_MessageObj3_ID 259
#define IRIS_CAN_MessageObj4_ID 513
#define IRIS_CAN_MessageObj5_ID 514
#define IRIS_CAN_MessageObj6_ID 515
#define IRIS_CAN_MessageObj7_ID 516
#define IRIS_CAN_MessageObj8_ID 517
#define IRIS_CAN_MessageObj9_ID 518
#define IRIS_CAN_MessageObj10_ID 519
void IRIS_CAN_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
#define myCPUTIMER0_BASE CPUTIMER0_BASE
void myCPUTIMER0_init();

//*****************************************************************************
//
// DAC Configurations
//
//*****************************************************************************
#define IRIS_DACA_BASE DACA_BASE
void IRIS_DACA_init();
#define IRIS_DACB_BASE DACB_BASE
void IRIS_DACB_init();

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define IRIS_EPWM1_BASE EPWM2_BASE
#define IRIS_EPWM1_TBPRD 3000
#define IRIS_EPWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM1_TBPHS 0
#define IRIS_EPWM1_CMPA 1500
#define IRIS_EPWM1_CMPB 1500
#define IRIS_EPWM1_CMPC 0
#define IRIS_EPWM1_CMPD 0
#define IRIS_EPWM1_DBRED 50
#define IRIS_EPWM1_DBFED 50
#define IRIS_EPWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define IRIS_EPWM2_BASE EPWM1_BASE
#define IRIS_EPWM2_TBPRD 3000
#define IRIS_EPWM2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM2_TBPHS 0
#define IRIS_EPWM2_CMPA 1500
#define IRIS_EPWM2_CMPB 1500
#define IRIS_EPWM2_CMPC 0
#define IRIS_EPWM2_CMPD 0
#define IRIS_EPWM2_DBRED 50
#define IRIS_EPWM2_DBFED 50
#define IRIS_EPWM2_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM2_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM2_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define IRIS_EPWM3_BASE EPWM4_BASE
#define IRIS_EPWM3_TBPRD 3000
#define IRIS_EPWM3_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM3_TBPHS 0
#define IRIS_EPWM3_CMPA 1500
#define IRIS_EPWM3_CMPB 1500
#define IRIS_EPWM3_CMPC 0
#define IRIS_EPWM3_CMPD 0
#define IRIS_EPWM3_DBRED 50
#define IRIS_EPWM3_DBFED 50
#define IRIS_EPWM3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define IRIS_EPWM4_BASE EPWM3_BASE
#define IRIS_EPWM4_TBPRD 3000
#define IRIS_EPWM4_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM4_TBPHS 0
#define IRIS_EPWM4_CMPA 1500
#define IRIS_EPWM4_CMPB 1500
#define IRIS_EPWM4_CMPC 0
#define IRIS_EPWM4_CMPD 0
#define IRIS_EPWM4_DBRED 50
#define IRIS_EPWM4_DBFED 50
#define IRIS_EPWM4_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM4_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM4_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define IRIS_EPWM5_BASE EPWM8_BASE
#define IRIS_EPWM5_TBPRD 3000
#define IRIS_EPWM5_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM5_TBPHS 0
#define IRIS_EPWM5_CMPA 1500
#define IRIS_EPWM5_CMPB 1500
#define IRIS_EPWM5_CMPC 0
#define IRIS_EPWM5_CMPD 0
#define IRIS_EPWM5_DBRED 50
#define IRIS_EPWM5_DBFED 50
#define IRIS_EPWM5_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM5_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM5_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define IRIS_EPWM6_BASE EPWM7_BASE
#define IRIS_EPWM6_TBPRD 3000
#define IRIS_EPWM6_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define IRIS_EPWM6_TBPHS 0
#define IRIS_EPWM6_CMPA 1500
#define IRIS_EPWM6_CMPB 1500
#define IRIS_EPWM6_CMPC 0
#define IRIS_EPWM6_CMPD 0
#define IRIS_EPWM6_DBRED 50
#define IRIS_EPWM6_DBFED 50
#define IRIS_EPWM6_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM6_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define IRIS_EPWM6_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD

//*****************************************************************************
//
// EQEP Configurations
//
//*****************************************************************************
#define IRIS_EQEP1_BASE EQEP1_BASE
void IRIS_EQEP1_init();
#define IRIS_EQEP2_BASE EQEP2_BASE
void IRIS_EQEP2_init();

//*****************************************************************************
//
// FSIRX Configurations
//
//*****************************************************************************
//
// Rx Defines
// Pointer to be declared in example code before use
//
#define myBoardFSI0_FSIRX_BASE FSIRXA_BASE
#define myBoardFSI0_FSIRX_nWords 8
void myBoardFSI0_FSIRX_init();

//*****************************************************************************
//
// FSITX Configurations
//
//*****************************************************************************
//
// Tx Defines
// Pointer to be declared in example code before use
//
#define myBoardFSI0_FSITX_BASE FSITXA_BASE
#define myBoardFSI0_FSITX_PRESCALER_VAL 4
#define myBoardFSI0_FSITX_nWords 8
void myBoardFSI0_FSITX_init();

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define IRIS_GPIO1 58
void IRIS_GPIO1_init();
#define IRIS_GPIO2 23
void IRIS_GPIO2_init();
#define IRIS_GPIO3 40
void IRIS_GPIO3_init();
#define IRIS_GPIO4 44
void IRIS_GPIO4_init();
#define IRIS_GPIO5 34
void IRIS_GPIO5_init();
#define IRIS_GPIO6 47
void IRIS_GPIO6_init();
#define IRIS_LED1 61
void IRIS_LED1_init();
#define IRIS_LED2 59
void IRIS_LED2_init();
#define IRIS_GPIO_SPI_RST 55
void IRIS_GPIO_SPI_RST_init();

//*****************************************************************************
//
// I2C Configurations
//
//*****************************************************************************
#define IRIS_IIC_BASE I2CA_BASE
#define IRIS_IIC_BITRATE 50000
#define IRIS_IIC_TARGET_ADDRESS 112
#define IRIS_IIC_OWN_ADDRESS 8
#define IRIS_IIC_MODULE_CLOCK_FREQUENCY 10000000
void IRIS_IIC_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_IRIS_ADCA_1
// ISR need to be defined for the registered interrupts
#define INT_IRIS_ADCA_1 INT_ADCA1
#define INT_IRIS_ADCA_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void MainISR(void);

// Interrupt Settings for INT_IRIS_CAN_0
// ISR need to be defined for the registered interrupts
#define INT_IRIS_CAN_0 INT_CANA0
#define INT_IRIS_CAN_0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_IRIS_CAN_0_ISR(void);

// Interrupt Settings for INT_IRIS_CAN_1
// ISR need to be defined for the registered interrupts
#define INT_IRIS_CAN_1 INT_CANA1
#define INT_IRIS_CAN_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_IRIS_CAN_1_ISR(void);

// Interrupt Settings for INT_IRIS_UART_RS232_RX
// ISR need to be defined for the registered interrupts
#define INT_IRIS_UART_RS232_RX INT_SCIA_RX
#define INT_IRIS_UART_RS232_RX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_IRIS_UART_RS232_RX_ISR(void);

// Interrupt Settings for INT_IRIS_UART_USB_RX
// ISR need to be defined for the registered interrupts
#define INT_IRIS_UART_USB_RX INT_SCIB_RX
#define INT_IRIS_UART_USB_RX_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_IRIS_UART_USB_RX_ISR(void);

//*****************************************************************************
//
// OTHER Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define IRIS_UART_RS232_BASE SCIA_BASE
#define IRIS_UART_RS232_BAUDRATE 115200
#define IRIS_UART_RS232_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define IRIS_UART_RS232_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define IRIS_UART_RS232_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define IRIS_UART_RS232_FIFO_TX_LVL SCI_FIFO_TX0
#define IRIS_UART_RS232_FIFO_RX_LVL SCI_FIFO_RX0
void IRIS_UART_RS232_init();
#define IRIS_UART_USB_BASE SCIB_BASE
#define IRIS_UART_USB_BAUDRATE 921600
#define IRIS_UART_USB_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define IRIS_UART_USB_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define IRIS_UART_USB_CONFIG_PAR SCI_CONFIG_PAR_NONE
#define IRIS_UART_USB_FIFO_TX_LVL SCI_FIFO_TX0
#define IRIS_UART_USB_FIFO_RX_LVL SCI_FIFO_RX14
void IRIS_UART_USB_init();

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define IRIS_SPI_FPGA_BRIDGE_BASE SPIA_BASE
#define IRIS_SPI_FPGA_BRIDGE_BITRATE 15000000
#define IRIS_SPI_FPGA_BRIDGE_DATAWIDTH 16
void IRIS_SPI_FPGA_BRIDGE_init();
#define IRIS_SPI_OUT_BASE SPIB_BASE
#define IRIS_SPI_OUT_BITRATE 1000000
#define IRIS_SPI_OUT_DATAWIDTH 16
void IRIS_SPI_OUT_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CAN_init();
void	CPUTIMER_init();
void	DAC_init();
void	EPWM_init();
void	EQEP_init();
void	FSIRX_init();
void	FSITX_init();
void	GPIO_init();
void	I2C_init();
void	INTERRUPT_init();
void	OTHER_init();
void	SCI_init();
void	SPI_init();
void	SYNC_init();
void	SYSCTL_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
