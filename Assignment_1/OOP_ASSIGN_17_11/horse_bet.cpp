#include <iostream>
#include "racing.hpp"
#include <regex>

using namespace std;

int menu()
{
    cout<<"===== Menu ====="<<endl;
    cout<<"1.Display horses"<<endl;
    cout<<"2.Bet to a horse"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"================"<<endl;
    cout<<"Select:";
    int ch;
    cin>>ch;
    cout<<endl<<endl;
    return ch;
}

int select_horse(vector <horse> &horses)
{
    int j;
    cout<<"===== Horse Selection ====="<<endl;
    for(int i=0,t=horses.size();i<t;i++)
    {
        cout<<i+1<<"."<<horses[i]<<endl;
    }
    cout<<"Select:";
    cin>>j;
    cout<<endl<<endl;
    while(j<=0 || j>horses.size())
    {
        cout<<"Your provide an invallid index!!Try again"<<endl;
        cin>>j;
        cout<<endl<<endl;
    }
    return j-1;
}

int main(int argc,char **argv)
{
    int number_of_horses=4;
    int number_of_rounds=10;
    if(argc==3)
    {  
        number_of_horses=atoi(argv[1]);
        number_of_rounds=atoi(argv[2]);
    }
    Racing rc(number_of_horses,number_of_rounds);
    double money_amount;
    double betting_money;
    vector <horse> horses;
    vector <pair<horse,int>> standings;
    int choice;
    do
    {
        cout<<"Give your initial balance amount:";
        cin>>money_amount;
        if(cin.fail())
        {
            cerr<<"You provide an undefine money amount"<<endl;
            cin.clear();
            continue;
        }
    } while (money_amount<0 || money_amount>1000000);
    
    while(true)
    {
        cout<<"======= Money amount ========"<<endl;
        cout<<"Your Money:"<<money_amount<<endl<<endl;
        choice=menu();
        if(choice==1)
        {
            rc.display_horses();
        }
        else if(choice==2)
        {
            cout<<"==== Money Betting ===="<<endl;
            cout<<"Select your bet amount:";
            cin>>betting_money;
            cout<<endl<<endl;
            while(betting_money<=0 || betting_money>money_amount)
            {
                cout<<"Your amount["<<money_amount<<"]--Your betting["<<betting_money<<"]-->Please provide a valid betting amount[1-"<<money_amount<<"]:";
                cin>>betting_money;
            }
            horses=rc.get_horses();
            int horse_index=select_horse(horses);
            auto shorse=horses[horse_index];
            standings=rc.get_standings();
            auto horse_position=find_if(standings.begin(),standings.end(),[&](pair <horse,int> &p) {return shorse==p.first;})->second;
            if(horse_position==1)
            {
                money_amount+=betting_money*2;
            }
            else if(horse_position>3)
            {
                money_amount-=betting_money;
            }
            cout<<"==== Betting Result ====="<<endl;
            cout<<shorse<<"->"<<horse_position<<endl;
            cout<<"Money amount:"<<money_amount<<endl<<endl;
        }
        else{
            cout<<"Exiting Race!  Your final amount:"<<money_amount<<endl;
            exit(EXIT_SUCCESS);
        }
    }
}