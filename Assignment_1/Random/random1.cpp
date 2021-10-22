#include <iostream>
#include <chrono>
#include <random>

int main()
{
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    // std::mt19937 mt1(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    const int bound1=10;
    const int bound2=100;
    auto rf=std::uniform_int_distribution<int>()
}