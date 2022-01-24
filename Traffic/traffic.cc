#include "traffic.h"

Traffic::Traffic(sc_module_name name)
  : sc_module(name)
{
  lights[0].initialize(0); //N
  lights[1].initialize(0); //S
  lights[2].initialize(0); //W
  lights[3].initialize(0); //E


  SC_METHOD(turn_on_lights);
  dont_initialize();
  sensitive << cars[0] << cars[1] << cars[2] << cars[3];
}

void Traffic::turn_on_lights()
{
    bool N,S,W,E;
    N = cars[0]; S = cars[1]; W = cars[2]; E = cars[3];

    if(N)
    {
        if( lights[2] == false && lights[3] == false)
        lights[0] = true;
    }
    else if(W)
    {
        if( lights[0] == false && lights[1] == false)
        lights[2] = true;
    }
    else if(S)
    {
        if( lights[2] == false && lights[3] == false)
        lights[1] = true;
    }
    else if(E)
    {
        if( lights[0] == false && lights[1] == false)
        lights[3] = true;
    }
    else
    {
        lights[0] = false;
        lights[2] = false;
        lights[1] = false;
        lights[3] = false;
    }
}
