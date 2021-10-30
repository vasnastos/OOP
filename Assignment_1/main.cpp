#include "racing.hpp"

void scenario_1()
{
    racing rc(4,10);
}

void scenario_2()
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue", "Danger", "Raider", "Storm", "Nitro", "Hulk"};
    racing rc(names,10);
}

int main()
{
    // scenario_1();
    // scenario_2();
}