
// GMP basic core header
#include <gmp_core.h>

// user main header
#include "ctl_main.h"
#include "user_main.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>

// peripheral
#include <core/dev/display/ht16k33.h>
#include <core/dev/gpio/pca9555.h>
#include <core/dev/sensor/hdc1080.h>

#include <oled_driver.h>

//=================================================================================================
// BEEP control function



gpio_halt gpio_beep;

void beep_on()
{
    gmp_hal_gpio_write(gpio_beep, 1);
}

void beep_off()
{
    gmp_hal_gpio_write(gpio_beep, 0);
}

//=================================================================================================
// LED control function

// devices
iic_halt iic_bus;
ht16k33_dev_t ht16k33;
hdc1080_dev_t hdc1080;

//
// Common cathode digital tube segment code table
//
const unsigned char led_lut[] = {
    0x3F, // 0  (a,b,c,d,e,f)
    0x06, // 1  (b,c)
    0x5B, // 2  (a,b,d,e,g)
    0x4F, // 3  (a,b,c,d,g)
    0x66, // 4  (b,c,f,g)
    0x6D, // 5  (a,c,d,f,g)
    0x7D, // 6  (a,c,d,e,f,g)
    0x07, // 7  (a,b,c)
    0x7F, // 8  (a,b,c,d,e,f,g)
    0x6F, // 9  (a,b,c,d,f,g)
    0x77, // A  (a,b,c,e,f,g)
    0x7C, // b  (c,d,e,f,g)
    0x39, // C  (a,d,e,f)
    0x5E, // d  (b,c,d,e,g)
    0x79, // E  (a,d,e,f,g)
    0x71, // F  (a,e,f,g)
    0x76, // H  (b,c,e,f,g)
    0x38, // L  (d,e,f)
    0x73, // P  (a,b,e,f,g)
    0x3E, // U  (b,c,d,e,f)
    0x40, // -  (g) - dash
    0x80, // .  (dp) - dot
    0x00  // close all
};

void update_led_content_8byte(ht16k33_dev_t* dev, uint16_t ch1, uint16_t ch2, uint16_t ch3, uint16_t ch4, uint16_t ch5,
                              uint16_t ch6, uint16_t ch7, uint16_t ch8)
{
    dev->display_ram[0] = ch1;
    dev->display_ram[2] = ch2;
    dev->display_ram[4] = ch3;
    dev->display_ram[6] = ch4;
    dev->display_ram[8] = ch5;
    dev->display_ram[10] = ch6;
    dev->display_ram[12] = ch7;
    dev->display_ram[14] = ch8;
    dev->is_dirty = 1;
}

gmp_task_status_t tsk_LED_flush(gmp_task_t* tsk)
{
    ht16k33_dev_t* dev = (ht16k33_dev_t*)tsk->user_data;

    if(flag_init_cmpt)
    {
    // fresh LED buffer here.
    ec_gt ret = ht16k33_update_display(dev);

    // if meets error, close this task
    if (ret != GMP_EC_OK)
    {
        tsk->is_enabled = 0;
    }
    }

    return GMP_TASK_DONE;
}

#define IRIS_SW1_KEY_ID 8U
#define IRIS_SW2_KEY_ID 9U
#define IRIS_SW3_KEY_ID 1U
#define IRIS_SW4_KEY_ID 2U
#define IRIS_SW5_KEY_ID 3U
#define IRIS_SW6_KEY_ID 4U
#define IRIS_SW7_KEY_ID 5U
#define IRIS_SW8_KEY_ID 6U
#define IRIS_SW9_KEY_ID 7U
#define IRIS_SW10_KEY_ID 21U
#define IRIS_SW11_KEY_ID 22U
#define IRIS_SW12_KEY_ID 14U
#define IRIS_SW13_KEY_ID 15U
#define IRIS_SW14_KEY_ID 16U
#define IRIS_SW15_KEY_ID 17U
#define IRIS_SW16_KEY_ID 18U
#define IRIS_SW17_KEY_ID 19U
#define IRIS_SW18_KEY_ID 20U

