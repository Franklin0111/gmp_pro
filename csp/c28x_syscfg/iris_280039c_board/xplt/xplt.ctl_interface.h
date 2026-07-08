//
// THIS IS A DEMO SOURCE CODE FOR GMP LIBRARY.
//
// User should add all declarations of controller objects in this file.
//
// User should implement the Main ISR of the controller tasks.
//
// User should ensure that all the controller codes here is platform-independent.
//
// WARNING: This file must be kept in the include search path during compilation.
//

#include <xplt.peripheral.h>

#ifndef _FILE_CTL_INTERFACE_H_
#define _FILE_CTL_INTERFACE_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//=================================================================================================
// Controller interface

#define PSU_DAC_MAX_CODE 4095.0f
#define PSU_DAC_V_FULL_SCALE 10.0f
#define PSU_DAC_I_FULL_SCALE 100.0f
#define PSU_ADC_MAX_CODE 4095.0f
#define PSU_ADC_V_FULL_SCALE 12.0f
#define PSU_ADC_I_FULL_SCALE 120.0f

GMP_STATIC_INLINE uint16_t psu_dac_norm_to_code(float32_t value)
{
    float32_t code;

    if (value < 0.0f)
        value = 0.0f;
    else if (value > 1.0f)
        value = 1.0f;

    code = value * PSU_DAC_MAX_CODE + 0.5f;

    return (uint16_t)code;
}

GMP_STATIC_INLINE float32_t psu_adc_code_to_value(uint16_t code, float32_t full_scale)
{
    if (code > 4095U)
        code = 4095U;

    return ((float32_t)code * full_scale) / PSU_ADC_MAX_CODE;
}

GMP_STATIC_INLINE void psu_trip_fault(psu_fault_t fault)
{
    psu_state = PSU_STATE_FAULT;
    psu_fault = fault;
    GPIO_writePin(IRIS_GPIO1, 1U);
}

// Input Callback
GMP_STATIC_INLINE void ctl_input_callback(void)
{
    uint16_t v_code;
    uint16_t i_code;

    v_code = ADC_readResult(ADC_CH1_RESULT_BASE, ADC_CH1);
    i_code = ADC_readResult(ADC_CH3_RESULT_BASE, ADC_CH3);

    psu_v_meas = psu_adc_code_to_value(v_code, PSU_ADC_V_FULL_SCALE);
    psu_i_meas = psu_adc_code_to_value(i_code, PSU_ADC_I_FULL_SCALE);

    if (psu_state == PSU_STATE_ON)
    {
        if ((psu_mode == PSU_MODE_CV) && (psu_i_meas > psu_oc_limit))
            psu_trip_fault(PSU_FAULT_OVERCURRENT);
        else if ((psu_mode == PSU_MODE_CC) && (psu_v_meas > psu_ov_limit))
            psu_trip_fault(PSU_FAULT_OVERVOLTAGE);
        else if (psu_mode == PSU_MODE_AUTO)
        {
            if (psu_i_meas > psu_oc_limit)
                psu_trip_fault(PSU_FAULT_OVERCURRENT);
            else if (psu_v_meas > psu_ov_limit)
                psu_trip_fault(PSU_FAULT_OVERVOLTAGE);
        }
    }
}

// Output Callback
GMP_STATIC_INLINE void ctl_output_callback(void)
{
    float32_t v_norm;
    float32_t i_norm;
    uint16_t relay_on;
    static uint16_t last_relay_on = 0xFFFFU;

    EPWM_setCounterCompareValue(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1500);

    if (psu_state == PSU_STATE_ON)
    {
        v_norm = psu_v_set / PSU_DAC_V_FULL_SCALE;
        i_norm = psu_i_set / PSU_DAC_I_FULL_SCALE;
        relay_on = 1U;
    }
    else
    {
        v_norm = 0.0f;
        i_norm = 0.0f;
        relay_on = 0U;
    }

    if (relay_on != last_relay_on)
    {
        GPIO_writePin(IRIS_GPIO6, relay_on);
        last_relay_on = relay_on;
    }

    DAC_setShadowValue(IRIS_DACA_BASE, psu_dac_norm_to_code(v_norm));
    DAC_setShadowValue(IRIS_DACB_BASE, psu_dac_norm_to_code(i_norm));

}

// function prototype
void GPIO_WritePin(uint16_t gpioNumber, uint16_t outVal);

// Enable Motor Controller
// Enable Output
GMP_STATIC_INLINE void ctl_fast_enable_output()
{
    // Clear any Trip Zone flag
    EPWM_clearTripZoneFlag(PHASE_U_BASE, EPWM_TZ_FORCE_EVENT_OST);
    EPWM_clearTripZoneFlag(PHASE_V_BASE, EPWM_TZ_FORCE_EVENT_OST);
    EPWM_clearTripZoneFlag(PHASE_W_BASE, EPWM_TZ_FORCE_EVENT_OST);
}

// Disable Output
GMP_STATIC_INLINE void ctl_fast_disable_output()
{
    // Disables the PWM device
    EPWM_forceTripZoneEvent(PHASE_U_BASE, EPWM_TZ_FORCE_EVENT_OST);
    EPWM_forceTripZoneEvent(PHASE_V_BASE, EPWM_TZ_FORCE_EVENT_OST);
    EPWM_forceTripZoneEvent(PHASE_W_BASE, EPWM_TZ_FORCE_EVENT_OST);
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _FILE_CTL_INTERFACE_H_
