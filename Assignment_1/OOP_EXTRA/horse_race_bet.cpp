#include "racing.hpp"

int main()
{
    int number_of_horses=8;
    int number_of_rounds=10;
    double money_amount;
    do {
        cout<<"Give user's money amount:";
        cin>>money_amount;
        cout<<endl;
    }while(money_amount<0 || money_amount>1000000);
    cout<<"User money amount set to-->"<<money_amount<<endl<<endl;

    // ------
    vector <horse> race_horses;
    int choice;
    double bet_amount;
    while(true)
    {
        Racing rc(number_of_horses,number_of_rounds);
        race_horses=rc.get_horses();
        cout<<"====== Select Horse ======"<<endl;
        for(int i=0;i<race_horses.size();i++)
        {
            cout<<i<<"."<<race_horses[i]<<endl;  
        }
        cout<<"Select a Horse:";
        cin>>choice;
        cout<<endl;

        // Αν ο χρήστης θέλει να ποντάρει χρήματα

        cout<<"==== Place a Bet ===="<<endl;
        cout<<"Place your bet:";
        cin>>bet_amount;
        rc.auto_race();
        break;

    }
    return EXIT_SUCCESS;
}