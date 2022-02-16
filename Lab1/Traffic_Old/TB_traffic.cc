#include <cassert>
#include <array>
#include <systemc.h>
#include "traffic.h"
#include "input_gen.h"
int sc_main(int argc, char **argv)
{
  // The command-line arguments are as follows:
  // 1. the initial value of the counter and
  // 2. the simulation time (in seconds).
  assert(argc == 2);

  sc_time sim_time(atof(argv[1]), SC_SEC);
  // Signals
  sc_signal<bool> sensors[4];
  sc_signal<bool> actuators[4];
  //sc_signal<bool>  Light_N_sig, Light_S_sig, Light_W_sig, Light_E_sig;
  // Instantiate the module.
  Traffic T1("trafficlights");
  Generator G1("generator");
  // Connect wires
  T1(sensors[0],sensors[1], sensors[2], sensors[3], actuators[0], actuators[1], actuators[2], actuators[3]);
  G1(sensors[0],sensors[1], sensors[2], sensors[3], actuators[0], actuators[1], actuators[2], actuators[3]);
  // Start the simulation.
  sc_start(sim_time);

  return 0;
}
