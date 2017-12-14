module DhSerialC
{
    uses
    {
        interface Boot;
        interface StdControl;
        interface UartStream;
    }
}

implementation
{
    uint8_t m_send_buf[100];

    void showMenu()
    {
        strcpy(m_send_buf,"Sanctorum003");
        call UartStream.send(m_send_buf,strlen(m_send_buf));
    }

    event void Boot.booted()
    {
        call StdControl.start();
        showMenu();
    }

    async event void UartStream.sendDone(uint8_t *buf,uint16_t len, error_t error)
    {
    }

    task void showMneuTask()
    {
        showMenu();
    }

    async event void UartStream.receivedByte(uint8_t byte)
    {
    }

    async event void UartStream.receiveDone(uint8_t *buf, uint16_t len, error_t error)
    {
    }
    
}