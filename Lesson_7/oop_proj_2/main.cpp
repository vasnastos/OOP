#include "management.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
    SetConsoleOutputCP(65001);
    Management msystem;
    msystem.display_courses();
    msystem.load_sample();
    msystem.display();
}