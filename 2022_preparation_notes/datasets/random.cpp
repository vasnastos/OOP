#include <random>
#include <chrono>
#include <fstream>
#include <sstream>
using namespace std;
using namespace std::chrono;

mt19937 mt(high_resolution_clock::now().time_since_epoch().count());

double rand_grade()
{
    uniform_real_distribution <double> rr(0,10);
    return rr(mt);
}