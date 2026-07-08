
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

// programmable power supply state
typedef enum
{
    PSU_STATE_OFF = 0,
    PSU_STATE_ON,
    PSU_STATE_FAULT
} psu_state_t;

typedef enum
{
    PSU_MODE_CV = 0,
    PSU_MODE_CC,
    PSU_MODE_AUTO
} psu_mode_t;

typedef enum
{
    PSU_EDIT_VOLTAGE = 0,
    PSU_EDIT_CURRENT,
    PSU_EDIT_OV_LIMIT,
    PSU_EDIT_OC_LIMIT,
    PSU_EDIT_MODE
} psu_edit_target_t;

typedef enum
{
    PSU_FAULT_NONE = 0,
    PSU_FAULT_OVERVOLTAGE,
    PSU_FAULT_OVERCURRENT
} psu_fault_t;

extern volatile psu_state_t psu_state;
extern volatile psu_mode_t psu_mode;
extern volatile psu_edit_target_t psu_edit_target;
extern volatile psu_fault_t psu_fault;

extern volatile float32_t psu_v_set;
extern volatile float32_t psu_i_set;
extern volatile float32_t psu_ov_limit;
extern volatile float32_t psu_oc_limit;
extern volatile float32_t psu_v_meas;
extern volatile float32_t psu_i_meas;

void reset_controller(void);

uint16_t SPI_readReg(uint16_t addr);
void SPI_writeReg(uint16_t addr, uint16_t data);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _FILE_PERIPHERAL_H_
