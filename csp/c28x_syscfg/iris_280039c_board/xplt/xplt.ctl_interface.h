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

// Input Callback
GMP_STATIC_INLINE void ctl_input_callback(void)
{

}

// Output Callback
GMP_STATIC_INLINE void ctl_output_callback(void)
{
    float32_t v_norm;
    float32_t i_norm;

    EPWM_setCounterCompareValue(IRIS_EPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1500);

    if (psu_state == PSU_STATE_ON)
    {
        v_norm = psu_v_set / PSU_DAC_V_FULL_SCALE;
        i_norm = psu_i_set / PSU_DAC_I_FULL_SCALE;
    }
    else
    {
        v_norm = 0.0f;
        i_norm = 0.0f;
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
