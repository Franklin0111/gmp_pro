// This is the example of user main.

// GMP basic core header
#include <gmp_core.h>

// user main header
#include "ctl_main.h"
#include "user_main.h"
#include <stdlib.h>

#include <core/dev/pil_core.h>
#include <core/dev/tunable.h>
#include <core/dev/mem_presp.h>


ctrl_gt kp, ki, kd;

ctrl_gt ram_range[512];

//=================================================================================================
// Datalink protocol online Debug module

gmp_datalink_t dl;

//
// PIL (processor in loop module)
//
gmp_pil_sim_t pil;

//
// Tunable Dictionary
//
const gmp_param_item_t dict_m1[] = {
    {&kp, GMP_PARAM_TYPE_F32, GMP_PARAM_PERM_RO},
    {&ki, GMP_PARAM_TYPE_F32, GMP_PARAM_PERM_RW},
    {&kd, GMP_PARAM_TYPE_F32, GMP_PARAM_PERM_RW},
};
const uint16_t var_tunable_count = sizeof(dict_m1) / sizeof(dict_m1[0]);
gmp_param_tunable_t tunable;

//
// Memory perspective Dictionary
//
const gmp_mem_region_t mem_regions[] = {
    {.base_addr = &ram_range, .byte_length = sizeof(ram_range) * GMP_PORT_DATA_SIZE_PER_BYTES, .perm = GMP_MEM_PERM_RW},
};
const uint16_t mem_regions_count = sizeof(mem_regions) / sizeof(mem_regions[0]);
gmp_mem_persp_t mem_persp_server;

//
// Datalink protocol stack task
//
gmp_task_status_t tsk_dl_debug_device(gmp_task_t* tsk)
{
    GMP_UNUSED_VAR(tsk);

    flush_dl_rx_buffer();

    // In PC simulation environment the DL protocol module is disabled.
#ifndef SPECIFY_PC_ENVIRONMENT

    gmp_dl_event_t e = gmp_dev_dl_loop_cb(&dl);

    switch (e)
    {
    //
    // if TX data is ready, do transmit
    //
    case GMP_DL_EVENT_TX_RDY:

        // send tx buffer message
        flush_dl_tx_buffer();

        // ack TX state machine.
        gmp_dev_dl_tx_state_done(&dl);
        break;

    case GMP_DL_EVENT_RX_OK:

        //
        // Ack PIL simulation message
        //
        if (gmp_pil_sim_rx_cb(&pil))
            break;

        //
        // Ack parameter tunable message
        //
        if (gmp_param_tunable_rx_cb(&tunable))
            break;

        //
        // Ack memory perspective message
        //
        if (gmp_mem_persp_rx_cb(&mem_persp_server))
            break;

        //
        // Echo Command
        //
        if (dl.rx_head.cmd == 0x99)
        {
            // echo payload_buf
            gmp_dev_dl_tx_request(&dl, dl.rx_head.seq_id, GMP_DL_CMD_ECHO, dl.expected_payload_len, dl.payload_buf);

            // ack this message
            gmp_dev_dl_msg_handled(&dl);

            break;
        }

        // default handler
        gmp_dev_dl_default_rx_handler(&dl);

        break;
    }

#endif // SPECIFY_PC_ENVIRONMENT

    return GMP_TASK_DONE;
}


//=================================================================================================
// task manager

// GPIO
gpio_halt user_led;

#define PHASE_ALARM_NONE  0U
#define PHASE_ALARM_LOWER 1U
#define PHASE_ALARM_UPPER 2U

#define PHASE_PERIOD_TOLERANCE_PERCENT 15U
#define PHASE_CHANNEL_TOLERANCE_PERCENT 10U
#define PHASE_JUMP_LIMIT_DEG 10.0f
#define PHASE_JUMP_CONFIRM_TOLERANCE_DEG 3.0f
#define PHASE_JUMP_CONFIRM_COUNT 3U

#define LED_LUT_MINUS 20U
#define LED_LUT_DP_MASK 0x80U
#define LED_LUT_BLANK 22U

