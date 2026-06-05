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


// periodic callback function things.
GMP_STATIC_INLINE void ctl_dispatch(void)
{
    float32_t dc_mv_x10;

    ctrl_gt sin_source_ac =
    ctl_step_filter_iir1(&sin_source_hpf, adc_sin_source.control_port.value);

    ctrl_gt sin_fs_ac =
    ctl_step_filter_iir1(&sin_fs_hpf, adc_sin_fs.control_port.value);

    adc_product_raw = sin_source_ac * sin_fs_ac;
    adc_product_dc = ctl_step_filter_iir1(&adc_product_lpf, adc_product_raw);

    dc_mv_x10 = adc_product_dc * 3.3f * 3.3f * 10000.0f;
    if (dc_mv_x10 >= 0.0f)
    {
        dc_mv_x10 += 0.5f;
    }
    else
    {
        dc_mv_x10 -= 0.5f;
    }

    if (dc_mv_x10 > 999.0f)
    {
        adc_product_dc_mv_x10 = 999;
    }
    else if (dc_mv_x10 < -999.0f)
    {
        adc_product_dc_mv_x10 = -999;
    }
    else
    {
        adc_product_dc_mv_x10 = (int16_t)dc_mv_x10;
    }

    dac_result=50.0f*(sin_source_ac * sin_fs_ac);
}

#ifdef __cplusplus
}
#endif // _cplusplus

#endif // _FILE_CTL_MAIN_H_
