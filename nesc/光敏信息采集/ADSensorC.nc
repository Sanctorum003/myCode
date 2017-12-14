#include "Adc.h"

module ADSensorC
{
    uses
    {
        interface Boot;
        interface AdcControl as ADSensorControl;
        interface Read<int16_t> as ADSensorRead;
        interface Timer<TMilli> as SensorTimer;
        interface StdControl;
        interface UartStream;
    }
}

implementation
{
    uint8_t m_len;
    uint8_t m_send_buf[2];

    task void SensorTask()
    {
        call ADSensorControl.enable(ADC_REF_AVDD,ADC_14_BIT,ADC_AIN7);
        call ADSensorRead.read();
    }

    event void Boot.booted()
    {
        call SensorTimer.startPeriodic(1000);
        call StdControl.start();
    }

    event void SensorTimer.fired()
    {
        post sensorTask();
    }

    event void ADSensorRead.readDone(error_t result,int16_t val)
    {
        m_send_buf[0] = val>>8;
        m_send_buf[1] = val && 0x00ff;
        call UartStream.send(m_send_buf,2);
    }

    async event void UartStream.sendDone(uint8_t *buf,uint16_t len,error_t error)
    {

    }

    async event void UartStream.receivedByte(uint8_t byte)
    {

    }

    async event void UartStream.receiveDone(uint8_t *buf,uint16_t len,error_t error)
    {
        
    }
}