gmp_task_status_t tsk_blink(gmp_task_t* tsk)
{
    GMP_UNUSED_VAR(tsk);

    gmp_base_print(TEXT_STRING("Hello World!\r\n"));

    static fast_gt led_stat = 0;
    if (led_stat == 0)
    {
        led_stat = 1;
        gmp_hal_gpio_write(user_led, 0);
    }
    else
    {
        led_stat = 0;
        gmp_hal_gpio_write(user_led, 1);
    }

    return GMP_TASK_DONE;
}

static uint16_t phase_abs_round_deg(float deg)
{
    int16_t rounded_deg;

    if (deg >= 0.0f)
    {
        rounded_deg = (int16_t)(deg + 0.5f);
    }
    else
    {
        rounded_deg = (int16_t)(deg - 0.5f);
        rounded_deg = (int16_t)(-rounded_deg);
    }

    if (rounded_deg > 999)
    {
        rounded_deg = 999;
    }

    return (uint16_t)rounded_deg;
}

static float phase_abs_float(float value)
{
    return (value >= 0.0f) ? value : -value;
}

static uint16_t phase_periods_are_valid(uint32_t source_period, uint32_t fs_period)
{
    uint32_t reference = phase_period_count;
    uint32_t period_min = reference * (100U - PHASE_PERIOD_TOLERANCE_PERCENT) / 100U;
    uint32_t period_max = reference * (100U + PHASE_PERIOD_TOLERANCE_PERCENT) / 100U;
    uint32_t channel_difference = (source_period >= fs_period) ?
                                  (source_period - fs_period) : (fs_period - source_period);
    uint32_t channel_tolerance = reference * PHASE_CHANNEL_TOLERANCE_PERCENT / 100U;

    return (source_period >= period_min) && (source_period <= period_max) &&
           (fs_period >= period_min) && (fs_period <= period_max) &&
           (channel_difference <= channel_tolerance);
}

gmp_task_status_t tsk_phase_update(gmp_task_t* tsk)
{
    static float pending_phase_deg = 0.0f;
    static uint16_t pending_phase_count = 0U;

    GMP_UNUSED_VAR(tsk);

    if (capsource_ready && capps_ready)
    {
        int32_t raw_delta = (int32_t)(capps_count - capsource_count);
        int32_t period_count = (int32_t)phase_period_count;

        if (phase_periods_are_valid(capsource_period_count, capps_period_count))
        {
            uint32_t period_count_avg = (capsource_period_count + capps_period_count) / 2U;
            float candidate_phase_deg;
            int32_t half_period_count;

            phase_period_count = (phase_period_count * 7U + period_count_avg + 4U) / 8U;
            period_count = (int32_t)phase_period_count;
            half_period_count = period_count / 2;
            phase_delta_count = raw_delta - ecap_offset_count;

            while (phase_delta_count > half_period_count)
            {
                phase_delta_count -= period_count;
            }
            while (phase_delta_count < -half_period_count)
            {
                phase_delta_count += period_count;
            }

            candidate_phase_deg = ((float)phase_delta_count / (float)period_count) * 360.0f;

            if (phase_abs_float(candidate_phase_deg - phase_deg) <= PHASE_JUMP_LIMIT_DEG)
            {
                phase_deg = candidate_phase_deg;
                pending_phase_count = 0U;
            }
            else if (phase_abs_float(candidate_phase_deg - pending_phase_deg) <=
                     PHASE_JUMP_CONFIRM_TOLERANCE_DEG)
            {
                pending_phase_count++;
                if (pending_phase_count >= PHASE_JUMP_CONFIRM_COUNT)
                {
                    phase_deg = candidate_phase_deg;
                    pending_phase_count = 0U;
                }
            }
            else
            {
                pending_phase_deg = candidate_phase_deg;
                pending_phase_count = 1U;
            }

            phase_display_deg = phase_abs_round_deg(phase_deg);
        }

        capsource_ready = 0;
        capps_ready = 0;

        ECAP_reArm(capsource_BASE);
        ECAP_reArm(capps_BASE);
    }

    return GMP_TASK_DONE;
}

static uint16_t adc_product_abs_mv_x10(void)
{
    if (adc_product_dc_mv_x10 < 0)
    {
        return (uint16_t)(-adc_product_dc_mv_x10);
    }

    return (uint16_t)adc_product_dc_mv_x10;
}

