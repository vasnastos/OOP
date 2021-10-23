#include "cargo.hpp"
#include <vector>
#include <random>
#include <chrono>

std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    std::vector <std::string> destinations{
        "Athens",
        "Paris",
        "Thessaloniki",
        "London",
        "Madrid",
        "Warsow",
        "Berlin"
    };

    auto dest_genarator=std::uniform_int_distribution<int>(0,destinations.size()-1);
    auto frag=std::uniform_int_distribution<int>(0,1);
    auto weight_genarator=std::uniform_real_distribution<double>(10,2000);
    std::vector <Cargo> cargos;
    std::string destination;
    for(int i=1;i<=5;i++)
    {
        destination=destinations.at(dest_genarator(mt));
        cargos.emplace_back(Cargo(i,destination,weight_genarator(mt),bool(frag(mt))));
    }

    for(auto &cargo:cargos)
    {
        cargo.show();
        cargo.make_safe();
    }
    for(auto &cargo:cargos)
    {
        cargo.show();
    }
}