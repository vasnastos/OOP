#include "racing.hpp"
#include <regex>

double amount_of_money()
{
    double am;
    cout<<"======= Input Amount ========="<<endl;
    cout<<"Give User initial amount:";
    cin>>am;
    cout<<endl<<endl;
    return am;
}

int menu()
{
    int input;
    cout<<"====== Menu ======"<<endl;
    cout<<"1.Display horses"<<endl;
    cout<<"2.Bet on a horse"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"=================="<<endl;
    cout<<"Select:";
    cin>>input;
    cout<<endl<<endl;
    return input;
}

int horse_selection(vector <horse> &horses)
{
    cout<<"========= Horse Selection ==========="<<endl;
    for(int i=0,t=horses.size();i<t;i++)
    {
        cout<<i+1<<"."<<string(horses[i])<<endl;
    }
    cout<<"====================================="<<endl;
    cout<<"Select:";
    int choice;
    cin>>choice;
    cout<<endl;
    return choice;
}

void display_amount(double am)
{
    cout<<"================="<<endl;
    cout<<"Amount of money:"<<am<<endl;
    cout<<"================="<<endl<<endl;
}

int main(int argc,char *argv[])
{
    int number_of_horses=4;
    int number_of_rounds=10;
    if(argc==3)
    {
        regex r("/d+");
        string val1=argv[1];
        string val2=argv[2];
        if(!regex_match(val1,r) || !regex_match(val2,r))
        {
            cerr<<"You did not provide the right amount of arguments["<<val1<<"--"<<val2<<"]"<<endl;
            exit(EXIT_FAILURE);
        }
        number_of_horses=stoi(val1);
        number_of_rounds=stoi(val2);
    }
    Racing rc(number_of_horses,number_of_rounds);
    double money_amount;
    int a_menu;
    int horse_choice;
    double money_betting;
    vector <horse> race_horses;
    vector <pair<horse,int>> standings;
    do
    {
        money_amount=amount_of_money();
    } while (money_amount<0 || money_amount>1000000);
    while(true)
    {
        a_menu=menu();
        if(a_menu==1)
        {
            rc.display_horses();
        }
        else if (a_menu==2)
        { 
            race_horses=rc.get_horses();
            cout<<"====== Money Bet ======"<<endl;
            cout<<"Give money you want to bet:";
            cin>>money_betting;
            cout<<endl<<endl;
            while(money_betting<0 || money_betting>money_amount)
            {
                cout<<"===== Transaction Error ====="<<endl;
                cout<<"Your betting balance is ["<<money_betting<<"]> your amount is["<<money_amount<<"]"<<endl;
                cout<<"Invallid transaction!! Try again"<<endl<<endl;
                cout<<"(The money you bet should be lower thna your total amount)|Give money you want to bet:";
                cin>>money_betting;
                cout<<endl<<endl;
            }
            horse_choice=horse_selection(race_horses);
            auto horse_selected=race_horses[horse_choice-1];
            rc.race();
            standings=rc.get_standings();
            auto selected_horse_position=find_if(standings.begin(),standings.end(),[&](pair <horse,int> &p) {return p.first==horse_selected;})->second;
            if(selected_horse_position==1)
            {
                money_amount+=money_betting*2;
            }
            else if(selected_horse_position<3)
            {
                money_amount-=money_betting;
            }
            display_amount(money_amount);
        } 
        else{
            cout<<"Exit Race:Your final amount:"<<money_amount<<endl;
            break;
        }
    }
    return EXIT_SUCCESS;
}