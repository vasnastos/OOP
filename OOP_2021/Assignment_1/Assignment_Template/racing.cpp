#include "racing.hpp"

std::mt19937 mt1(std::chrono::high_resolution_clock::now().time_since_epoch().count());

racing::racing(int h,int rounds):rounds(rounds)
{
}

racing::racing(std::vector <std::string> &names,int rnds)
{

}

racing::~racing() {delete[] positions;}

void racing::race()
{
}

void racing::auto_race()
{
}

void racing::draw_race()
{

}


void press_any_key()
{
    #ifdef _WIN32
    system("pause");
    #else
    cout<<"Press any key....";
    cin.get();
    #endif
    cout<<endl<<endl;
}