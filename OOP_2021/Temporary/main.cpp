#include <iostream>
#include <windows.h>
#include "vending_machine.hpp"
using namespace std;

// 1. Καφές 1.5 ευρώ
// 2. Καφές με γάλα 1.8 ευρώ
// 3. Σοκολάτα 2.1 ευρώ
// 4. Σοκολάτα με γάλα 2.4 ευρώ
// 5. Τροφοδότηση (καφές, σοκολάτα και γάλα)
// ‐1. Έξοδος

int menu()
{
    system("cls");
    int choice;
    cout<<"=== ΛΙΣΤΑ ΕΠΙΛΟΓΩΝ ==="<<endl;
    cout<<" 1. Καφές 1.5 ευρώ"<<endl;
    cout<<" 2. Καφές με γάλα 1.8 ευρώ"<<endl;
    cout<<" 3. Σοκολάτα 2.1 ευρώ"<<endl;
    cout<<" 4. Σοκολάτα με γάλα 2.4 ευρώ"<<endl;
    cout<<" 5. Τροφοδότηση (καφές, σοκολάτα και γάλα)"<<endl;
    cout<<"‐1. Έξοδος"<<endl;
    cout<<"Διάλεξε επιλογή:";
    cin>>choice;
    return choice;
}

int main(int argc,char **argv)
{
    SetConsoleOutputCP(65001);
    int pchoice;
    bool exit_flag=false;
    string product;
    bool has_milk;
    VendingMachine vm;
    while(true)
    {
        pchoice=menu();
        switch(pchoice)
        {
            case 1:
                product="coffee";
                has_milk=false;
                vm.payout(product,has_milk);
                break;
            case 2:
                product="coffee";
                has_milk=true;
                vm.payout(product,has_milk);
                break;
            case 3:
                product="chocolate";
                has_milk=false;
                vm.payout(product,has_milk);
                break;
            case 4:
                product="chocolate";
                has_milk=true;
                vm.payout(product,has_milk);
                break;
            case 5:
                cout<<"refill"<<endl;
                break;
            case -1:
                exit_flag=true;
                break;
            default:
                cerr<<"Η επιλογή "<<pchoice<<" δεν είναι διαθέσιμη"<<endl;
                break;
        }
        if(exit_flag)
        {
            break;
        }
    }
    return EXIT_SUCCESS;
}