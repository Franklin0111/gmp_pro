
// GMP basic core header
#include <gmp_core.h>

// user main header
#include "ctl_main.h"
#include "user_main.h"
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

gmp_task_status_t tsk_key_flush(gmp_task_t* tsk)
{
    ht16k33_dev_t* dev = (ht16k33_dev_t*)tsk->user_data;
    fast_gt key_id = 0;

    if(flag_init_cmpt)
    {

    ec_gt ret = ht16k33_read_keys(dev, &key_id);

    // if meets error, close this task
    if (ret != GMP_EC_OK)
    {
        tsk->is_enabled = 0;
    }

    if (key_id != 0)
    {
        // response key message
        update_led_content_8byte(dev, led_lut[2], led_lut[0], led_lut[2], led_lut[6], led_lut[20], led_lut[key_id / 10],
                                 led_lut[key_id % 10], led_lut[20]);

        gmp_base_print("Receive Key Message, %d\r\n", key_id);
    }
    }

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

static void psu_oled_show_line(uint8_t y_page, const char* text)
{
    char line[17];
    uint16_t i;

    for (i = 0; (i < 16U) && (text[i] != '\0'); ++i)
        line[i] = text[i];

    for (; i < 16U; ++i)
        line[i] = ' ';

    line[16] = '\0';
    oled_show_str(0, y_page, line);
}

gmp_task_status_t oled_show_task(gmp_task_t* tsk)
{
    char line[32];
    char v_set_str[8];
    char i_set_str[8];
    char v_meas_str[8];
    char i_meas_str[8];

    GMP_UNUSED_VAR(tsk);

    if (flag_init_cmpt != 1U)
        return GMP_TASK_DONE;

    psu_format_voltage(v_set_str, psu_v_set);
    psu_format_current(i_set_str, psu_i_set);
    psu_format_voltage(v_meas_str, psu_v_meas);
    psu_format_current(i_meas_str, psu_i_meas);

    sprintf(line, "%s %s E:%s", psu_state_text(psu_state), psu_mode_text(psu_mode), psu_edit_text(psu_edit_target));
    psu_oled_show_line(0, line);

    sprintf(line, "SV%s SI%s", v_set_str, i_set_str);
    psu_oled_show_line(2, line);

    sprintf(line, "MV%s MI%s", v_meas_str, i_meas_str);
    psu_oled_show_line(4, line);

    sprintf(line, "FLT:%s", psu_fault_text(psu_fault));
    psu_oled_show_line(6, line);

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
