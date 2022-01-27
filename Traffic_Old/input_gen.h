#ifndef INPUT_GEN_H
#define INPUT_GEN_H

#include <systemc.h>
#include <random>


SC_MODULE(Generator) {
  sc_out<bool> car_N, car_S, car_W, car_E;
  sc_in<bool>  Light_N, Light_S, Light_W, Light_E;

  SC_HAS_PROCESS(Generator);
  Generator(sc_module_name name);
  

  void generate_cars();

};

#endif // INPUT_GEN_H
