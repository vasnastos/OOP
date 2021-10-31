#include "racing.hpp"

int main(int argc,char **argv)
{
    std::vector <std::string> names{"Blitz","Bolt","Goliath","Hercules","Rogue","Danger","Raider","Storm","Nitro","Hulk"};
    racing rc(5,names,10);
    rc.auto_race();
    rc.print_ranks();
    return EXIT_SUCCESS;    
}