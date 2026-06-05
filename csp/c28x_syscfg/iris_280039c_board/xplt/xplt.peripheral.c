//
// THIS IS A DEMO SOURCE CODE FOR GMP LIBRARY.
//
// User should add all definitions of peripheral objects in this file.
//
// User should implement the peripheral objects initialization in setup_peripheral function.
//
// This file is platform-related.
//

// GMP basic core header
#include <gmp_core.h>

#include "user_main.h"
#include <xplt.peripheral.h>

//=================================================================================================
// definitions of peripheral

// inverter side voltage feedback
tri_ptr_adc_channel_t uuvw;
adc_gt uuvw_src[3];

// inverter side current feedback
tri_ptr_adc_channel_t iuvw;
adc_gt iuvw_src[3];

// grid side voltage feedback
tri_ptr_adc_channel_t vabc;
adc_gt vabc_src[3];

// grid side current feedback
tri_ptr_adc_channel_t iabc;
adc_gt iabc_src[3];

// DC bus current & voltage feedback
ptr_adc_channel_t udc;
adc_gt udc_src;
ptr_adc_channel_t idc;
adc_gt idc_src;

// eCAP phase measurement
volatile uint32_t capsource_count = 0;
volatile uint32_t capps_count = 0;
volatile uint32_t capsource_period_count = 0;
volatile uint32_t capps_period_count = 0;
volatile uint16_t capsource_ready = 0;
volatile uint16_t capps_ready = 0;

int32_t ecap_offset_count = 47;
int32_t phase_delta_count = 0;
uint32_t phase_period_count = 120000UL;
float phase_deg = 0.0f;
uint16_t phase_display_deg = 0;
uint16_t phase_alarm_enable = 0;
uint16_t phase_alarm_state = 0;

//=================================================================================================
// peripheral setup function

extern iic_halt iic_bus;
extern gpio_halt user_led;
extern gpio_halt gpio_beep;

//my variable define
adc_gt sin_source;
adc_gt sin_fs;
adc_channel_t adc_sin_source;
adc_channel_t adc_sin_fs;
ctrl_gt dac_result;
ctl_filter_IIR1_t sin_source_hpf;
ctl_filter_IIR1_t sin_fs_hpf;
ctrl_gt adc_product_raw;
ctrl_gt adc_product_dc;
volatile int16_t adc_product_dc_mv_x10 = 0;
ctl_filter_IIR1_t adc_product_lpf;

//
// Function to configure I2C A in FIFO mode.
//
void initI2C()
{
    //
    // Must put I2C into reset before configuring it
    //
    I2C_disableModule(I2CA_BASE);

    //
    // I2C configuration. Use a 400kHz I2CCLK with a 33% duty cycle.
    //
    I2C_initController(I2CA_BASE, DEVICE_SYSCLK_FREQ, 400000, I2C_DUTYCYCLE_33);
    I2C_setBitCount(I2CA_BASE, I2C_BITCOUNT_8);
    I2C_setTargetAddress(I2CA_BASE, 0x70);
    I2C_setEmulationMode(I2CA_BASE, I2C_EMULATION_FREE_RUN);

    //
    // Enable stop condition and register-access-ready interrupts
    I2C_enableInterrupt(I2CA_BASE, I2C_INT_STOP_CONDITION |
                                   I2C_INT_REG_ACCESS_RDY);

    //
    // FIFO configuration
    //
    I2C_enableFIFO(I2CA_BASE);
    I2C_clearInterruptStatus(I2CA_BASE, I2C_INT_RXFF | I2C_INT_TXFF);

    //
    // Configuration complete. Enable the module.
    //
    I2C_enableModule(I2CA_BASE);
}

