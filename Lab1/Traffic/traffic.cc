#include "traffic.h"

Traffic::Traffic(sc_module_name name)
  : sc_module(name)
{
  lights[0].initialize(0); //N
  lights[1].initialize(0); //S
  lights[2].initialize(0); //W
  lights[3].initialize(0); //E

  SC_THREAD(trigger_timer);

  SC_METHOD(turn_on_lights);
  dont_initialize();
  sensitive << cars[0] << cars[1] << cars[2] << cars[3];
  sensitive << trigger_event;
}

void Traffic::trigger_timer()
{
    for (;;)
    {
    wait(1, SC_SEC);
    trigger_event.notify();
    }
}
void Traffic::turn_on_lights()
{
    bool N,S,W,E;
    N = cars[0]; S = cars[1]; W = cars[2]; E = cars[3];

    // DEFAULT: turn off lights
    lights[0] = false;
    lights[1] = false;
    lights[2] = false;
    lights[3] = false;

    if(  (N || S) && !(W||E) )  //fast-track as to not slow down if coast is clear
    {
        lights[0] = N;
        lights[1] = S;
    }
    else if(  (W || E) && !(N||S) )  //fast-track as to not slow down if coast is clear
    {
        lights[2] = W;
        lights[3] = E;
    }
    else if( (N || S ) && timer) //to prevent gridlock in direction
    {
        lights[0] = N;
        lights[1] = S;

    }
    else if( ( W || E) && (!timer) )
    {
        lights[2] = W;
        lights[3] = E;

    }
    timer = !timer; // boolean timer to prevent N/S direction having constant priority
}
