//DhSerialAppC.nc
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

//DhSerialC.nc
module DhSerialC
{
    uses interface Boot;
    uses interface StdControl;
    uses interface UartStream;
}

implementation
{
    uint8_t m_send_buf[100];

    void showMenu()
    {
        strcpy(m_send_buf,"lsc");
        call  UartStream.send(m_send_buf,strlen(m_send_buf));//call
    }

    event void Boot.booted()
    {
        call StdControl.start();//call
        showMenu();
    }

    async event void UartStream.sendDone(uint8_t *buf, uint16_t len,error_t error)
    {

    }

    task void showMenuTask()
    {
        shownMenu();
    }

    async event void UartStream.receivedByte(uint8_t byte)//uint8_t byte
    {

    }

    async event void UartStream.receiveDone(uint8_t *buf,uint16_t len,error_t error)
    {

    }
}