// User should setup all the peripheral in this function.
void setup_peripheral(void)
{
    // Setup Debug Uart
    debug_uart = IRIS_UART_USB_BASE;

    // Test print function
    gmp_base_print(TEXT_STRING("Hello World!\r\n"));
    asm(" RPT #255 || NOP");

    //
    // Initialize GPIOs for use as SDA A and SCL A respectively
    //
    // GPIO_setPinConfig(DEVICE_GPIO_CFG_SDAA);
    GPIO_setPadConfig(IRIS_IIC_I2CSDA_GPIO, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(IRIS_IIC_I2CSDA_GPIO, GPIO_QUAL_ASYNC);

    // GPIO_setPinConfig(DEVICE_GPIO_CFG_SCLA);
    GPIO_setPadConfig(IRIS_IIC_I2CSCL_GPIO, GPIO_PIN_TYPE_PULLUP);
    GPIO_setQualificationMode(IRIS_IIC_I2CSCL_GPIO, GPIO_QUAL_ASYNC);

    GPIO_setPadConfig(IRIS_IIC_I2CSDA_GPIO, GPIO_PIN_TYPE_PULLUP);

    //
    // Set I2C use, initializing it for FIFO mode
    //
    initI2C();

    iic_bus = I2CA_BASE;

    user_led = SYSTEM_LED;

    gpio_beep = IRIS_GPIO1;

    ctl_init_adc_channel(&adc_sin_source, 1.0, 0.0, 12, 24);
    ctl_init_adc_channel(&adc_sin_fs, 1.0, 0.0, 12, 24);

    ECAP_stopCounter(capsource_BASE);
    ECAP_stopCounter(capps_BASE);

    ECAP_resetCounters(capsource_BASE);
    ECAP_resetCounters(capps_BASE);

    ECAP_clearInterrupt(capsource_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                      ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(capsource_BASE);
    ECAP_clearInterrupt(capps_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                  ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(capps_BASE);

    capsource_ready = 0;
    capps_ready = 0;
    capsource_period_count = 0;
    capps_period_count = 0;

    ECAP_reArm(capsource_BASE);
    ECAP_reArm(capps_BASE);

    ECAP_startCounter(capsource_BASE);
    ECAP_startCounter(capps_BASE);
}

//=================================================================================================
// ADC Interrupt ISR and controller related function

// ADC interrupt
interrupt void MainISR(void)
{
    //
    // call GMP ISR  Controller operation callback function
    //
    gmp_base_ctl_step();

    //
    // Call GMP Timer
    //
    gmp_step_system_tick();

    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(IRIS_ADCA_BASE, ADC_INT_NUMBER1);

    //
    // Check if overflow has occurred
    //
    if (true == ADC_getInterruptOverflowStatus(IRIS_ADCA_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(IRIS_ADCA_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(IRIS_ADCA_BASE, ADC_INT_NUMBER1);
    }

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INT_IRIS_ADCA_1_INTERRUPT_ACK_GROUP);
}

interrupt void INT_capsource_ISR(void)
{
    uint32_t cap1 = ECAP_getEventTimeStamp(capsource_BASE, ECAP_EVENT_1);
    uint32_t cap3 = ECAP_getEventTimeStamp(capsource_BASE, ECAP_EVENT_3);

    capsource_count = cap1;
    capsource_period_count = cap3 - cap1;
    capsource_ready = 1;

    ECAP_clearInterrupt(capsource_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                      ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(capsource_BASE);

    Interrupt_clearACKGroup(INT_capsource_INTERRUPT_ACK_GROUP);
}

interrupt void INT_capps_ISR(void)
{
    uint32_t cap1 = ECAP_getEventTimeStamp(capps_BASE, ECAP_EVENT_1);
    uint32_t cap3 = ECAP_getEventTimeStamp(capps_BASE, ECAP_EVENT_3);

    capps_count = cap1;
    capps_period_count = cap3 - cap1;
    capps_ready = 1;

    ECAP_clearInterrupt(capps_BASE, ECAP_ISR_SOURCE_CAPTURE_EVENT_1 | ECAP_ISR_SOURCE_CAPTURE_EVENT_2 |
                                  ECAP_ISR_SOURCE_CAPTURE_EVENT_3 | ECAP_ISR_SOURCE_CAPTURE_EVENT_4);
    ECAP_clearGlobalInterrupt(capps_BASE);

    Interrupt_clearACKGroup(INT_capps_INTERRUPT_ACK_GROUP);
}

void reset_controller(void)
{
    int i = 0;

    GPIO_WritePin(PWM_RESET_PORT, 0);

    for(i=0;i<10000;++i);

    GPIO_WritePin(PWM_RESET_PORT, 1);

}

//=================================================================================================
// communication functions and interrupt functions here

// 10000 -> 1.0
#define CAN_SCALE_FACTOR 10000

// 32 bit union
typedef union {
    int32_t i32;
    uint16_t u16[2]; // C2000��uint16_tռ1��word��32λռ��2��word
} can_data_t;

// CAN interrupt
interrupt void INT_IRIS_CAN_0_ISR(void)
{
    uint32_t status = CAN_getInterruptCause(IRIS_CAN_BASE);

    uint16_t rx_data[4];
    can_data_t recv_content[2];

    if (status == 1)
    {
        CAN_readMessage(IRIS_CAN_BASE, 1, rx_data);
        CAN_clearInterruptStatus(CANA_BASE, 1);

        // Control Flag, Enable System
//        if (rx_data[0] == 1)
//        {
//            cia402_send_cmd(&cia402_sm, CIA402_CMD_ENABLE_OPERATION);
//        }
//        if (rx_data[0] == 0)
//        {
//            cia402_send_cmd(&cia402_sm, CIA402_CMD_DISABLE_VOLTAGE);
//        }
    }
    else if (status == 2)
    {
        CAN_readMessage(IRIS_CAN_BASE, 2, (uint16_t*)recv_content);
        CAN_clearInterruptStatus(CANA_BASE, 2);

        // set target value
#if BUILD_LEVEL == 1
        // For level 1 Set target voltage
        ctl_set_gfl_inv_voltage_openloop(&inv_ctrl, float2ctrl((float)recv_content[0].i32 / CAN_SCALE_FACTOR),
                                         float2ctrl((float)recv_content[1].i32 / CAN_SCALE_FACTOR));

#endif // BUILD_LEVEL
    }

    //
    // Clear the interrupt flag
    //
    CAN_clearGlobalInterruptStatus(IRIS_CAN_BASE, CAN_GLOBAL_INT_CANINT0);

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INT_IRIS_CAN_0_INTERRUPT_ACK_GROUP);
}

interrupt void INT_IRIS_CAN_1_ISR(void)
{
    // Nothing here

    //
    // Clear the interrupt flag
    //
    CAN_clearGlobalInterruptStatus(IRIS_CAN_BASE, CAN_GLOBAL_INT_CANINT1);

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INT_IRIS_CAN_1_INTERRUPT_ACK_GROUP);
}

void send_monitor_data(void)
{
    uint16_t rx_raw[4];
    can_data_t tran_content[2];

    // 0x201: Monitor Grid Voltage
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 4, 8, (uint16_t*)tran_content);

    //0x202: Monitor inverter voltage
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 5, 8, (uint16_t*)tran_content);

    // 0x203: Monitor grid current
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 6, 8, (uint16_t*)tran_content);

    // 0x204: TODO Monitor inverter current
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 7, 8, (uint16_t*)tran_content);

    // 0x205: TODO Monitor DC Voltage / Current
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 8, 8, (uint16_t*)tran_content);

    // 0x206: Monitor Grid Voltage A and PLL output angle
