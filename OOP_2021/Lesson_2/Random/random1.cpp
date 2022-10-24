#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    // std::mt19937 mt1(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    const int bound1=10;
    const int bound2=100;
    auto rf=uniform_int_distribution<int>(bound1,bound2);
    for(int i=0;i<10;i++)
    {
        cout<<rf(mt);
    }
    return EXIT_SUCCESS;
}