static void adc_product_display_segments(uint16_t* ch5, uint16_t* ch6, uint16_t* ch7, uint16_t* ch8)
{
    uint16_t abs_mv_x10 = adc_product_abs_mv_x10();
    uint16_t integer_part;
    uint16_t tenth_part;

    *ch5 = led_lut[LED_LUT_BLANK];

    if (adc_product_dc_mv_x10 < 0)
    {
        *ch5 = led_lut[LED_LUT_MINUS];
    }

    if (abs_mv_x10 > 999U)
    {
        abs_mv_x10 = 999U;
    }

    integer_part = abs_mv_x10 / 10U;
    tenth_part = abs_mv_x10 % 10U;

    if (integer_part >= 10U)
    {
        *ch6 = led_lut[integer_part / 10U];
    }
    else
    {
        *ch6 = led_lut[LED_LUT_BLANK];
    }

    *ch7 = (uint16_t)(led_lut[integer_part % 10U] | LED_LUT_DP_MASK);
    *ch8 = led_lut[tenth_part];
}

static void phase_display_blank(ht16k33_dev_t* dev)
{
    uint16_t dc_ch5;
    uint16_t dc_ch6;
    uint16_t dc_ch7;
    uint16_t dc_ch8;

    adc_product_display_segments(&dc_ch5, &dc_ch6, &dc_ch7, &dc_ch8);

    update_led_content_8byte(dev, led_lut[LED_LUT_BLANK], led_lut[LED_LUT_BLANK], led_lut[LED_LUT_BLANK],
                             led_lut[LED_LUT_BLANK], dc_ch5, dc_ch6, dc_ch7, dc_ch8);
}

static void phase_display_value(ht16k33_dev_t* dev, uint16_t deg)
{
    uint16_t dc_ch5;
    uint16_t dc_ch6;
    uint16_t dc_ch7;
    uint16_t dc_ch8;

    if (deg > 999U)
    {
        deg = 999U;
    }

    adc_product_display_segments(&dc_ch5, &dc_ch6, &dc_ch7, &dc_ch8);

    update_led_content_8byte(dev, led_lut[deg / 100U], led_lut[(deg / 10U) % 10U], led_lut[deg % 10U],
                             led_lut[LED_LUT_BLANK], dc_ch5, dc_ch6, dc_ch7, dc_ch8);
}

gmp_task_status_t tsk_phase_display(gmp_task_t* tsk)
{
    ht16k33_dev_t* dev = (ht16k33_dev_t*)tsk->user_data;
    static uint16_t blink_state = 0;

    if (phase_alarm_state != PHASE_ALARM_NONE)
    {
        blink_state = (uint16_t)!blink_state;

        if (blink_state)
        {
            phase_display_value(dev, phase_display_deg);
        }
        else
        {
            phase_display_blank(dev);
        }
    }
    else
    {
        blink_state = 0;
        phase_display_value(dev, phase_display_deg);
    }

    return GMP_TASK_DONE;
}

gmp_task_status_t tsk_phase_alarm(gmp_task_t* tsk)
{
    GMP_UNUSED_VAR(tsk);

    static uint16_t beep_tick = 0;
    static uint16_t beep_state = 0;
    static uint16_t last_alarm_state = PHASE_ALARM_NONE;

    if (phase_alarm_enable == 0U)
    {
        phase_alarm_state = PHASE_ALARM_NONE;
    }
    else if (phase_display_deg <= 3U)
    {
        phase_alarm_state = PHASE_ALARM_LOWER;
    }
    else if (phase_display_deg >= 97U)
    {
        phase_alarm_state = PHASE_ALARM_UPPER;
    }
    else
    {
        phase_alarm_state = PHASE_ALARM_NONE;
    }

    if (phase_alarm_state == PHASE_ALARM_NONE)
    {
        beep_tick = 0;
        beep_state = 0;
        last_alarm_state = PHASE_ALARM_NONE;
        beep_off();

        return GMP_TASK_DONE;
    }

    if (phase_alarm_state != last_alarm_state)
    {
        beep_tick = 0;
        beep_state = 0;
        last_alarm_state = phase_alarm_state;
        beep_off();
    }

    beep_tick += 1U;

    if ((phase_alarm_state == PHASE_ALARM_UPPER) || (beep_tick >= 5U))
    {
        beep_tick = 0;
        beep_state = (uint16_t)!beep_state;

        if (beep_state)
        {
            beep_on();
        }
        else
        {
            beep_off();
        }
    }

    return GMP_TASK_DONE;
}