//    tran_content[0].i32 = (int32_t)(inv_ctrl.vabc.dat[phase_A] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.pll.theta * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 9, 8, (uint16_t*)tran_content);

    // 0x207: Monitor reserved
//    tran_content[0].i32 = (int32_t)(inv_ctrl.idq.dat[phase_d] * CAN_SCALE_FACTOR);
//    tran_content[1].i32 = (int32_t)(inv_ctrl.idq.dat[phase_q] * CAN_SCALE_FACTOR);

    CAN_sendMessage(IRIS_CAN_BASE, 10, 8, (uint16_t*)tran_content);
}

#if BOARD_SELECTION == GMP_IRIS

interrupt void INT_IRIS_UART_RS232_RX_ISR(void)
{
    // Nothing here

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INT_IRIS_UART_RS232_RX_INTERRUPT_ACK_GROUP);
}

#endif // BOARD_SELECTION == GMP_IRIS

//=================================================================================================
// Debug interface

// a local small cache size, capable of covering the depth of the hardware FIFO (typically 16 bytes)
#define ISR_LOCAL_BUF_SIZE 16

extern gmp_datalink_t dl;

void flush_dl_tx_buffer()
{
    // Send head
    gmp_hal_uart_write(IRIS_UART_USB_BASE, gmp_dev_dl_get_tx_hw_hdr_ptr(&dl), gmp_dev_dl_get_tx_hw_hdr_size(&dl), 10);

    // Send data body, if necessary
    if (gmp_dev_dl_get_tx_hw_pld_size(&dl) > 0)
    {
        gmp_hal_uart_write(IRIS_UART_USB_BASE, gmp_dev_dl_get_tx_hw_pld_ptr(&dl), gmp_dev_dl_get_tx_hw_pld_size(&dl),
                           10);
    }
}

