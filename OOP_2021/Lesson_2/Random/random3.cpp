#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed);
    mt19937 generator_steady(1821);

    cout << "mt19937 generator seeds examples" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << generator();
        cout << "\t" << generator_steady() << endl;
    }

    cout << endl
         << "Uniform int distribution examples" << endl;
    uniform_int_distribution<int> dist_int(0, 9);
    for (int i = 0; i < 5; i++)
    {
        cout << dist_int(generator) << "\t" << dist_int(generator_steady) << endl;
    }

    cout << endl
         << "Uniform real distribution examples" << endl;
    uniform_real_distribution<double> dist_real(0, 9);
    for (int i = 0; i < 5; i++)
    {
        cout << dist_real(generator) << "\t" << dist_real(generator_steady) << endl;
    }
}