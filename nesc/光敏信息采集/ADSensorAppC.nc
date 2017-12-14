configuration ADSensorAppC
{

}

implementation
{
    components ADSensorC;
    components new AdcC() as ADSensor;
    ADSensorC.ADSensorControl -> ADSensor;
    ADSensorC.ADSensorRead -> ADSensor;
    components MainC;
    ADSensorC.Boot -> MainC.Boot;
    components new TimerMilliC() as SensorTimerC;
    components PlatformSerialC;
    ADSensorC.StdControl -> PlatformSerialC.StdControl;
    ADSensorC.UartStream -> PlatformSerialC.UartStream;
}

