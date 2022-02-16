#include <systemc.h>
#include "traffic.h"
#include "input_gen.h"
#include "monitor.h"

int sc_main(int argc, char **argv)
{
  // The command-line arguments are as follows:
  // 1. the simulation time (in seconds),
  // 2. the file with input data (see input.txt), and
  // 3. the file to write output data.
  assert(argc == 4);

  sc_time sim_time(atof(argv[1]), SC_SEC);
  char *infile = argv[2];
  char *outfile = argv[3];

  // Create channels.
 sc_signal<bool> Sig_cars[4];
 sc_signal<bool> Sig_lights[4];

  // Instantiate modules.
  Traffic traffic("traffic");
  Generator gen("Generator", infile);
  Monitor monitor("Monitor", outfile);

  // Connect the channels to the ports.
  traffic(Sig_cars[0], Sig_cars[1],Sig_cars[2],Sig_cars[3], Sig_lights[0], Sig_lights[1],Sig_lights[2],Sig_lights[3]);

  gen(Sig_cars[0], Sig_cars[1],Sig_cars[2],Sig_cars[3] );

  monitor(Sig_cars[0], Sig_cars[1],Sig_cars[2],Sig_cars[3], Sig_lights[0], Sig_lights[1],Sig_lights[2],Sig_lights[3]);

  // Start the simulation.
  sc_start(sim_time);

  return 0;
}
