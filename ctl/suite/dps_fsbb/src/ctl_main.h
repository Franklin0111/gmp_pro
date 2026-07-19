/**
 * @file ctl_main.h
 * @brief Top-level controller interface for the four-switch buck-boost converter.
 */

#ifndef _FILE_CTRL_MAIN_H_
#define _FILE_CTRL_MAIN_H_

#ifndef SDPE_FSBB_SETTINGS_HEADER
#define SDPE_FSBB_SETTINGS_HEADER <sdpe_dps_fsbb_iris_settings.h>
#endif
#include SDPE_FSBB_SETTINGS_HEADER
#include <core/pm/function_scheduler.h>
#include <core/dev/pil_core.h>
#include <ctl/framework/cia402_state_machine.h>
#include <ctl/component/interface/adc_channel.h>
#include <ctl/component/digital_power/dcdc/dcdc_core.h>
#include <ctl/component/digital_power/dcdc/fsbb.h>

#ifdef __cplusplus
extern "C"
{
#endif

extern cia402_sm_t cia402_sm;
extern ctl_dcdc_core_t dcdc_core;
extern ctl_pid_t iout_outer_pid;

extern adc_channel_t adc_v_in;
extern adc_channel_t adc_v_out;
extern adc_channel_t adc_i_L;
extern adc_channel_t adc_i_load;
extern fsbb_modulator_t fsbb_mod;

extern adc_bias_calibrator_t adc_calibrator;
extern volatile fast_gt flag_enable_adc_calibrator;
extern volatile fast_gt index_adc_calibrator;

extern ctrl_gt g_v_out_ref_user;
extern ctrl_gt g_i_limit_user;
extern ctrl_gt g_i_out_ref_user;
extern ctrl_gt g_iout_inner_ref;

/** 4096-sample average of the filtered output-voltage feedback, in volts. */
extern volatile float g_vout_filtered_avg_v;
extern ctrl_gt v_req;

typedef enum _tag_fsbb_regulation_mode
{
    FSBB_REGULATION_CV_CASCADE = 0,
    FSBB_REGULATION_CC_OUTPUT = 1
} fsbb_regulation_mode_t;

extern volatile fsbb_regulation_mode_t g_fsbb_regulation_mode;

/** Execute IOUT outer loop -> IL inner loop cascade control. */
GMP_STATIC_INLINE ctrl_gt ctl_step_fsbb_iout_cascade(ctl_dcdc_core_t* core)
{
    ctl_dcdc_internal_ingest_and_filter(core);

    /* Outer loop: regulated load/output current -> inductor-current reference. */
    core->i_ramp_ref = ctl_step_slope_limiter(&core->ramp_i, core->i_target);
    g_iout_inner_ref = ctl_step_pid_ser(&iout_outer_pid,
                                        core->i_ramp_ref - core->filter_i_load.out);

    /* Inner loop: inductor-current reference -> synthesized voltage command. */
    core->v_out_formal = ctl_step_pid_ser(&core->current_pid,
                                          g_iout_inner_ref - core->filter_i_L.out);
    core->v_out_formal = ctl_sat(core->v_out_formal, core->out_max, core->out_min);
    core->is_current_dominant = 1;
    return core->v_out_formal;
}

typedef enum _tag_fsbb_fault
{
    FSBB_FAULT_NONE = 0,
    FSBB_FAULT_VIN_UNDERVOLTAGE = 1U << 0,
    FSBB_FAULT_VIN_OVERVOLTAGE = 1U << 1,
    FSBB_FAULT_VOUT_OVERVOLTAGE = 1U << 2,
    FSBB_FAULT_IL_POSITIVE_OVERCURRENT = 1U << 3,
    FSBB_FAULT_IL_NEGATIVE_OVERCURRENT = 1U << 4,
    FSBB_FAULT_IOUT_OVERCURRENT = 1U << 5
} fsbb_fault_t;

extern volatile uint16_t g_fsbb_faults;
extern volatile fast_gt g_fsbb_output_enabled;

void ctl_init(void);
void ctl_mainloop(void);
void ctl_enable_pwm(void);
void ctl_disable_pwm(void);
void clear_all_controllers(void);
void ctl_update_vout_filtered_average(void);
gmp_task_status_t tsk_protect(gmp_task_t* tsk);

/** Execute one control sample after the platform input callback has run. */
GMP_STATIC_INLINE void ctl_dispatch(void)
{
#if defined SPECIFY_ENABLE_ADC_CALIBRATE
    if (flag_enable_adc_calibrator)
    {
        if (index_adc_calibrator == 0)
            ctl_step_adc_calibrator(&adc_calibrator, adc_i_L.control_port.value);
#if defined FSBB_ENABLE_IOUT_SAMPLE
        else if (index_adc_calibrator == 1)
            ctl_step_adc_calibrator(&adc_calibrator, adc_i_load.control_port.value);
#endif
        return;
    }
#endif

    if (g_fsbb_faults != FSBB_FAULT_NONE)
        return;

#if (BUILD_LEVEL == 1)
    dcdc_core.mode = CTL_DCDC_MODE_OPENLOOP;
    dcdc_core.v_target = float2ctrl(FSBB_OPEN_LOOP_VOLTAGE_COMMAND / CTRL_VOLTAGE_BASE);
    v_req = ctl_step_dcdc_open_loop(&dcdc_core);
#elif (BUILD_LEVEL == 2)
    dcdc_core.mode = CTL_DCDC_MODE_CURRENTLOOP;
    dcdc_core.i_target = ctl_sat(g_i_limit_user,
                                 float2ctrl(FSBB_OUTPUT_CURRENT_LIM / CTRL_CURRENT_BASE),
                                 float2ctrl(0.0f));
    v_req = ctl_step_dcdc_current_loop(&dcdc_core);
#elif (BUILD_LEVEL == 3)
    {
        if (g_fsbb_regulation_mode == FSBB_REGULATION_CC_OUTPUT)
        {
            /* IOUT outer loop -> IL inner loop cascade. */
            ctrl_gt inner_i_limit = ctl_sat(g_i_limit_user,
                                             float2ctrl(FSBB_OUTPUT_CURRENT_LIM / CTRL_CURRENT_BASE),
                                             float2ctrl(0.0f));
            dcdc_core.mode = CTL_DCDC_MODE_CURRENTLOOP;
            dcdc_core.i_target = ctl_sat(g_i_out_ref_user,
                                         float2ctrl(FSBB_OUTPUT_CURRENT_LIM / CTRL_CURRENT_BASE),
                                         float2ctrl(0.0f));
            ctl_set_pid_limit(&iout_outer_pid, inner_i_limit, float2ctrl(0.0f));
            ctl_set_pid_int_limit(&iout_outer_pid, inner_i_limit, float2ctrl(0.0f));
            v_req = ctl_step_fsbb_iout_cascade(&dcdc_core);
            v_req = ctl_sat(v_req,
                            ctl_sat(g_v_out_ref_user,
                                    float2ctrl(FSBB_OUTPUT_VOLTAGE_MAX / CTRL_VOLTAGE_BASE),
                                    float2ctrl(FSBB_OUTPUT_VOLTAGE_MIN / CTRL_VOLTAGE_BASE)),
                            float2ctrl(0.0f));
        }
        else
        {
            ctrl_gt current_limit = ctl_sat(g_i_limit_user,
                                            float2ctrl(FSBB_OUTPUT_CURRENT_LIM / CTRL_CURRENT_BASE),
                                            float2ctrl(0.0f));
            dcdc_core.mode = CTL_DCDC_MODE_VOLTAGELOOP;
            dcdc_core.v_target = ctl_sat(g_v_out_ref_user,
                                         float2ctrl(FSBB_OUTPUT_VOLTAGE_MAX / CTRL_VOLTAGE_BASE),
                                         float2ctrl(FSBB_OUTPUT_VOLTAGE_MIN / CTRL_VOLTAGE_BASE));
            ctl_set_pid_limit(&dcdc_core.voltage_pid, current_limit, float2ctrl(0.0f));
            ctl_set_pid_int_limit(&dcdc_core.voltage_pid, current_limit, float2ctrl(0.0f));
            v_req = ctl_step_dcdc_cascade(&dcdc_core);
        }
    }
#endif

    /* Update the slow debug/commissioning average after the ADC filters run. */
    ctl_update_vout_filtered_average();

    ctl_step_fsbb_modulator(&fsbb_mod, v_req, adc_v_in.control_port.value);
}

#ifdef __cplusplus
}
#endif

#endif // _FILE_CTRL_MAIN_H_
