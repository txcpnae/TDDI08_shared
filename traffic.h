#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <systemc.h>

SC_MODULE(Traffic) {
  sc_in<bool> N, S, W, E; //Sensors detecing cars
  sc_out<bool> light_N, light_S, light_W,light_E;

  SC_HAS_PROCESS(Traffic);
  Traffic(sc_module_name name);

  void car_arriving();
};

#endif // COUNTER_H
