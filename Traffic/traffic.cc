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


    if(W || E)
    {
      if(W)
      {
        if( lights[0] == false && lights[1] == false)
        lights[2] = true;
        else
        lights[2] = false;
      }
      if(E)
      {
          if( lights[0] == false && lights[1] == false)
          lights[3] = true;
          else
          lights[3] = false;
      }

        //cout << "nonono";

    }
    else if(N || S)
    {
      // lights[2] = false;
      // lights[3] = false;
      if(N)
      {
          // if(lights[2] == true)
          //   cout << "\n2yesagain";
          // if(lights[3] == false)
          //   cout << "\n3yesagain";
          if( lights[2] == false && lights[3] == false){
            lights[0] = true;
            //cout << "\nY";
          }
          else{
            lights[0] = false;
            //cout << "\nX";
          }
      }
      if(S)
      {
          if( lights[2] == false && lights[3] == false)
          lights[1] = true;
          else
          lights[1] = false;
      }
        //cout << "yesyes";
    }
    else{
      lights[0] = false;
      lights[2] = false;
      lights[1] = false;
      lights[3] = false;
    }

    // if(!N)
    // lights[0] = false;
    // if(!W)
    // lights[2] = false;
    // if(!S)
    // lights[1] = false;
    // if(!E)
    // lights[3] = false;
}
