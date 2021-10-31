#include "racing.hpp"

int main()
{
    racing rc(4,10);
    rc.race();
    rc.print_ranks();
    return EXIT_SUCCESS;
}