
//
// THIS IS A DEMO SOURCE CODE FOR GMP LIBRARY.
//
// User should add all necessary GMP config macro in this file.
//
// WARNING: This file must be kept in the include search path during compilation.
//

#ifndef _FILE_XPLT_PERIPHERAL_H_
#define _FILE_XPLT_PERIPHERAL_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <gmp_core.h>

// controller settings
#include "ctrl_settings.h"

// select ADC PTR interface
#include <ctl/component/interface/adc_ptr_channel.h>

// my added path
#include <ctl/component/interface/adc_channel.h>
#include <ctl/component/intrinsic/discrete/discrete_filter.h>

//=================================================================================================
// definitions of peripheral

// inverter side voltage feedback
extern tri_ptr_adc_channel_t uuvw;
extern adc_gt uuvw_src[3];

// inverter side current feedback
extern tri_ptr_adc_channel_t iuvw;
extern adc_gt iuvw_src[3];

// grid side voltage feedback
extern tri_ptr_adc_channel_t vabc;
extern adc_gt vabc_src[3];

// grid side current feedback
extern tri_ptr_adc_channel_t iabc;
extern adc_gt iabc_src[3];

// DC bus current & voltage feedback
extern ptr_adc_channel_t udc;
extern adc_gt udc_src;
extern ptr_adc_channel_t idc;
extern adc_gt idc_src;

// eCAP phase measurement
extern volatile uint32_t capsource_count;
extern volatile uint32_t capps_count;
extern volatile uint16_t capsource_ready;
extern volatile uint16_t capps_ready;

extern int32_t ecap_offset_count;
extern int32_t phase_delta_count;
extern uint32_t phase_period_count;
extern float phase_deg;
extern uint16_t phase_display_deg;
extern uint16_t phase_alarm_enable;
extern uint16_t phase_alarm_state;

// AD test signal processing
extern adc_gt sin_source;
extern adc_gt sin_fs;
extern adc_channel_t adc_sin_source;
extern adc_channel_t adc_sin_fs;
extern ctrl_gt dac_result;
extern ctl_filter_IIR1_t sin_source_hpf;
extern ctl_filter_IIR1_t sin_fs_hpf;

void reset_controller(void);

uint16_t SPI_readReg(uint16_t addr);
void SPI_writeReg(uint16_t addr, uint16_t data);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _FILE_PERIPHERAL_H_
