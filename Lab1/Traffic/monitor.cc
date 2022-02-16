#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name, char *outfile)
  : sc_module(name)
{
  assert(outfile != 0);
  out = new ofstream(outfile);
  assert(*out);

  SC_THREAD(event_trigger_thread);

  SC_METHOD(monitor_method);
  dont_initialize();
  sensitive << cars[0] << cars[1] << cars[2] << cars[3] << lights[0] << lights[1] << lights[2] << lights[3];
  sensitive << count_event;

}

Monitor::~Monitor()
{
  delete out;
}

void Monitor::monitor_method()
{
  *out << "Cars  (" << sc_time_stamp() << ") = ";
  for (int i{}; i < 4; i++)
  {
      *out << cars[i] << ", ";
  }

  *out << "\nLights(" << sc_time_stamp() << ") = ";
  for (int i{}; i < 4; i++)
  {
      *out << lights[i] << ", ";
  }

  if( (lights[0] || lights[1]) && (lights[2] || lights[3] ) ) //checks if NS are on at the same time as WE
  {
      *out << "ERROR";
  }
  assert( !((lights[0] || lights[1]) && (lights[2] || lights[3] )) );
  *out << '\n' << std::endl;
}

void Monitor::event_trigger_thread()
{
    for (;;) {               // Loop infinitely.
    wait(1, SC_SEC);       // Wait one second.
    count_event.notify();  // Trigger count_method.
  }
}
