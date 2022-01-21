#include <iostream>
#include "traffic.h"
using std::cout;
using std::endl;

Traffic::Traffic(sc_module_name name) : sc_module(name)
{
    light_N.initialize(false);
    light_S.initialize(false);
    light_W.initialize(false);
    light_E.initialize(false);

    SC_METHOD(car_arriving);
    dont_initialize();
    sensitive << N << S << E << W;
}

void Traffic::car_arriving()
{
    if(N)
    {
        if( light_W == false && light_E == false)
        light_N = true;
    }
    else if(W)
    {
        if( light_N == false && light_S == false)
        light_W = true;
    }
    else if(S)
    {
        if( light_W == false && light_E == false)
        light_S = true;
    }
    else if(E)
    {
        if( light_N == false && light_S == false)
        light_E = true;
    }
    else
    {
        light_N = false;
        light_W = false;
        light_S = false;
        light_E = false;
    }
}
