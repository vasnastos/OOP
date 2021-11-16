#include <iostream>

using namespace std;

void press_enter()
{
    #ifdef __WIN32__
    system("pause");
    #else
    cout<<"Press [Enter] to continue....";
    cin.get();
    #endif
}