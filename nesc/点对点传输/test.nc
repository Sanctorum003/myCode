implementation
{
    bool busy = FALSE;
    message_t pkt;
    uint16_t counter;

    event void Boot.booted()
    {
        busy = FALSE;
        call AMControl.start();
    }

    event void 
}