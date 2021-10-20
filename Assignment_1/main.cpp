#include "racing.hpp"

void scenario_1()
{
    racing rc(4,10);
    rc.print_race();
    press_any_key();
    rc.game_started();
}

void scenario_2()
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue", "Danger", "Raider", "Storm", "Nitro", "Hulk"};
    racing rc(names,10);
}

void scenario_3()
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue", "Danger", "Raider", "Storm", "Nitro", "Hulk"};
    racing rc(names,10);
    rc.game_automatically_executed();
}

int main()
{
    // scenario_1();
    // scenario_2();
    scenario_3();
}