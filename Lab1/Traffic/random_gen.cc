#include <random>
#include <fstream>
#include <cassert>

using std::ofstream;

int main(int argc, char **argv)
{

    assert( argc == 2); // 1 inputs
    int rows = atof(argv[1]);

    ofstream out;
    out.open( "input/random.txt");

    bool rand_val;
    for(int i{}; i<rows; i++)
    {
        for(int j{}; j<4; j++)
        {
            rand_val = rand() & 0x01;
            out << rand_val << " ";
        }
        out << "\n";
    }

    out.close();
}
