#include "management.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
    SetConsoleOutputCP(65001);
    Management msystem;
    msystem.load_sample();
    msystem.display_courses();
    cout<<"=== ΦΟΙΤΗΤΕΣ ==="<<endl;
    vector <Student> students=msystem.get_students();
    for(int i=0,t=students.size();i<t;i++)
    {
        cout<<i<<"."<<students.at(i)<<endl;
    }
    int ch;
    cout<<"Διάλεξε φοιτητή:";
    cin>>ch;
    while(ch<0 || ch>=students.size())
    {
        cout<<"Επέλεξε ξανά μία από τις διαθέσιμες επιλογές[0-"<<students.size()-1<<endl;
    }
    system("cls");
    students.at(ch).display();
    return EXIT_SUCCESS;
}