#include "input_gen.h"

Generator::Generator(sc_module_name name) : sc_module(name)
{
    SC_THREAD(generate_cars);

    car_N.initialize(false);
    car_S.initialize(false);
    car_W.initialize(false);
    car_E.initialize(false);


}

void Generator::generate_cars()
{
    int random_num{0};
    bool random_bool{false};
    for(;;)
    {
        wait(2, SC_SEC); //wait 2 sec
        random_num = rand() % 2;
        random_bool= static_cast<bool>( random_num );
        if( !car_N)
            car_N = random_bool;


    }
}