#define PSU_V_SET_MAX 10.0f
#define PSU_I_SET_MAX 100.0f
#define PSU_INPUT_BUF_SIZE 8U
#define PSU_KEY_RELEASE_COUNT 20U
#define PSU_OLED_LINE_COUNT 4U
#define PSU_OLED_LINE_LEN 16U
#define PSU_OLED_FORCE_REDRAW_COUNT 10U
#define PSU_EQEP_POSITION_MAX 10000L
#define PSU_EQEP_V_STEP 0.01f
#define PSU_EQEP_I_STEP 0.1f

static char psu_input_buf[PSU_INPUT_BUF_SIZE];
static uint16_t psu_input_len = 0;
static uint16_t psu_input_has_dot = 0;
static uint16_t psu_input_active = 0;
static uint16_t psu_oled_force_redraw = 1U;

static void psu_input_clear(void)
{
    psu_input_len = 0;
    psu_input_has_dot = 0;
    psu_input_active = 0;
    psu_input_buf[0] = '\0';
}

static void psu_input_start(void)
{
    if (psu_input_active == 0U)
    {
        psu_input_len = 0;
        psu_input_has_dot = 0;
        psu_input_buf[0] = '\0';
        psu_input_active = 1U;
    }
}

static uint16_t psu_input_frac_len(void)
{
    uint16_t frac_len = 0;
    uint16_t after_dot = 0;
    uint16_t i;

    for (i = 0; i < psu_input_len; ++i)
    {
        if (psu_input_buf[i] == '.')
            after_dot = 1U;
        else if (after_dot)
            ++frac_len;
    }

    return frac_len;
}

static uint16_t psu_input_max_frac_len(void)
{
    if (psu_edit_target == PSU_EDIT_VOLTAGE)
        return 2U;

    if (psu_edit_target == PSU_EDIT_CURRENT)
        return 1U;

    return 0U;
}

static void psu_input_append(char ch)
{
    psu_input_start();

    if (psu_input_len >= (PSU_INPUT_BUF_SIZE - 1U))
        return;

    if (ch == '.')
    {
        if (psu_input_has_dot)
            return;

        psu_input_has_dot = 1U;
    }
    else if (psu_input_has_dot && (psu_input_frac_len() >= psu_input_max_frac_len()))
    {
        return;
    }

    psu_input_buf[psu_input_len++] = ch;
    psu_input_buf[psu_input_len] = '\0';
}

static void psu_input_backspace(void)
{
    if (psu_input_len == 0U)
        return;

    if (psu_input_buf[psu_input_len - 1U] == '.')
        psu_input_has_dot = 0U;

    psu_input_buf[--psu_input_len] = '\0';

    if (psu_input_len == 0U)
        psu_input_active = 0U;
}

static float32_t psu_input_parse(void)
{
    float32_t value = 0.0f;
    float32_t frac = 0.1f;
    uint16_t after_dot = 0;
    uint16_t i;

    for (i = 0; i < psu_input_len; ++i)
    {
        char ch = psu_input_buf[i];

        if (ch == '.')
        {
            after_dot = 1U;
        }
        else if ((ch >= '0') && (ch <= '9'))
        {
            if (after_dot)
            {
                value += (float32_t)(ch - '0') * frac;
                frac *= 0.1f;
            }
            else
            {
                value = value * 10.0f + (float32_t)(ch - '0');
            }
        }
    }

    return value;
}

static float32_t psu_limit_value(float32_t value, float32_t max_value)
{
    if (value < 0.0f)
        return 0.0f;

    if (value > max_value)
        return max_value;

    return value;
}

static void psu_input_confirm(void)
{
    float32_t value;

    if (psu_input_len == 0U)
        return;

    value = psu_input_parse();

    if (psu_edit_target == PSU_EDIT_VOLTAGE)
        psu_v_set = psu_limit_value(value, PSU_V_SET_MAX);
    else if (psu_edit_target == PSU_EDIT_CURRENT)
        psu_i_set = psu_limit_value(value, PSU_I_SET_MAX);

    psu_input_clear();
}