void flush_dl_rx_buffer()
{
    uint16_t fifoLevel;
    data_gt rxBuf[ISR_LOCAL_BUF_SIZE];

    // read all FIFO messages
    fifoLevel = SCI_getRxFIFOStatus(IRIS_UART_USB_BASE);

    if (fifoLevel > 0)
    {
        SCI_readCharArray(IRIS_UART_USB_BASE, (uint16_t*)rxBuf, fifoLevel);

        // Lock-free ring queue pushed into the protocol stack (very fast, O(1))
        gmp_dev_dl_push_str(&dl, rxBuf, fifoLevel);
    }
}

interrupt void INT_IRIS_UART_USB_RX_ISR(void)
{
    flush_dl_rx_buffer();

    //
    // deal with overrun
    //
    if (SCI_getRxStatus(IRIS_UART_USB_BASE) & SCI_RXSTATUS_OVERRUN)
    {
        SCI_clearOverflowStatus(IRIS_UART_USB_BASE);
    }

    //
    // Clear interrupt flags
    //
    SCI_clearInterruptStatus(IRIS_UART_USB_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INT_IRIS_UART_USB_RX_INTERRUPT_ACK_GROUP);
}

////

//=========================================================
// 1. SPI ��д�ײ㺯����װ
//=========================================================

// �� FPGA д��Ĵ���?
// Э��: ֡1=[15λ=1(д), 14:8=��ַ, 7:0=����] -> ֡2=[16λ����]
void SPI_writeReg(uint16_t addr, uint16_t data)
{
    // ����д������λ�?0
    uint16_t cmd = 0x0000 | ((addr & 0x7F) << 8); // ���λ��Ȼ��?0

    // ������ 16-bit word ѹ�� TX FIFO ����
    SPI_writeDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE, cmd);
    SPI_writeDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE, data);

    // �ȴ� FPGA ���ղ��������� 16-bit word
    // ��Ȼ��д���������� SPI ȫ˫�����յ��Է����صķ�����
    while(SPI_getRxFIFOStatus(IRIS_SPI_FPGA_BRIDGE_BASE) < SPI_FIFO_RX2);

    // �ѽ��յ��������������ݶ��������?RX FIFO����ֹӰ�����ͨ��?
    SPI_readDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE);
    SPI_readDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE);
}

// �� FPGA ��ȡ�Ĵ���
// Э��: ֡1=[15λ=0(��), 14:8=��ַ, 7:0=����] -> ֡2=[16λռλ������(0x0000)]
uint16_t SPI_readReg(uint16_t addr)
{
    // �����������λΪ 1
    uint16_t cmd = 0x8000 | ((addr & 0x7F) << 8); // ǿ�ư����λ����?
    uint16_t dummy_data = 0x0000; // ���ڲ���ʱ�ӵ�������

    // ѹ������֡������֡
    SPI_writeDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE, cmd);
    SPI_writeDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE, dummy_data);

    // �ȴ����� 2 ����
    while(SPI_getRxFIFOStatus(IRIS_SPI_FPGA_BRIDGE_BASE) < SPI_FIFO_RX2);

    // �����ĵ�һ�����Ƿ�������֡ʱ FPGA ���صģ�ͨ����״̬λ��ȫ0��ֱ�Ӷ�����
    SPI_readDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE);

    // �����ĵڶ����ֲ�������Ҫ����ʵ����֡
    uint16_t read_data = SPI_readDataBlockingFIFO(IRIS_SPI_FPGA_BRIDGE_BASE);

    return read_data;
}

