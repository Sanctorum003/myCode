configuration DhSerialAppC
{

}

implementation
{
    components DhSerialC;
    components MainC;
    DhSerialC.Boot -> MainC.Boot;
    components PlatformSerialC; 
    DhSerialC.StdControl -> PlatformSerialC.StdControl;
    DhSerialC.UartStream -> PlatformSerialC.UartStream;
}