static const char* psu_input_unit_text(void)
{
    uint16_t frac_len = psu_input_frac_len();

    if (psu_edit_target == PSU_EDIT_VOLTAGE)
    {
        if (psu_input_has_dot && (frac_len >= 2U))
            return "0.01V";

        if (psu_input_has_dot)
            return "0.1V";

        return "1V";
    }

    if (psu_edit_target == PSU_EDIT_CURRENT)
    {
        if (psu_input_has_dot)
            return "0.1mA";

        return "1mA";
    }

    return "";
}

static void psu_next_mode(void)
{
    if (psu_mode == PSU_MODE_CV)
        psu_mode = PSU_MODE_CC;
    else if (psu_mode == PSU_MODE_CC)
        psu_mode = PSU_MODE_AUTO;
    else
        psu_mode = PSU_MODE_CV;
}

static void psu_handle_key(uint16_t key_id)
{
    switch (key_id)
    {
    case IRIS_SW1_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('1');
        break;

    case IRIS_SW2_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('2');
        break;

    case IRIS_SW3_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('3');
        break;

    case IRIS_SW4_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('4');
        break;

    case IRIS_SW5_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('5');
        break;

    case IRIS_SW6_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('6');
        break;

    case IRIS_SW7_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('7');
        break;

    case IRIS_SW8_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('8');
        break;

    case IRIS_SW9_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('9');
        break;

    case IRIS_SW10_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('0');
        break;

    case IRIS_SW11_KEY_ID:
        if (psu_edit_target != PSU_EDIT_MODE)
            psu_input_append('.');
        break;

    case IRIS_SW12_KEY_ID:
        psu_input_confirm();
        break;

    case IRIS_SW13_KEY_ID:
        psu_input_backspace();
        break;

    case IRIS_SW14_KEY_ID:
        psu_state = PSU_STATE_ON;
        psu_fault = PSU_FAULT_NONE;
        break;

    case IRIS_SW15_KEY_ID:
        psu_state = PSU_STATE_OFF;
        break;

    case IRIS_SW16_KEY_ID:
        psu_input_clear();
        psu_edit_target = PSU_EDIT_VOLTAGE;
        break;

    case IRIS_SW17_KEY_ID:
        psu_input_clear();
        psu_edit_target = PSU_EDIT_CURRENT;
        break;

    case IRIS_SW18_KEY_ID:
        psu_input_clear();
        psu_edit_target = PSU_EDIT_MODE;
        psu_next_mode();
        break;

    default:
        break;
    }
}

gmp_task_status_t tsk_key_flush(gmp_task_t* tsk)
{
    ht16k33_dev_t* dev = (ht16k33_dev_t*)tsk->user_data;
    fast_gt key_id = 0;
    static fast_gt accepted_key_id = 0;
    static uint16_t release_count = 0;

    if(flag_init_cmpt)
    {

    ec_gt ret = ht16k33_read_keys(dev, &key_id);

    // if meets error, close this task
    if (ret != GMP_EC_OK)
    {
        tsk->is_enabled = 0;
        return GMP_TASK_DONE;
    }

    if (key_id == 0)
    {
        if (release_count < PSU_KEY_RELEASE_COUNT)
            ++release_count;

        if (release_count >= PSU_KEY_RELEASE_COUNT)
            accepted_key_id = 0;
    }
    else
    {
        release_count = 0;
    }

    if ((key_id != 0) && (accepted_key_id != key_id))
    {
        accepted_key_id = key_id;
        psu_handle_key((uint16_t)key_id);

        // response key message
        update_led_content_8byte(dev, led_lut[2], led_lut[0], led_lut[2], led_lut[6], led_lut[20], led_lut[key_id / 10],
                                 led_lut[key_id % 10], led_lut[20]);

        gmp_base_print("Receive Key Message, %d\r\n", key_id);
    }
    }

    return GMP_TASK_DONE;
}

