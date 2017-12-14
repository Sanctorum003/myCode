#include <Timer.h>
#include "BlinkToRadio.h"//定义串口传送的周期以及要传送消息的结构体

module BlinkToRadioC
{
    uses
    {
        interface Boot;
        interface Timer<TMilli> as Timer0;

        interface Packet;
        interface AMPacket;
        interface AMSend;
        interface SplitControl as AMControl;
        interface Receive;
        interface PacketAcknowledgements;
    }
}

implementation
{
    bool busy = FALSE;
    message_t pkt;
    uint16_t counter = 0;

    event void Boot.booted()
    {
        busy = FALSE;
        call AMControl.start();
    }

    event void AMControl.startDone(error_t err)
    {
        if(err == SUCCESS)
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

    event void Timer.fired()
    {/*定时事件处理，发送数据*/
        if(!busy)
        {
            BlinkToRadioMsg *btrpkt;
            btrpkt  = (BlinkToRadioMsg *)call Packet.getPayload(&pkt, sizeof(BlinkToRadioMsg));
            btrpkt->nodeid = TOS_NODE_ID;
            btrpkt->counter = counter++;
            if(call ANSend(AM_BROADCAST_ADDR,&pkt,sizeof(BlinkToRadioMsg)) == SUCCESS)
            {
                busy = true;
            }
        }
    }

    event vouid AMSend.sendDone(message_t* msg,error_t error)
    {/*发送完成后调用帧回复命令*/
        if(&pkt == msg)
        {
            call PacketAcknowledgements.request(msg);
            busy = FALSE;
        }
    }

    event message_t * Receive.receive(message_t * msg,void *payload ,uint8_t len)
    {
        if(len == sizeof(BlinkToRadioMsg))
        {
            BlinkToRadioMsg * btrpkt = (BlinkToRadioMsg *)payload;
        }

        return msg;
    }
}