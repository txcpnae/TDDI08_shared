#ifndef Traffic_H
#define Traffic_H

#include <systemc.h>

SC_MODULE(Traffic) {
  sc_in<bool> cars[4];
  sc_out<bool> lights[4];
  bool timer; // to remove bias of N/S
  sc_event trigger_event;

  SC_HAS_PROCESS(Traffic);
  Traffic(sc_module_name name);

  void turn_on_lights();

  void trigger_timer(); //checks inputs every 100ms
};

#endif // Traffic
