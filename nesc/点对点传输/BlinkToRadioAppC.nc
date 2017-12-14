#include <Timer.h>
#include "BlinkToRadio.h"

configuration BlinkToRadioAppC
{

}

implementation
{
    components MainC;
    components BlinkToRadioC as App;
    components new TimerMilli() as Timer();
    components ActiveMessageC;

    App.Boot -> MainC.Boot;
    App.Timer0 -> Timer0;

    App.Packet -> ActiveMessageC;
    App.AMPacket -> ActiveMessageC;
    App.AMSend ->ActiveMessageC.AMSend[uniqueCount("BlinkToRadio")];
    App.AMControl -> ActiveMessageC;
    App.Receive -> ActiveMessageC.Receive[uniqueCount("BlinkToRadio")];
    App.PacketAcknowledgements -> ActiveMessageC;
}