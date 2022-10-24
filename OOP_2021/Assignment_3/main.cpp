#include "vending_machine.hpp"
#pragma character_execution_set("utf-8")
#ifdef _WIN32
    #include <windows.h>
#endif

int menu()
{
    system("cls");
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    int choice;
    cout<<"1. Καφές 1.5 ευρώ"<<endl;
    cout<<"2. Καφές με γάλα 1.8 ευρώ"<<endl;
    cout<<"3. Σοκολάτα 2.1 ευρώ"<<endl;
    cout<<"4. Σοκολάτα με γάλα 2.4 ευρώ"<<endl;
    cout<<"5. Τροφοδότηση(καφές, γάλα, σοκολάτα)"<<endl;
    cout<<"-1. Έξοδος"<<endl;
    cout<<"Διάλεξε ρόφημα:";
    cin>>choice;
    cout<<endl<<endl;
    return choice;
}   

int main()
{
    vector <double> coins={0.1,0.2,0.5,1.0,2.0,5.0,10.0};
    VendingMachine vm(coins);
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    #endif
    int selection;
    string product;
    bool has_milk;
    while(true)
    {
        selection=menu();
        switch(selection)
        {
            case 1:
                product="Coffee";
                has_milk=false;
                vm.payout(product,has_milk);
                break;
            case 2:
                product="Coffee";
                has_milk=true;
                vm.payout(product,has_milk);
                break;
            case 3:
                product="Chocolate";
                has_milk=false;
                vm.payout(product,has_milk);
                break;
            case 4:
                product="Chocolate";
                has_milk=true;
                vm.payout(product,has_milk);
                break;
            case 5:
                vm.refill();
                break;
            case -1:
                cout<<vm<<endl;
                exit(EXIT_SUCCESS);
                break;
        }
        
    }
}