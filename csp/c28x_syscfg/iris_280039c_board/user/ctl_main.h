/**
 * @file ctl_main.cpp
 * @author Javnson (javnson@zju.edu.cn)
 * @brief
 * @version 0.1
 * @date 2024-09-30
 *
 * @copyright Copyright GMP(c) 2024
 *
 */

#include <xplt.peripheral.h>

//=================================================================================================
// include Necessary control modules

#include <ctl/component/interface/adc_channel.h>
#include <ctl/component/interface/pwm_channel.h>
#include <ctl/component/interface/spwm_modulator.h>

#include <ctl/framework/cia402_state_machine.h>

#ifndef _FILE_CTL_MAIN_H_
#define _FILE_CTL_MAIN_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

//=================================================================================================
// controller modules with extern



//=================================================================================================
// function prototype
void clear_all_controllers();

//=================================================================================================
// controller process

#define ADC_PRODUCT_GAIN       50.0f
#define DAC_OUTPUT_BIAS_MV   1650.0f
#define DAC_OUTPUT_SCALE_MV  1650.0f


// periodic callback function things.
GMP_STATIC_INLINE void ctl_dispatch(void)
{
    float32_t output_dc_mv;

    ctrl_gt sin_source_ac =
    ctl_step_filter_iir1(&sin_source_hpf, adc_sin_source.control_port.value);

    ctrl_gt sin_fs_ac =
    ctl_step_filter_iir1(&sin_fs_hpf, adc_sin_fs.control_port.value);

    adc_product_raw = sin_source_ac * sin_fs_ac;
    adc_product_dc = ctl_step_filter_iir1(&adc_product_lpf, adc_product_raw);

    output_dc_mv = DAC_OUTPUT_BIAS_MV + adc_product_dc * ADC_PRODUCT_GAIN * DAC_OUTPUT_SCALE_MV;

    if (output_dc_mv > 3300.0f)
    {
        adc_product_output_mv = 3300U;
    }
    else if (output_dc_mv < 0.0f)
    {
        adc_product_output_mv = 0U;
    }
    else
    {
        adc_product_output_mv = (uint16_t)(output_dc_mv + 0.5f);
    }

    dac_result = ADC_PRODUCT_GAIN * adc_product_raw;
}

#ifdef __cplusplus
}
#endif // _cplusplus

#endif // _FILE_CTL_MAIN_H_