static void psu_apply_eqep_steps(int16_t steps)
{
    if (steps == 0)
        return;

    if (psu_edit_target == PSU_EDIT_VOLTAGE)
    {
        psu_input_clear();
        psu_v_set = psu_limit_value(psu_v_set + (float32_t)steps * PSU_EQEP_V_STEP, PSU_V_SET_MAX);
    }
    else if (psu_edit_target == PSU_EDIT_CURRENT)
    {
        psu_input_clear();
        psu_i_set = psu_limit_value(psu_i_set + (float32_t)steps * PSU_EQEP_I_STEP, PSU_I_SET_MAX);
    }
}

gmp_task_status_t tsk_eqep_flush(gmp_task_t* tsk)
{
    static int32_t last_position = 0;
    int32_t position;
    int32_t delta;

    GMP_UNUSED_VAR(tsk);

    if (flag_init_cmpt != 1U)
        return GMP_TASK_DONE;

    position = (int32_t)EQEP_getPosition(IRIS_EQEP1_BASE);
    delta = position - last_position;
    last_position = position;

    if (delta > (PSU_EQEP_POSITION_MAX / 2L))
        delta -= (PSU_EQEP_POSITION_MAX + 1L);
    else if (delta < -(PSU_EQEP_POSITION_MAX / 2L))
        delta += (PSU_EQEP_POSITION_MAX + 1L);

    psu_apply_eqep_steps((int16_t)delta);

    return GMP_TASK_DONE;
}

static const char* psu_state_text(psu_state_t state)
{
    switch (state)
    {
    case PSU_STATE_ON:
        return "ON";
    case PSU_STATE_FAULT:
        return "FAULT";
    case PSU_STATE_OFF:
    default:
        return "OFF";
    }
}

static const char* psu_mode_text(psu_mode_t mode)
{
    switch (mode)
    {
    case PSU_MODE_CV:
        return "CV";
    case PSU_MODE_CC:
        return "CC";
    case PSU_MODE_AUTO:
    default:
        return "AUTO";
    }
}

static const char* psu_edit_text(psu_edit_target_t target)
{
    switch (target)
    {
    case PSU_EDIT_CURRENT:
        return "I";
    case PSU_EDIT_MODE:
        return "M";
    case PSU_EDIT_VOLTAGE:
    default:
        return "V";
    }
}

static const char* psu_fault_text(psu_fault_t fault)
{
    switch (fault)
    {
    case PSU_FAULT_OVERVOLTAGE:
        return "OV";
    case PSU_FAULT_OVERCURRENT:
        return "OC";
    case PSU_FAULT_NONE:
    default:
        return "NONE";
    }
}

static uint16_t psu_to_scaled_u16(float32_t value, float32_t scale, uint16_t max_value)
{
    uint32_t scaled;

    if (value < 0.0f)
        value = 0.0f;

    scaled = (uint32_t)(value * scale + 0.5f);

    if (scaled > max_value)
        scaled = max_value;

    return (uint16_t)scaled;
}

static void psu_format_voltage(char* str, float32_t voltage)
{
    uint16_t centivolt = psu_to_scaled_u16(voltage, 100.0f, 9999U);
    sprintf(str, "%02u.%02u", centivolt / 100U, centivolt % 100U);
}

static void psu_format_current(char* str, float32_t current_ma)
{
    uint16_t deci_ma = psu_to_scaled_u16(current_ma, 10.0f, 9999U);
    sprintf(str, "%03u.%01u", deci_ma / 10U, deci_ma % 10U);
}

static uint16_t psu_oled_line_index(uint8_t y_page)
{
    return (uint16_t)(y_page / 2U);
}

static char psu_oled_line_cache[PSU_OLED_LINE_COUNT][PSU_OLED_LINE_LEN + 1U];

static void psu_oled_invalidate_cache(void)
{
    uint16_t i;

    for (i = 0; i < PSU_OLED_LINE_COUNT; ++i)
        psu_oled_line_cache[i][0] = '\0';
}