//
// Non-blocking task scheduler
//
gmp_scheduler_t sched;

#define TASK_INDEX_FLUSH_KEY     3U
#define TASK_INDEX_FLUSH_LED     4U
#define TASK_INDEX_PHASE_DISPLAY 7U
#define TASK_INDEX_PHASE_ALARM   8U

// All tasks must be non blocking tasks
gmp_task_t tasks[] = {
    // name,     task,      period(ms),  init_phase, is_enabled, pParam
    {"blink_led", tsk_blink, 1000, 100, 1, NULL},
    {"fpga_test", fpga_test_task, 1000, 600, 1, NULL},
    {"dl_online", tsk_dl_debug_device, 2, 0, 1, NULL},
    {"flush_key", tsk_key_flush, 20, 10, 0, (void*)&ht16k33},
    {"flush_led", tsk_LED_flush, 500, 200, 0, (void*)&ht16k33},
    {"startup", tsk_startup, 500, 0, 1, NULL},
    {"phase_update", tsk_phase_update, 1, 0, 1, NULL},
    {"phase_display", tsk_phase_display, 500, 100, 0, (void*)&ht16k33},
    {"phase_alarm", tsk_phase_alarm, 100, 50, 0, NULL},
};

//=================================================================================================
// initialize routine

GMP_NO_OPT_PREFIX
void init(void) GMP_NO_OPT_SUFFIX
{
    int i;

    // init scheduler
    gmp_scheduler_init(&sched);

    for (i = 0; i < sizeof(tasks) / sizeof(gmp_task_t); ++i)
        gmp_scheduler_add_task(&sched, &tasks[i]);

    // init datalink protocol
    gmp_dev_dl_init(&dl);

    // enable PIL simulation environment
    gmp_pil_sim_init(&pil, &dl, 0x10);

    // Band DL module with tunable and persp module.
    gmp_param_tunable_init(&tunable, &dl, 0x30, dict_m1, var_tunable_count);
    gmp_mem_persp_init(&mem_persp_server, &dl, 0x50, mem_regions, mem_regions_count);
}

// Initialization tasks after all peripherals have been initialized
gmp_task_status_t tsk_startup(gmp_task_t* tsk)
{
    GMP_UNUSED_VAR(tsk);

    static uint16_t beep_counter = 0;

    if (beep_counter == 0)
        beep_on();
    else if (beep_counter == 1)
        beep_off();
    else if (beep_counter == 2)
        beep_on();
    else if (beep_counter == 3)
        beep_off();

    beep_counter += 1;

    // if program is complete, init all the peripherals, and close this routine.
    if (beep_counter >= 4)
    {
        ht16k33_init_t ht16k33_init_struct = {.brightness = 15, .blink_rate = 0, .int_enable = 0, .int_act_high = 0};

        ec_gt ec = ht16k33_init(&ht16k33, iic_bus, HT16K33_DEFAULT_DEV_ADDR, &ht16k33_init_struct);

        if (ec == GMP_EC_OK)
        {
            sched.task_list[TASK_INDEX_FLUSH_KEY]->is_enabled = 1;
            sched.task_list[TASK_INDEX_FLUSH_LED]->is_enabled = 1;
            sched.task_list[TASK_INDEX_PHASE_DISPLAY]->is_enabled = 1;
            sched.task_list[TASK_INDEX_PHASE_ALARM]->is_enabled = 1;
        }

        hdc1080_config_reg_t hdc1080_cfg = {.all = 0};
        hdc1080_cfg.bits.mode = 1; // continuous acquisition data

        //hdc1080_init(&hdc1080, iic_bus, HDC1080_I2C_ADDR_DEFAULT, hdc1080_cfg);

        // startup process is complete.
        tsk->is_enabled = 0;
    }

    return GMP_TASK_DONE;
}


//=================================================================================================
// endless loop routine

GMP_NO_OPT_PREFIX
void mainloop(void) GMP_NO_OPT_SUFFIX
{
    // run task scheduler
    gmp_scheduler_dispatch(&sched);
}
