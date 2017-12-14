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

    event void AMControl.startDone(error_t err)
    {
        if(err == SUCEESS)
        {
            call Timer0.startPeriodic(TIMER_PERIOD_MILLI);
        }
        else
        {
            call AMControl.start();
        }
    }

    event void AMControl.stopDone(error_t err)
    {

    }

    event void Timer0.fired()
    {
        if(!busy)
        {
            BlinkToRadioMsg *btrpkt;
            btrpkt = (BlinkToRadioMsg *)call Packet.getPayload(&pkt, sizeof(BlinkToRadioMsg));
            btrpkt->nodeid = TOS_NODE_ID;
            btrpkt->counter = counter++;
            if(call AMSend.send(AM_BROADCAST_ADDR,&pkt,sizeof(BlinkToRadioMsg))== SUCEESS)
            {
                busy = TRUE;
            }
        }
    }

    event void AMSend.sendDone(message_t *msg,error_t error)
    {
        if(&pkg == msg)
        {
            call PacketAcknowledgements.requestAck(msg);
            busy = FALSE;
        }
    }

    event message_t Receive.receive(message_t *msg,void *payload,uint8_t len)
    {
        if(len == sizeof(BlinkToRadioMsg))
            BlinkToRadioMsg *btrpkt = (BlinkToRadioMsg *)payload;

        return msg;
    
    }
}