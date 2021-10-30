#include "racing.hpp"

void scenario_1()
{
    racing rc(4,10);
    rc.race();
}

void scenario_2()
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue", "Danger", "Raider", "Storm", "Nitro", "Hulk"};
    racing rc(names,10);
    rc.auto_race();
}

int main()
{
    // scenario_1();
    scenario_2();
    return EXIT_SUCCESS;
}