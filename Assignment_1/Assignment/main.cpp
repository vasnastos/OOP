#include "racing.hpp"

void query_1()
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue","Danger","Raider","Storm","Nitro","Hulk"};
    racing rc(5,names,10);
    rc.auto_race();     
}

void query_2()
{
    racing rc(4,10);
    rc.race();
}

int main(int argc,char **argv)
{
    // query_1();
    query_2();
    return EXIT_SUCCESS;
}