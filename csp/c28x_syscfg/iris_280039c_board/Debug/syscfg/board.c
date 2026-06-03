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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYSCTL_init();
	INPUTXBAR_init();
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	CAN_init();
	CPUTIMER_init();
	DAC_init();
	ECAP_init();
	EPWM_init();
	EQEP_init();
	FSIRX_init();
	FSITX_init();
	GPIO_init();
	I2C_init();
	OTHER_init();
	SCI_init();
	SPI_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// ANALOG -> IRIS_ANALOG_PinMux Pinmux
	//
	// Analog PinMux for A0/B15/C15/DACA_OUT
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(231, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A1/B7/DACB_OUT
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(232, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A10/B1/C10
	GPIO_setPinConfig(GPIO_230_GPIO230);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(230, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A11/B10/C0
	GPIO_setPinConfig(GPIO_237_GPIO237);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(237, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A12, C5
	GPIO_setPinConfig(GPIO_238_GPIO238);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(238, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A14/B14/C4
	GPIO_setPinConfig(GPIO_239_GPIO239);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(239, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/B6/C9
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3, C7/B9
	GPIO_setPinConfig(GPIO_229_GPIO229);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(229, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A4/B8
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(225, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A5
	GPIO_setPinConfig(GPIO_249_GPIO249);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(249, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A6
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(228, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A8
	GPIO_setPinConfig(GPIO_240_GPIO240);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(240, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A9
	GPIO_setPinConfig(GPIO_227_GPIO227);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(227, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B0/C11
	GPIO_setPinConfig(GPIO_253_GPIO253);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(253, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B11
	GPIO_setPinConfig(GPIO_251_GPIO251);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(251, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B2/C6
	GPIO_setPinConfig(GPIO_226_GPIO226);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(226, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B3/VDAC
	GPIO_setPinConfig(GPIO_242_GPIO242);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(242, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B4/C8
	GPIO_setPinConfig(GPIO_236_GPIO236);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(236, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B5
	GPIO_setPinConfig(GPIO_252_GPIO252);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(252, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C1
	GPIO_setPinConfig(GPIO_248_GPIO248);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(248, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C14
	GPIO_setPinConfig(GPIO_247_GPIO247);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(247, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C2/B12
	GPIO_setPinConfig(GPIO_244_GPIO244);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(244, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C3/A7
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(245, GPIO_ANALOG_ENABLED);
	//
	// CANA -> IRIS_CAN Pinmux
	//
	GPIO_setPinConfig(IRIS_CAN_CANRX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_CAN_CANRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_CAN_CANRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_CAN_CANTX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_CAN_CANTX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_CAN_CANTX_GPIO, GPIO_QUAL_ASYNC);

	//
	// EPWM2 -> IRIS_EPWM1 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM1 -> IRIS_EPWM2 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM2_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM2_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM2_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM2_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM2_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM2_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> IRIS_EPWM3 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM3_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM3_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM3_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM3_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM3_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM3_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM3 -> IRIS_EPWM4 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM4_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM4_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM4_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM4_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM4_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM4_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM8 -> IRIS_EPWM5 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM5_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM5_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM5_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM5_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM5_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM5_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM7 -> IRIS_EPWM6 Pinmux
	//
	GPIO_setPinConfig(IRIS_EPWM6_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM6_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM6_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EPWM6_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EPWM6_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EPWM6_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EQEP1 -> IRIS_EQEP1 Pinmux
	//
	GPIO_setPinConfig(IRIS_EQEP1_EQEPA_PIN_CONFIG);
	// AGPIO -> GPIO mode selected
	// On 100PZ package for F28003x, if "B5, GPIO20" is used in peripheral signal digital mode, 
	// then "B5" can be used for ADC
	// On 100PZ package for F28003x, if "B11, GPIO21" is used in peripheral signal digital mode, 
	// then "B11" can be used for ADC
	GPIO_setAnalogMode(20, GPIO_ANALOG_DISABLED);
	GPIO_setPadConfig(IRIS_EQEP1_EQEPA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP1_EQEPA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EQEP1_EQEPB_PIN_CONFIG);
	// AGPIO -> GPIO mode selected
	// On 100PZ package for F28003x, if "B5, GPIO20" is used in peripheral signal digital mode, 
	// then "B5" can be used for ADC
	// On 100PZ package for F28003x, if "B11, GPIO21" is used in peripheral signal digital mode, 
	// then "B11" can be used for ADC
	GPIO_setAnalogMode(21, GPIO_ANALOG_DISABLED);
	GPIO_setPadConfig(IRIS_EQEP1_EQEPB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP1_EQEPB_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(IRIS_EQEP1_EQEPINDEX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EQEP1_EQEPINDEX_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP1_EQEPINDEX_GPIO, GPIO_QUAL_SYNC);

	//
	// EQEP2 -> IRIS_EQEP2 Pinmux
	//
	GPIO_setPinConfig(IRIS_EQEP2_EQEPA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EQEP2_EQEPA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP2_EQEPA_GPIO, GPIO_QUAL_3SAMPLE);

	GPIO_setPinConfig(IRIS_EQEP2_EQEPB_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EQEP2_EQEPB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP2_EQEPB_GPIO, GPIO_QUAL_3SAMPLE);

	GPIO_setPinConfig(IRIS_EQEP2_EQEPINDEX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_EQEP2_EQEPINDEX_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_EQEP2_EQEPINDEX_GPIO, GPIO_QUAL_3SAMPLE);

	//
	// FSIRXA -> myBoardFSI0_FSIRX Pinmux
	//
	GPIO_setPinConfig(myBoardFSI0_FSIRX_FSIRXD0_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSIRX_FSIRXD0_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSIRX_FSIRXD0_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myBoardFSI0_FSIRX_FSIRXD1_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSIRX_FSIRXD1_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSIRX_FSIRXD1_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myBoardFSI0_FSIRX_FSIRXCLK_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSIRX_FSIRXCLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSIRX_FSIRXCLK_GPIO, GPIO_QUAL_ASYNC);

	//
	// FSITXA -> myBoardFSI0_FSITX Pinmux
	//
	GPIO_setPinConfig(myBoardFSI0_FSITX_FSITXD0_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSITX_FSITXD0_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSITX_FSITXD0_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myBoardFSI0_FSITX_FSITXD1_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSITX_FSITXD1_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSITX_FSITXD1_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(myBoardFSI0_FSITX_FSITXCLK_PIN_CONFIG);
	GPIO_setPadConfig(myBoardFSI0_FSITX_FSITXCLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myBoardFSI0_FSITX_FSITXCLK_GPIO, GPIO_QUAL_ASYNC);

	// GPIO58 -> IRIS_GPIO1 Pinmux
	GPIO_setPinConfig(GPIO_58_GPIO58);
	// GPIO23 -> IRIS_GPIO2 Pinmux
	GPIO_setPinConfig(GPIO_23_GPIO23);
	// GPIO40 -> IRIS_GPIO3 Pinmux
	GPIO_setPinConfig(GPIO_40_GPIO40);
	// GPIO44 -> IRIS_GPIO4 Pinmux
	GPIO_setPinConfig(GPIO_44_GPIO44);
	// GPIO34 -> IRIS_GPIO5 Pinmux
	GPIO_setPinConfig(GPIO_34_GPIO34);
	// GPIO47 -> IRIS_GPIO6 Pinmux
	GPIO_setPinConfig(GPIO_47_GPIO47);
	// GPIO61 -> IRIS_LED1 Pinmux
	GPIO_setPinConfig(GPIO_61_GPIO61);
	// GPIO59 -> IRIS_LED2 Pinmux
	GPIO_setPinConfig(GPIO_59_GPIO59);
	// GPIO55 -> IRIS_GPIO_SPI_RST Pinmux
	GPIO_setPinConfig(GPIO_55_GPIO55);
	//
	// I2CA -> IRIS_IIC Pinmux
	//
	GPIO_setPinConfig(IRIS_IIC_I2CSDA_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_IIC_I2CSDA_GPIO, GPIO_PIN_TYPE_OD);
	GPIO_setQualificationMode(IRIS_IIC_I2CSDA_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_IIC_I2CSCL_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_IIC_I2CSCL_GPIO, GPIO_PIN_TYPE_OD);
	GPIO_setQualificationMode(IRIS_IIC_I2CSCL_GPIO, GPIO_QUAL_ASYNC);

	//
	// OTHER -> OTHER_PIN_DEFINITION Pinmux
	//
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_ADCSOCAO_PIN_CONFIG);
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_SYNCOUT_PIN_CONFIG);
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_XCLKOUT_PIN_CONFIG);
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_TDO_PIN_CONFIG);
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_TDI_PIN_CONFIG);
	GPIO_setPinConfig(OTHER_PIN_DEFINITION_X1_PIN_CONFIG);
	//
	// SCIA -> IRIS_UART_RS232 Pinmux
	//
	GPIO_setPinConfig(IRIS_UART_RS232_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_UART_RS232_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_UART_RS232_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_UART_RS232_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_UART_RS232_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_UART_RS232_SCITX_GPIO, GPIO_QUAL_ASYNC);

	//
	// SCIB -> IRIS_UART_USB Pinmux
	//
	GPIO_setPinConfig(IRIS_UART_USB_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_UART_USB_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_UART_USB_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_UART_USB_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_UART_USB_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(IRIS_UART_USB_SCITX_GPIO, GPIO_QUAL_ASYNC);

	//
	// SPIA -> IRIS_SPI_FPGA_BRIDGE Pinmux
	//
	GPIO_setPinConfig(IRIS_SPI_FPGA_BRIDGE_SPIPICO_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_FPGA_BRIDGE_SPIPICO_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_FPGA_BRIDGE_SPIPICO_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_FPGA_BRIDGE_SPIPOCI_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_FPGA_BRIDGE_SPIPOCI_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_FPGA_BRIDGE_SPIPOCI_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_FPGA_BRIDGE_SPICLK_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_FPGA_BRIDGE_SPICLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_FPGA_BRIDGE_SPICLK_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_FPGA_BRIDGE_SPIPTE_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_FPGA_BRIDGE_SPIPTE_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_FPGA_BRIDGE_SPIPTE_GPIO, GPIO_QUAL_ASYNC);

	//
	// SPIB -> IRIS_SPI_OUT Pinmux
	//
	GPIO_setPinConfig(IRIS_SPI_OUT_SPIPICO_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_OUT_SPIPICO_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_OUT_SPIPICO_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_OUT_SPIPOCI_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_OUT_SPIPOCI_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_OUT_SPIPOCI_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_OUT_SPICLK_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_OUT_SPICLK_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_OUT_SPICLK_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(IRIS_SPI_OUT_SPIPTE_PIN_CONFIG);
	GPIO_setPadConfig(IRIS_SPI_OUT_SPIPTE_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_SPI_OUT_SPIPTE_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	IRIS_ADCA_init();
	IRIS_ADCB_init();
	IRIS_ADCC_init();
}

void IRIS_ADCA_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(IRIS_ADCA_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(IRIS_ADCA_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(IRIS_ADCA_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(IRIS_ADCA_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(IRIS_ADCA_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(IRIS_ADCA_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(IRIS_ADCA_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCA_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN6, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCA_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN8
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCA_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN8, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCA_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN10
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCA_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN10, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCA_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCA_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN6, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCA_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN11
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCA_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN11, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCA_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		Source	: ADC_SOC_NUMBER0
	// 		Interrupt Source: enabled
	//		Continuous Mode	: enabled
	//
	//
	ADC_setInterruptSource(IRIS_ADCA_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER0);
	ADC_clearInterruptStatus(IRIS_ADCA_BASE, ADC_INT_NUMBER1);
	ADC_enableContinuousMode(IRIS_ADCA_BASE, ADC_INT_NUMBER1);
	ADC_enableInterrupt(IRIS_ADCA_BASE, ADC_INT_NUMBER1);
}

void IRIS_ADCB_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(IRIS_ADCB_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(IRIS_ADCB_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(IRIS_ADCB_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(IRIS_ADCB_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(IRIS_ADCB_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(IRIS_ADCB_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(IRIS_ADCB_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCB_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN2, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCB_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN8
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCB_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN8, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCB_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCB_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN0, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCB_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCB_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN3, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCB_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 4 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 4
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN12
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCB_BASE, ADC_SOC_NUMBER4, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN12, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCB_BASE, ADC_SOC_NUMBER4, ADC_INT_SOC_TRIGGER_NONE);
}

void IRIS_ADCC_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Set the analog voltage reference selection and ADC module's offset trims.
	// This function sets the analog voltage reference to internal (with the reference voltage of 1.65V or 2.5V) or external for ADC
	// which is same as ASysCtl APIs.
	//
	ADC_setVREF(IRIS_ADCC_BASE, ADC_REFERENCE_EXTERNAL, ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(IRIS_ADCC_BASE, ADC_CLK_DIV_2_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(IRIS_ADCC_BASE, ADC_PULSE_END_OF_ACQ_WIN);
	//
	// Sets the timing of early interrupt generation.
	//
	ADC_setInterruptCycleOffset(IRIS_ADCC_BASE, 0U);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(IRIS_ADCC_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(500);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Disables SOC burst mode.
	//
	ADC_disableBurstMode(IRIS_ADCC_BASE);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(IRIS_ADCC_BASE, ADC_PRI_ALL_ROUND_ROBIN);
	//
	// Start of Conversion 0 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 0
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCC_BASE, ADC_SOC_NUMBER0, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN4, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCC_BASE, ADC_SOC_NUMBER0, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 1 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 1
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN8
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCC_BASE, ADC_SOC_NUMBER1, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN8, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCC_BASE, ADC_SOC_NUMBER1, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 2 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 2
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN14
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCC_BASE, ADC_SOC_NUMBER2, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN14, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCC_BASE, ADC_SOC_NUMBER2, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 3 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 3
	//	  	Trigger			: ADC_TRIGGER_EPWM1_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(IRIS_ADCC_BASE, ADC_SOC_NUMBER3, ADC_TRIGGER_EPWM1_SOCA, ADC_CH_ADCIN6, 9U);
	ADC_setInterruptSOCTrigger(IRIS_ADCC_BASE, ADC_SOC_NUMBER3, ADC_INT_SOC_TRIGGER_NONE);
}


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to external.
	//
	ASysCtl_setAnalogReferenceExternal( ASYSCTL_VREFHI );
}


//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
void CAN_init(){
	IRIS_CAN_init();
}

void IRIS_CAN_init(){
	CAN_initModule(IRIS_CAN_BASE);
	//
	// Refer to the Driver Library User Guide for information on how to set
	// tighter timing control. Additionally, consult the device data sheet
	// for more information about the CAN module clocking.
	//
	CAN_setBitTiming(IRIS_CAN_BASE, 4, 0, 14, 7, 3);
	//
	// Enable CAN Auto-Bus-On
	//
	CAN_enableAutoBusOn(IRIS_CAN_BASE);
	//
	// Set Auto-Bus-On Timer
	//
	CAN_setAutoBusOnTime(IRIS_CAN_BASE, 128);
	//
	// Enable CAN Interrupts
	//
	CAN_enableInterrupt(IRIS_CAN_BASE, CAN_INT_IE0);
	CAN_enableGlobalInterrupt(IRIS_CAN_BASE, CAN_GLOBAL_INT_CANINT0);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 1
	//      Message Identifier: 257
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_RX
	//      Message ID Mask: 0
	//      Message Object Flags: CAN_MSG_OBJ_RX_INT_ENABLE
	//      Message Data Length: 0 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 1, IRIS_CAN_MessageObj1_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,0);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 2
	//      Message Identifier: 258
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_RX
	//      Message ID Mask: 0
	//      Message Object Flags: CAN_MSG_OBJ_RX_INT_ENABLE
	//      Message Data Length: 0 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 2, IRIS_CAN_MessageObj2_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,0);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 3
	//      Message Identifier: 259
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_RX
	//      Message ID Mask: 0
	//      Message Object Flags: CAN_MSG_OBJ_RX_INT_ENABLE
	//      Message Data Length: 0 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 3, IRIS_CAN_MessageObj3_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_RX, 0, CAN_MSG_OBJ_RX_INT_ENABLE,0);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 4
	//      Message Identifier: 513
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 4, IRIS_CAN_MessageObj4_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 5
	//      Message Identifier: 514
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 5, IRIS_CAN_MessageObj5_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 6
	//      Message Identifier: 515
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 6, IRIS_CAN_MessageObj6_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 7
	//      Message Identifier: 516
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 7, IRIS_CAN_MessageObj7_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 8
	//      Message Identifier: 517
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 8, IRIS_CAN_MessageObj8_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 9
	//      Message Identifier: 518
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 9, IRIS_CAN_MessageObj9_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	//
	// Initialize the transmit message object used for sending CAN messages.
	// Message Object Parameters:
	//      Message Object ID Number: 10
	//      Message Identifier: 519
	//      Message Frame: CAN_MSG_FRAME_STD
	//      Message Type: CAN_MSG_OBJ_TYPE_TX
	//      Message ID Mask: 0
	//      Message Object Flags: 
	//      Message Data Length: 8 Bytes
	//
	CAN_setupMessageObject(IRIS_CAN_BASE, 10, IRIS_CAN_MessageObj10_ID, CAN_MSG_FRAME_STD,CAN_MSG_OBJ_TYPE_TX, 0, 0,8);
	CAN_setInterruptMux(IRIS_CAN_BASE, 2032);
	//
	// Start CAN module operations
	//
	CAN_startModule(IRIS_CAN_BASE);
}

//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************
void CPUTIMER_init(){
	myCPUTIMER0_init();
}

void myCPUTIMER0_init(){
	CPUTimer_setEmulationMode(myCPUTIMER0_BASE, CPUTIMER_EMULATIONMODE_STOPAFTERNEXTDECREMENT);
	CPUTimer_setPreScaler(myCPUTIMER0_BASE, 0U);
	CPUTimer_setPeriod(myCPUTIMER0_BASE, 1000U);
	CPUTimer_disableInterrupt(myCPUTIMER0_BASE);
	CPUTimer_stopTimer(myCPUTIMER0_BASE);

	CPUTimer_reloadTimerCounter(myCPUTIMER0_BASE);
}

//*****************************************************************************
//
// DAC Configurations
//
//*****************************************************************************
void DAC_init(){
	IRIS_DACA_init();
	IRIS_DACB_init();
}

void IRIS_DACA_init(){
	//
	// Set DAC reference voltage.
	//
	DAC_setReferenceVoltage(IRIS_DACA_BASE, DAC_REF_ADC_VREFHI);
	//
	// Set DAC gain mode.
	//
	DAC_setGainMode(IRIS_DACA_BASE, DAC_GAIN_ONE);
	//
	// Set DAC load mode.
	//
	DAC_setLoadMode(IRIS_DACA_BASE, DAC_LOAD_SYSCLK);
	//
	// Enable the DAC output
	//
	DAC_enableOutput(IRIS_DACA_BASE);
	//
	// Set the DAC shadow output
	//
	DAC_setShadowValue(IRIS_DACA_BASE, 500U);

	//
	// Delay for buffered DAC to power up.
	//
	DEVICE_DELAY_US(500);
}
void IRIS_DACB_init(){
	//
	// Set DAC reference voltage.
	//
	DAC_setReferenceVoltage(IRIS_DACB_BASE, DAC_REF_ADC_VREFHI);
	//
	// Set DAC gain mode.
	//
	DAC_setGainMode(IRIS_DACB_BASE, DAC_GAIN_ONE);
	//
	// Set DAC load mode.
	//
	DAC_setLoadMode(IRIS_DACB_BASE, DAC_LOAD_SYSCLK);
	//
	// Enable the DAC output
	//
	DAC_enableOutput(IRIS_DACB_BASE);
	//
	// Set the DAC shadow output
	//
	DAC_setShadowValue(IRIS_DACB_BASE, 500U);

	//
	// Delay for buffered DAC to power up.
	//
	DEVICE_DELAY_US(500);
}

//*****************************************************************************
//
// ECAP Configurations
//
//*****************************************************************************
void ECAP_init(){
	capsource_init();
	capps_init();
}

void capsource_init(){
	//
	// Disable ,clear all capture flags and interrupts
	//
	ECAP_disableInterrupt(capsource_BASE,
		(ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
		ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
		ECAP_ISR_SOURCE_COUNTER_PERIOD   |
		ECAP_ISR_SOURCE_COUNTER_COMPARE));
	ECAP_clearInterrupt(capsource_BASE,
		(ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
		ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
		ECAP_ISR_SOURCE_COUNTER_PERIOD   |
		ECAP_ISR_SOURCE_COUNTER_COMPARE));
	//
	// Disables time stamp capture.
	//
	ECAP_disableTimeStampCapture(capsource_BASE);
	//
	// Stops Time stamp counter.
	//
	ECAP_stopCounter(capsource_BASE);
	//
	// Sets eCAP in Capture mode.
	//
	ECAP_enableCaptureMode(capsource_BASE);
	//
	// Sets the capture mode.
	//
	ECAP_setCaptureMode(capsource_BASE,ECAP_ONE_SHOT_CAPTURE_MODE,ECAP_EVENT_1);
	//
	// Sets the Capture event prescaler.
	//
	ECAP_setEventPrescaler(capsource_BASE, 0U);
	//
	// Sets the Capture event polarity.
	//
	ECAP_setEventPolarity(capsource_BASE,ECAP_EVENT_1,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capsource_BASE,ECAP_EVENT_2,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capsource_BASE,ECAP_EVENT_3,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capsource_BASE,ECAP_EVENT_4,ECAP_EVNT_RISING_EDGE);
	//
	// Configure counter reset on events
	//
	ECAP_disableCounterResetOnEvent(capsource_BASE,ECAP_EVENT_1);
	ECAP_disableCounterResetOnEvent(capsource_BASE,ECAP_EVENT_2);
	ECAP_disableCounterResetOnEvent(capsource_BASE,ECAP_EVENT_3);
	ECAP_disableCounterResetOnEvent(capsource_BASE,ECAP_EVENT_4);
	//
	// Select eCAP input.
	//
	ECAP_selectECAPInput(capsource_BASE,ECAP_INPUT_INPUTXBAR1);
	//
	// Sets a phase shift value count.
	//
	ECAP_setPhaseShiftCount(capsource_BASE,0U);
	//
	// Disable counter loading with phase shift value.
	//
	ECAP_disableLoadCounter(capsource_BASE);
	//
	// Configures Sync out signal mode.
	//
	ECAP_setSyncOutMode(capsource_BASE,ECAP_SYNC_OUT_SYNCI);
	//
	// Configures emulation mode.
	//
	ECAP_setEmulationMode(capsource_BASE,ECAP_EMULATION_STOP);
	//
	// Set up the source for sync-in pulse..
	//
	ECAP_setSyncInPulseSource(capsource_BASE,ECAP_SYNC_IN_PULSE_SRC_DISABLE);
	//
	// Starts Time stamp counter for capsource.
	//
	ECAP_startCounter(capsource_BASE);
	//
	// Enables time stamp capture for capsource.
	//
	ECAP_enableTimeStampCapture(capsource_BASE);
	//
	// Re-arms the eCAP module for capsource.
	//
	ECAP_reArm(capsource_BASE);
	//
	// Enables interrupt source for capsource.
	//
	ECAP_enableInterrupt(capsource_BASE,(ECAP_ISR_SOURCE_CAPTURE_EVENT_1));

    //-----------------Signal Monitoring--------------------//
}
void capps_init(){
	//
	// Disable ,clear all capture flags and interrupts
	//
	ECAP_disableInterrupt(capps_BASE,
		(ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
		ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
		ECAP_ISR_SOURCE_COUNTER_PERIOD   |
		ECAP_ISR_SOURCE_COUNTER_COMPARE));
	ECAP_clearInterrupt(capps_BASE,
		(ECAP_ISR_SOURCE_CAPTURE_EVENT_1  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_2  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_3  |
		ECAP_ISR_SOURCE_CAPTURE_EVENT_4  |
		ECAP_ISR_SOURCE_COUNTER_OVERFLOW |
		ECAP_ISR_SOURCE_COUNTER_PERIOD   |
		ECAP_ISR_SOURCE_COUNTER_COMPARE));
	//
	// Disables time stamp capture.
	//
	ECAP_disableTimeStampCapture(capps_BASE);
	//
	// Stops Time stamp counter.
	//
	ECAP_stopCounter(capps_BASE);
	//
	// Sets eCAP in Capture mode.
	//
	ECAP_enableCaptureMode(capps_BASE);
	//
	// Sets the capture mode.
	//
	ECAP_setCaptureMode(capps_BASE,ECAP_ONE_SHOT_CAPTURE_MODE,ECAP_EVENT_1);
	//
	// Sets the Capture event prescaler.
	//
	ECAP_setEventPrescaler(capps_BASE, 0U);
	//
	// Sets the Capture event polarity.
	//
	ECAP_setEventPolarity(capps_BASE,ECAP_EVENT_1,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capps_BASE,ECAP_EVENT_2,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capps_BASE,ECAP_EVENT_3,ECAP_EVNT_RISING_EDGE);
	ECAP_setEventPolarity(capps_BASE,ECAP_EVENT_4,ECAP_EVNT_RISING_EDGE);
	//
	// Configure counter reset on events
	//
	ECAP_disableCounterResetOnEvent(capps_BASE,ECAP_EVENT_1);
	ECAP_disableCounterResetOnEvent(capps_BASE,ECAP_EVENT_2);
	ECAP_disableCounterResetOnEvent(capps_BASE,ECAP_EVENT_3);
	ECAP_disableCounterResetOnEvent(capps_BASE,ECAP_EVENT_4);
	//
	// Select eCAP input.
	//
	ECAP_selectECAPInput(capps_BASE,ECAP_INPUT_INPUTXBAR2);
	//
	// Sets a phase shift value count.
	//
	ECAP_setPhaseShiftCount(capps_BASE,0U);
	//
	// Disable counter loading with phase shift value.
	//
	ECAP_disableLoadCounter(capps_BASE);
	//
	// Configures Sync out signal mode.
	//
	ECAP_setSyncOutMode(capps_BASE,ECAP_SYNC_OUT_SYNCI);
	//
	// Configures emulation mode.
	//
	ECAP_setEmulationMode(capps_BASE,ECAP_EMULATION_STOP);
	//
	// Set up the source for sync-in pulse..
	//
	ECAP_setSyncInPulseSource(capps_BASE,ECAP_SYNC_IN_PULSE_SRC_DISABLE);
	//
	// Starts Time stamp counter for capps.
	//
	ECAP_startCounter(capps_BASE);
	//
	// Enables time stamp capture for capps.
	//
	ECAP_enableTimeStampCapture(capps_BASE);
	//
	// Re-arms the eCAP module for capps.
	//
	ECAP_reArm(capps_BASE);
	//
	// Enables interrupt source for capps.
	//
	ECAP_enableInterrupt(capps_BASE,(ECAP_ISR_SOURCE_CAPTURE_EVENT_1));

    //-----------------Signal Monitoring--------------------//
}

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    EPWM_setClockPrescaler(IRIS_EPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM1_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM1_BASE, 3000);	
    EPWM_setTimeBaseCounter(IRIS_EPWM1_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM1_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM1_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM1_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM1_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM1_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM1_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM1_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM1_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM1_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM1_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM1_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM1_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM1_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM1_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM1_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM1_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM1_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM1_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM1_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM1_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM1_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM1_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM1_BASE, EPWM_SOC_A, 1);	
    EPWM_setClockPrescaler(IRIS_EPWM2_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM2_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM2_BASE, 300);	
    EPWM_setTimeBaseCounter(IRIS_EPWM2_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM2_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM2_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM2_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM2_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM2_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM2_BASE, EPWM_COUNTER_COMPARE_A, 150);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM2_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM2_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM2_BASE, EPWM_COUNTER_COMPARE_B, 150);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM2_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM2_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM2_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM2_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM2_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM2_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM2_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM2_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM2_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM2_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM2_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM2_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM2_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM2_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM2_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM2_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM2_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM2_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM2_BASE, EPWM_SOC_A, 1);	
    EPWM_setClockPrescaler(IRIS_EPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM3_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM3_BASE, 3000);	
    EPWM_setTimeBaseCounter(IRIS_EPWM3_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM3_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM3_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM3_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM3_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM3_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM3_BASE, EPWM_COUNTER_COMPARE_A, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM3_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM3_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM3_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM3_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM3_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM3_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM3_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM3_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM3_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM3_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM3_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM3_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM3_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM3_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM3_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM3_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM3_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM3_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM3_BASE, EPWM_SOC_A, 1);	
    EPWM_setClockPrescaler(IRIS_EPWM4_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM4_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM4_BASE, 3000);	
    EPWM_setTimeBaseCounter(IRIS_EPWM4_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM4_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM4_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM4_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM4_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM4_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM4_BASE, EPWM_COUNTER_COMPARE_A, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM4_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM4_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM4_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM4_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM4_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM4_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM4_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM4_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM4_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM4_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM4_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM4_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM4_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM4_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM4_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM4_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM4_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM4_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM4_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM4_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM4_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM4_BASE, EPWM_SOC_A, 1);	
    EPWM_setClockPrescaler(IRIS_EPWM5_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM5_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM5_BASE, 3000);	
    EPWM_setTimeBaseCounter(IRIS_EPWM5_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM5_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM5_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM5_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM5_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM5_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM5_BASE, EPWM_COUNTER_COMPARE_A, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM5_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM5_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM5_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM5_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM5_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM5_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM5_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM5_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM5_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM5_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM5_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM5_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM5_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM5_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM5_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM5_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM5_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM5_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM5_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM5_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM5_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM5_BASE, EPWM_SOC_A, 1);	
    EPWM_setClockPrescaler(IRIS_EPWM6_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_selectPeriodLoadEvent(IRIS_EPWM6_BASE, EPWM_SHADOW_LOAD_MODE_COUNTER_SYNC);	
    EPWM_setTimeBasePeriod(IRIS_EPWM6_BASE, 3000);	
    EPWM_setTimeBaseCounter(IRIS_EPWM6_BASE, 0);	
    EPWM_setTimeBaseCounterMode(IRIS_EPWM6_BASE, EPWM_COUNTER_MODE_UP_DOWN);	
    EPWM_setCountModeAfterSync(IRIS_EPWM6_BASE, EPWM_COUNT_MODE_UP_AFTER_SYNC);	
    EPWM_enablePhaseShiftLoad(IRIS_EPWM6_BASE);	
    EPWM_setPhaseShift(IRIS_EPWM6_BASE, 0);	
    EPWM_enableSyncOutPulseSource(IRIS_EPWM6_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM6_BASE, EPWM_COUNTER_COMPARE_A, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM6_BASE, EPWM_GL_REGISTER_CMPA_CMPAHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM6_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(IRIS_EPWM6_BASE, EPWM_COUNTER_COMPARE_B, 1500);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM6_BASE, EPWM_GL_REGISTER_CMPB_CMPBHR);	
    EPWM_setCounterCompareShadowLoadMode(IRIS_EPWM6_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_enableGlobalLoadRegisters(IRIS_EPWM6_BASE, EPWM_GL_REGISTER_AQCTLA_AQCTLA2);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(IRIS_EPWM6_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setDeadBandDelayPolarity(IRIS_EPWM6_BASE, EPWM_DB_FED, EPWM_DB_POLARITY_ACTIVE_LOW);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM6_BASE, EPWM_DB_RED, true);	
    EPWM_setRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM6_BASE, EPWM_RED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableRisingEdgeDelayCountShadowLoadMode(IRIS_EPWM6_BASE);	
    EPWM_setRisingEdgeDelayCount(IRIS_EPWM6_BASE, 50);	
    EPWM_setDeadBandDelayMode(IRIS_EPWM6_BASE, EPWM_DB_FED, true);	
    EPWM_setFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM6_BASE, EPWM_FED_LOAD_ON_CNTR_ZERO);	
    EPWM_disableFallingEdgeDelayCountShadowLoadMode(IRIS_EPWM6_BASE);	
    EPWM_setFallingEdgeDelayCount(IRIS_EPWM6_BASE, 50);	
    EPWM_enableInterrupt(IRIS_EPWM6_BASE);	
    EPWM_setInterruptSource(IRIS_EPWM6_BASE, EPWM_INT_TBCTR_PERIOD);	
    EPWM_setInterruptEventCount(IRIS_EPWM6_BASE, 1);	
    EPWM_enableADCTrigger(IRIS_EPWM6_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(IRIS_EPWM6_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_PERIOD);	
    EPWM_setADCTriggerEventPrescale(IRIS_EPWM6_BASE, EPWM_SOC_A, 1);	
}

//*****************************************************************************
//
// EQEP Configurations
//
//*****************************************************************************
void EQEP_init(){
	IRIS_EQEP1_init();
	IRIS_EQEP2_init();
}

void IRIS_EQEP1_init(){
	EQEP_SourceSelect source_IRIS_EQEP1 =
	{
		EQEP_SOURCE_DEVICE_PIN, 		// eQEPA source
		EQEP_SOURCE_DEVICE_PIN,		// eQEPB source
		EQEP_SOURCE_DEVICE_PIN,  	// eQEP Index source 
	};
	//
	// Selects the source for eQEPA/B/I signals
	//
	EQEP_selectSource(IRIS_EQEP1_BASE, source_IRIS_EQEP1);
	//
	// Set the strobe input source of the eQEP module.
	//
	EQEP_setStrobeSource(IRIS_EQEP1_BASE,EQEP_STROBE_FROM_GPIO);
	//
	// Sets the polarity of the eQEP module's input signals.
	//
	EQEP_setInputPolarity(IRIS_EQEP1_BASE,false,false,false,false);
	//
	// Configures eQEP module's quadrature decoder unit.
	//
	EQEP_setDecoderConfig(IRIS_EQEP1_BASE, (EQEP_CONFIG_QUADRATURE | EQEP_CONFIG_2X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	//
	// Set the emulation mode of the eQEP module.
	//
	EQEP_setEmulationMode(IRIS_EQEP1_BASE,EQEP_EMULATIONMODE_STOPIMMEDIATELY);
	//
	// Configures eQEP module position counter unit.
	//
	EQEP_setPositionCounterConfig(IRIS_EQEP1_BASE,EQEP_POSITION_RESET_IDX,10000U);
	//
	// Sets the current encoder position.
	//
	EQEP_setPosition(IRIS_EQEP1_BASE,0U);
	//
	// Disables the eQEP module unit timer.
	//
	EQEP_disableUnitTimer(IRIS_EQEP1_BASE);
	//
	// Disables the eQEP module watchdog timer.
	//
	EQEP_disableWatchdog(IRIS_EQEP1_BASE);
	//
	// Configures the quadrature modes in which the position count can be latched.
	//
	EQEP_setLatchMode(IRIS_EQEP1_BASE,(EQEP_LATCH_CNT_READ_BY_CPU|EQEP_LATCH_RISING_STROBE|EQEP_LATCH_RISING_INDEX));
	//
	// Set the quadrature mode adapter (QMA) module mode.
	//
	EQEP_setQMAModuleMode(IRIS_EQEP1_BASE,EQEP_QMA_MODE_BYPASS);
	//
	// Disable Direction Change During Index
	//
	EQEP_disableDirectionChangeDuringIndex(IRIS_EQEP1_BASE);
	//
	// Configures the mode in which the position counter is initialized.
	//
	EQEP_setPositionInitMode(IRIS_EQEP1_BASE,(EQEP_INIT_DO_NOTHING));
	//
	// Sets the software initialization of the encoder position counter.
	//
	EQEP_setSWPositionInit(IRIS_EQEP1_BASE,true);
	//
	// Sets the init value for the encoder position counter.
	//
	EQEP_setInitialPosition(IRIS_EQEP1_BASE,0U);
	//
	// Enables the eQEP module.
	//
	EQEP_enableModule(IRIS_EQEP1_BASE);
}
void IRIS_EQEP2_init(){
	EQEP_SourceSelect source_IRIS_EQEP2 =
	{
		EQEP_SOURCE_DEVICE_PIN, 		// eQEPA source
		EQEP_SOURCE_DEVICE_PIN,		// eQEPB source
		EQEP_SOURCE_DEVICE_PIN,  	// eQEP Index source 
	};
	//
	// Selects the source for eQEPA/B/I signals
	//
	EQEP_selectSource(IRIS_EQEP2_BASE, source_IRIS_EQEP2);
	//
	// Set the strobe input source of the eQEP module.
	//
	EQEP_setStrobeSource(IRIS_EQEP2_BASE,EQEP_STROBE_FROM_GPIO);
	//
	// Sets the polarity of the eQEP module's input signals.
	//
	EQEP_setInputPolarity(IRIS_EQEP2_BASE,false,false,false,false);
	//
	// Configures eQEP module's quadrature decoder unit.
	//
	EQEP_setDecoderConfig(IRIS_EQEP2_BASE, (EQEP_CONFIG_QUADRATURE | EQEP_CONFIG_2X_RESOLUTION | EQEP_CONFIG_NO_SWAP | EQEP_CONFIG_IGATE_DISABLE));
	//
	// Set the emulation mode of the eQEP module.
	//
	EQEP_setEmulationMode(IRIS_EQEP2_BASE,EQEP_EMULATIONMODE_STOPIMMEDIATELY);
	//
	// Configures eQEP module position counter unit.
	//
	EQEP_setPositionCounterConfig(IRIS_EQEP2_BASE,EQEP_POSITION_RESET_IDX,10000U);
	//
	// Sets the current encoder position.
	//
	EQEP_setPosition(IRIS_EQEP2_BASE,0U);
	//
	// Disables the eQEP module unit timer.
	//
	EQEP_disableUnitTimer(IRIS_EQEP2_BASE);
	//
	// Disables the eQEP module watchdog timer.
	//
	EQEP_disableWatchdog(IRIS_EQEP2_BASE);
	//
	// Configures the quadrature modes in which the position count can be latched.
	//
	EQEP_setLatchMode(IRIS_EQEP2_BASE,(EQEP_LATCH_CNT_READ_BY_CPU|EQEP_LATCH_RISING_STROBE|EQEP_LATCH_RISING_INDEX));
	//
	// Set the quadrature mode adapter (QMA) module mode.
	//
	EQEP_setQMAModuleMode(IRIS_EQEP2_BASE,EQEP_QMA_MODE_BYPASS);
	//
	// Disable Direction Change During Index
	//
	EQEP_disableDirectionChangeDuringIndex(IRIS_EQEP2_BASE);
	//
	// Configures the mode in which the position counter is initialized.
	//
	EQEP_setPositionInitMode(IRIS_EQEP2_BASE,(EQEP_INIT_DO_NOTHING));
	//
	// Sets the software initialization of the encoder position counter.
	//
	EQEP_setSWPositionInit(IRIS_EQEP2_BASE,true);
	//
	// Sets the init value for the encoder position counter.
	//
	EQEP_setInitialPosition(IRIS_EQEP2_BASE,0U);
	//
	// Enables the eQEP module.
	//
	EQEP_enableModule(IRIS_EQEP2_BASE);
}

//*****************************************************************************
//
// FSIRX Configurations
//
//*****************************************************************************
void FSIRX_init(){
	myBoardFSI0_FSIRX_init();
}

void myBoardFSI0_FSIRX_init(){
	//
	// Setting for requested nWords and nLanes with transfers
	//
	FSI_setRxSoftwareFrameSize(myBoardFSI0_FSIRX_BASE, 8);
	FSI_setRxDataWidth(myBoardFSI0_FSIRX_BASE, FSI_DATA_WIDTH_1_LANE);
	//
	// Configure for External Loopback
	//
	FSI_disableRxInternalLoopback(myBoardFSI0_FSIRX_BASE);
	//
	// Initialize Rx, reset sequence, clear events
	//
	FSI_performRxInitialization(myBoardFSI0_FSIRX_BASE);
}

//*****************************************************************************
//
// FSITX Configurations
//
//*****************************************************************************
void FSITX_init(){
	myBoardFSI0_FSITX_init();
}

void myBoardFSI0_FSITX_init(){
	//
	// Setting for requested nWords and nLanes with transfers
	// and desired frame configurations
	//
	FSI_setTxSoftwareFrameSize(myBoardFSI0_FSITX_BASE, 8);
	FSI_setTxDataWidth(myBoardFSI0_FSITX_BASE, FSI_DATA_WIDTH_1_LANE);
	FSI_setTxFrameTag(myBoardFSI0_FSITX_BASE, FSI_FRAME_TAG0);
	FSI_setTxFrameType(myBoardFSI0_FSITX_BASE, FSI_FRAME_TYPE_PING);
	//
	// Configure start of transmission mode
	//
	FSI_setTxStartMode(myBoardFSI0_FSITX_BASE, FSI_TX_START_FRAME_CTRL);
	//
	// Configure compute width for ECC
	//
	FSI_setTxECCComputeWidth(myBoardFSI0_FSITX_BASE, FSI_32BIT_ECC_COMPUTE);
	//
	// Initialize Tx, reset sequence, clear events
	//
	FSI_performTxInitialization(myBoardFSI0_FSITX_BASE, 4);
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	IRIS_GPIO1_init();
	IRIS_GPIO2_init();
	IRIS_GPIO3_init();
	IRIS_GPIO4_init();
	IRIS_GPIO5_init();
	IRIS_GPIO6_init();
	IRIS_LED1_init();
	IRIS_LED2_init();
	IRIS_GPIO_SPI_RST_init();
}

void IRIS_GPIO1_init(){
	GPIO_setPadConfig(IRIS_GPIO1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO1, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_GPIO1, GPIO_CORE_CPU1);
}
void IRIS_GPIO2_init(){
	GPIO_writePin(IRIS_GPIO2, 1);
	GPIO_setPadConfig(IRIS_GPIO2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_GPIO2, GPIO_CORE_CPU1);
}
void IRIS_GPIO3_init(){
	GPIO_writePin(IRIS_GPIO3, 1);
	GPIO_setPadConfig(IRIS_GPIO3, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO3, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO3, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_GPIO3, GPIO_CORE_CPU1);
}
void IRIS_GPIO4_init(){
	GPIO_setPadConfig(IRIS_GPIO4, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO4, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO4, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(IRIS_GPIO4, GPIO_CORE_CPU1);
}
void IRIS_GPIO5_init(){
	GPIO_setPadConfig(IRIS_GPIO5, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO5, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO5, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(IRIS_GPIO5, GPIO_CORE_CPU1);
}
void IRIS_GPIO6_init(){
	GPIO_setPadConfig(IRIS_GPIO6, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO6, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO6, GPIO_DIR_MODE_IN);
	GPIO_setControllerCore(IRIS_GPIO6, GPIO_CORE_CPU1);
}
void IRIS_LED1_init(){
	GPIO_setPadConfig(IRIS_LED1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_LED1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_LED1, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_LED1, GPIO_CORE_CPU1);
}
void IRIS_LED2_init(){
	GPIO_setPadConfig(IRIS_LED2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_LED2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_LED2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_LED2, GPIO_CORE_CPU1);
}
void IRIS_GPIO_SPI_RST_init(){
	GPIO_setPadConfig(IRIS_GPIO_SPI_RST, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(IRIS_GPIO_SPI_RST, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(IRIS_GPIO_SPI_RST, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(IRIS_GPIO_SPI_RST, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// I2C Configurations
//
//*****************************************************************************
void I2C_init(){
	IRIS_IIC_init();
}

void IRIS_IIC_init(){
	I2C_disableModule(IRIS_IIC_BASE);
	I2C_initController(IRIS_IIC_BASE, DEVICE_SYSCLK_FREQ, IRIS_IIC_BITRATE, I2C_DUTYCYCLE_50);
	I2C_setConfig(IRIS_IIC_BASE, I2C_CONTROLLER_SEND_MODE);
	I2C_disableLoopback(IRIS_IIC_BASE);
	I2C_setOwnAddress(IRIS_IIC_BASE, IRIS_IIC_OWN_ADDRESS);
	I2C_setTargetAddress(IRIS_IIC_BASE, IRIS_IIC_TARGET_ADDRESS);
	I2C_setBitCount(IRIS_IIC_BASE, I2C_BITCOUNT_8);
	I2C_setDataCount(IRIS_IIC_BASE, 0);
	I2C_setAddressMode(IRIS_IIC_BASE, I2C_ADDR_MODE_7BITS);
	I2C_enableFIFO(IRIS_IIC_BASE);
	I2C_setFIFOInterruptLevel(IRIS_IIC_BASE, I2C_FIFO_TX10, I2C_FIFO_RX10);
	I2C_setEmulationMode(IRIS_IIC_BASE, I2C_EMULATION_FREE_RUN);
	I2C_enableModule(IRIS_IIC_BASE);
}

//*****************************************************************************
//
// INPUTXBAR Configurations
//
//*****************************************************************************
void INPUTXBAR_init(){
	myINPUTXBARINPUT0_init();
	myINPUTXBARINPUT1_init();
}

void myINPUTXBARINPUT0_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT0_INPUT, myINPUTXBARINPUT0_SOURCE);
}
void myINPUTXBARINPUT1_init(){
	XBAR_setInputPin(INPUTXBAR_BASE, myINPUTXBARINPUT1_INPUT, myINPUTXBARINPUT1_SOURCE);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_IRIS_ADCA_1
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_IRIS_ADCA_1, &MainISR);
	Interrupt_enable(INT_IRIS_ADCA_1);
	
	// Interrupt Settings for INT_IRIS_CAN_0
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_IRIS_CAN_0, &INT_IRIS_CAN_0_ISR);
	Interrupt_enable(INT_IRIS_CAN_0);
	
	// Interrupt Settings for INT_IRIS_CAN_1
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_IRIS_CAN_1, &INT_IRIS_CAN_1_ISR);
	Interrupt_disable(INT_IRIS_CAN_1);
	
	// Interrupt Settings for INT_capsource
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_capsource, &INT_capsource_ISR);
	Interrupt_enable(INT_capsource);
	
	// Interrupt Settings for INT_capps
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_capps, &INT_capps_ISR);
	Interrupt_enable(INT_capps);
	
	// Interrupt Settings for INT_IRIS_UART_RS232_RX
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_IRIS_UART_RS232_RX, &INT_IRIS_UART_RS232_RX_ISR);
	Interrupt_disable(INT_IRIS_UART_RS232_RX);
	
	// Interrupt Settings for INT_IRIS_UART_USB_RX
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_IRIS_UART_USB_RX, &INT_IRIS_UART_USB_RX_ISR);
	Interrupt_enable(INT_IRIS_UART_USB_RX);
}
//*****************************************************************************
//
// OTHER Configurations
//
//*****************************************************************************
void OTHER_init(){
	//OTHER_PIN_DEFINITION initialization
	    
}
//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
void SCI_init(){
	IRIS_UART_RS232_init();
	IRIS_UART_USB_init();
}

void IRIS_UART_RS232_init(){
	SCI_clearInterruptStatus(IRIS_UART_RS232_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(IRIS_UART_RS232_BASE);
	SCI_resetTxFIFO(IRIS_UART_RS232_BASE);
	SCI_resetRxFIFO(IRIS_UART_RS232_BASE);
	SCI_resetChannels(IRIS_UART_RS232_BASE);
	SCI_setConfig(IRIS_UART_RS232_BASE, DEVICE_LSPCLK_FREQ, IRIS_UART_RS232_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(IRIS_UART_RS232_BASE);
	SCI_performSoftwareReset(IRIS_UART_RS232_BASE);
	SCI_enableInterrupt(IRIS_UART_RS232_BASE, SCI_INT_RXFF);
	SCI_setFIFOInterruptLevel(IRIS_UART_RS232_BASE, SCI_FIFO_TX0, SCI_FIFO_RX0);
	SCI_enableFIFO(IRIS_UART_RS232_BASE);
	SCI_enableModule(IRIS_UART_RS232_BASE);
}
void IRIS_UART_USB_init(){
	SCI_clearInterruptStatus(IRIS_UART_USB_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(IRIS_UART_USB_BASE);
	SCI_resetTxFIFO(IRIS_UART_USB_BASE);
	SCI_resetRxFIFO(IRIS_UART_USB_BASE);
	SCI_resetChannels(IRIS_UART_USB_BASE);
	SCI_setConfig(IRIS_UART_USB_BASE, DEVICE_LSPCLK_FREQ, IRIS_UART_USB_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(IRIS_UART_USB_BASE);
	SCI_performSoftwareReset(IRIS_UART_USB_BASE);
	SCI_enableInterrupt(IRIS_UART_USB_BASE, SCI_INT_RXFF);
	SCI_setFIFOInterruptLevel(IRIS_UART_USB_BASE, SCI_FIFO_TX0, SCI_FIFO_RX14);
	SCI_enableInterrupt(IRIS_UART_USB_BASE, SCI_INT_FE | SCI_INT_OE);
	SCI_enableFIFO(IRIS_UART_USB_BASE);
	SCI_enableModule(IRIS_UART_USB_BASE);
}

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
void SPI_init(){
	IRIS_SPI_FPGA_BRIDGE_init();
	IRIS_SPI_OUT_init();
}

void IRIS_SPI_FPGA_BRIDGE_init(){
	SPI_disableModule(IRIS_SPI_FPGA_BRIDGE_BASE);
	SPI_setConfig(IRIS_SPI_FPGA_BRIDGE_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
				  SPI_MODE_CONTROLLER, IRIS_SPI_FPGA_BRIDGE_BITRATE, IRIS_SPI_FPGA_BRIDGE_DATAWIDTH);
	SPI_setPTESignalPolarity(IRIS_SPI_FPGA_BRIDGE_BASE, SPI_PTE_ACTIVE_LOW);
	SPI_enableHighSpeedMode(IRIS_SPI_FPGA_BRIDGE_BASE);
	SPI_enableFIFO(IRIS_SPI_FPGA_BRIDGE_BASE);
	SPI_disableLoopback(IRIS_SPI_FPGA_BRIDGE_BASE);
	SPI_setEmulationMode(IRIS_SPI_FPGA_BRIDGE_BASE, SPI_EMULATION_FREE_RUN);
	SPI_enableModule(IRIS_SPI_FPGA_BRIDGE_BASE);
}
void IRIS_SPI_OUT_init(){
	SPI_disableModule(IRIS_SPI_OUT_BASE);
	SPI_setConfig(IRIS_SPI_OUT_BASE, DEVICE_LSPCLK_FREQ, SPI_PROT_POL0PHA0,
				  SPI_MODE_PERIPHERAL, IRIS_SPI_OUT_BITRATE, IRIS_SPI_OUT_DATAWIDTH);
	SPI_setPTESignalPolarity(IRIS_SPI_OUT_BASE, SPI_PTE_ACTIVE_LOW);
	SPI_enableFIFO(IRIS_SPI_OUT_BASE);
	SPI_setFIFOInterruptLevel(IRIS_SPI_OUT_BASE, SPI_FIFO_TXEMPTY, SPI_FIFO_RXEMPTY);
	SPI_disableLoopback(IRIS_SPI_OUT_BASE);
	SPI_setEmulationMode(IRIS_SPI_OUT_BASE, SPI_EMULATION_STOP_MIDWAY);
	SPI_enableModule(IRIS_SPI_OUT_BASE);
}

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************
void SYSCTL_init(){
	//
    // sysctl initialization
	//
    SysCtl_setStandbyQualificationPeriod(2);
    SysCtl_configureType(SYSCTL_ECAPTYPE, 0, 0);
    SysCtl_configureType(SYSCTL_SDFMTYPE, 0, 0);
    SysCtl_selectErrPinPolarity(0);

    SysCtl_disableMCD();


    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCC, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ADCC, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS1, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS2, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS3, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS3, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS3, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS3, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS4, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS4, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS4, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CMPSS4, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACB, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_DACB, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM1, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM2, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM3, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM3, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM3, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM3, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM4, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM4, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM4, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM4, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM5, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM5, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM5, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM5, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM6, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM6, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM6, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM6, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM7, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM7, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM7, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM7, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM8, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM8, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM8, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EPWM8, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP1, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP2, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_EQEP2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP1, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP2, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP3, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP3, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP3, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_ECAP3, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM1, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM2, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SDFM2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB1, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB1, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB1, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB2, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB2, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB2, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB3, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB3, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB3, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB4, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB4, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CLB4, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SCIB, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIB, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_SPIB, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_I2CB, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_PMBUSA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_PMBUSA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_PMBUSA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_PMBUSA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINB, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINB, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINB, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_LINB, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CANA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CANA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_CANA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_MCANA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_MCANA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_MCANA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIATX, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIATX, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIATX, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIATX, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIARX, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIARX, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIARX, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_FSIARX, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HRPWMA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HRPWMA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HRPWMA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HRPWMA, 
        SYSCTL_ACCESS_HIC, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HICA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HICA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_HICA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_AESA, 
        SYSCTL_ACCESS_CPU1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_AESA, 
        SYSCTL_ACCESS_CLA1, SYSCTL_ACCESS_FULL);
    SysCtl_setPeripheralAccessControl(SYSCTL_ACCESS_AESA, 
        SYSCTL_ACCESS_DMA1, SYSCTL_ACCESS_FULL);

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CPUBGCRC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLA1BGCRC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_HRCAL);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ERAD);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM5);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM6);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM7);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM8);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SD1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SD2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CANA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_MCANA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLB4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_FSITXA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_FSIRXA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_LINA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_LINB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_PMBUSA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DCC1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_HICA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_AESA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPG1);



}

