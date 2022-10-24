#include <iostream>
#include <random>
#include <chrono>

using namespace std::chrono;
using namespace std;

mt19937 engine(steady_clock::now().time_since_epoch().count());
// Epoch time 01/01/1970(Point zero)

int main(int argc,char **argv)
{
    auto selector=uniform_int_distribution<int>(0,argc-1);
    if(argc!=1)
    {
        cout<<"Values inserted from command line("<<argv[0]<<"):"<<argc<<endl;
        cout<<"**********************************"<<endl;
        for(int i=1;i<argc;i++)
        {
            cout<<i<<"."<<argv[i]<<endl;
        }
    }
    else
    {
        cout<<"No command line argument passed"<<endl;
    }
    std::cout<<"Random value from command line arguments selected:"<<argv[selector(engine)]<<endl;
    return EXIT_SUCCESS;
}

// Compilation
// g++ command_line_arguments.cpp -o cma
// cma Blitz Bolt Goliath Hercules Rogue Danger Raider Storm Nitro Hulk
