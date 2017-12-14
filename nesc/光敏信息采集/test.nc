//ADSensorAppC
configuration ADSensorAppC
{

}

implementation
{
    components ADSensorC;
    components new AdcC() as ADSensor;
    ADSnesorC.ADSensorControl -> ADSensor;
    ADSensorC.ADSensorRead -> ADSensor;
    components MainC;
    ADSensorC.Boot -> MainC.Boot;
    components new TimerMilli() as SensorTimerC;
    ADSensor.SensorTiemr -> SensorTimerC;
    components PlatformSerialC;
    ADSensor.StdControl -> PlatformSerialC.StdControl;
    ADsensor.UartControl -> PlatformSerialC.UartStream;
}

//ADSensorC
#include "Adc.h"

module ADSensorC
{
    uses
    {
        interface Boot;
        interface AdcControl as ADSensorControl;
        interface Read<int16_t> as ADSensorRead;
        interface Timer<TMilli> as SensorTimer;
        interface UartStream;
        interface StdControl;
    }
}

implementation
{
    uint8_t m_len;
    uint8_t m_send_buf[2];

    task void sensorTask()
    {
        call ADSensorControl.enable(ADS_REF_AVDD,ADS_14_BIT,ADS_AIN7);
        call ADSensorRead.read();
    }

    event void Boot.booted()
    {
        call SensorTimer.startPeriodic(1000);
        call StdControl.start();
    }

    event void SensorTiemr.fired()
    {
        post sensorTask();
    }

    event void ADSensorRead.readDone(error_t result, int16_t val)
    {
        m_sent_buf[0] = val >> 8;
        m_sent_buf[1] = val & 0x00ff;
        call UartStream.send(m_send_buf,2);
    }

    event void UartStream.sendDone(uint8_t *buf, uint16_t len,error_t error)
    {

    }

    event void UartStream.receivedByte(uint8_t byte)
    {

    }

    event void UartStream.receiveDone(uint8_t *buf,uint16_t len,error_t error)
    {

    }
}