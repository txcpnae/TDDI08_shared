#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name, char *datafile)
  : sc_module(name)
{
  assert(datafile != 0);       // An input file should be given.

  in = new ifstream(datafile); // Open the input file.
  assert(*in);                 // Check that everything is OK.

  SC_THREAD(generate_thread);
  sensitive << lights[0] << lights[1] << lights[2] << lights[3];
  cars[0].initialize(0);
  cars[1].initialize(0);
  cars[2].initialize(0);
  cars[3].initialize(0);

  //SC_METHOD(drive);
  //dont_initialize();
  //sensitive << lights[0] << lights[1] << lights[2] << lights[3];
}

Generator::~Generator()
{
  delete in;
}

void Generator::generate_thread()
{
    bool n[4];
    for (;;)
    {
        wait(1, SC_SEC);     // Generate new inputs every second.
        *in >> n[0] >> n[1] >> n[2] >> n[3]; // Read from the input file.

        for(int i{}; i<4; i++)
        {
            cars[i]->write(cars[i]->read() + n[i]);
            if(lights[i] == true)
            {
                //wait() to simulate car driving through intersection
                cars[i] = false;
            }

        }
    }
}