static void psu_oled_show_line(uint8_t y_page, const char* text)
{
    char line[PSU_OLED_LINE_LEN + 1U];
    uint16_t line_index = psu_oled_line_index(y_page);
    uint16_t changed = psu_oled_force_redraw;
    uint16_t i;

    for (i = 0; (i < PSU_OLED_LINE_LEN) && (text[i] != '\0'); ++i)
    {
        if ((text[i] >= ' ') && (text[i] <= '~'))
            line[i] = text[i];
        else
            line[i] = ' ';
    }

    for (; i < PSU_OLED_LINE_LEN; ++i)
        line[i] = ' ';

    line[PSU_OLED_LINE_LEN] = '\0';

    if (line_index >= PSU_OLED_LINE_COUNT)
        return;

    for (i = 0; i <= PSU_OLED_LINE_LEN; ++i)
    {
        if (psu_oled_line_cache[line_index][i] != line[i])
        {
            changed = 1U;
            break;
        }
    }

    if (changed)
    {
        for (i = 0; i <= PSU_OLED_LINE_LEN; ++i)
            psu_oled_line_cache[line_index][i] = line[i];

        oled_show_str(0, y_page, line);
    }
}

gmp_task_status_t oled_show_task(gmp_task_t* tsk)
{
    char line[32];
    char v_set_str[8];
    char i_set_str[8];
    char v_meas_str[8];
    char i_meas_str[8];
    static uint16_t redraw_counter = 0;

    GMP_UNUSED_VAR(tsk);

    if (flag_init_cmpt != 1U)
        return GMP_TASK_DONE;

    if (psu_oled_force_redraw || (++redraw_counter >= PSU_OLED_FORCE_REDRAW_COUNT))
    {
        oled_clear();
        psu_oled_invalidate_cache();
        psu_oled_force_redraw = 1U;
        redraw_counter = 0;
    }

    psu_format_voltage(v_set_str, psu_v_set);
    psu_format_current(i_set_str, psu_i_set);
    psu_format_voltage(v_meas_str, psu_v_meas);
    psu_format_current(i_meas_str, psu_i_meas);

    sprintf(line, "%s %s E:%s", psu_state_text(psu_state), psu_mode_text(psu_mode), psu_edit_text(psu_edit_target));
    psu_oled_show_line(0, line);

    if ((psu_input_active != 0U) && (psu_edit_target == PSU_EDIT_VOLTAGE))
        sprintf(line, "IN V:%s %s", psu_input_buf, psu_input_unit_text());
    else if ((psu_input_active != 0U) && (psu_edit_target == PSU_EDIT_CURRENT))
        sprintf(line, "IN I:%s %s", psu_input_buf, psu_input_unit_text());
    else
        sprintf(line, "SV%s SI%s", v_set_str, i_set_str);
    psu_oled_show_line(2, line);

    sprintf(line, "MV%s MI%s", v_meas_str, i_meas_str);
    psu_oled_show_line(4, line);

    sprintf(line, "FLT:%s", psu_fault_text(psu_fault));
    psu_oled_show_line(6, line);

    psu_oled_force_redraw = 0U;

    return GMP_TASK_DONE;
}

//=================================================================================================
// FPGA control function

gmp_task_status_t fpga_test_task(gmp_task_t* tsk)
{
    GMP_UNUSED_VAR(tsk);

    static fast_gt led_stat = 0;
    if (led_stat == 0)
    {
        led_stat = 1;
        SPI_writeReg(0x01, 0x0003);
    }
    else
    {
        led_stat = 0;
        SPI_writeReg(0x01, 0x0000);
    }

    SPI_writeReg(0x03, 0x00FF);

    // trigger ADC
    SPI_writeReg(0x05, 0x8000);
    SPI_writeReg(0x06, 0xA000);
    SPI_writeReg(0x07, 0xF000);

    uint16_t adc_result;
    adc_result = SPI_readReg(0x08);

    SPI_writeReg(0x04, adc_result);

    return GMP_TASK_DONE;
}
