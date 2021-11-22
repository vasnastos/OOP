#include "bet.hpp"

Bet_App::Bet_App():money_amount(0),rc(new Racing(8,10))
{

}

Bet_App::~Bet_App()
{
    delete this->rc;
}

istream &operator>>(istream &is,Bet_App &ba)
{
    cout<<"==== Bet User Insertion ===="<<endl;
    cout<<"Insert money amount:";
    is>>ba.money_amount;
    cout<<endl<<endl;
    return is;
}

void Bet_App::betting()
{
    vector <horse> race_horses;
    int choice;
    double bet_amount;
    vector <pair <horse,int>> standings;
    string answer,message,outcome;
    int wins=0,loses=0,no_money_loss=0;
    while(true)
    {
        cout<<"==== Place Bet ===="<<endl;
        cout<<"Place your bet:";
        cin>>bet_amount;
        while(bet_amount<0 || bet_amount>this->money_amount)
        {
            cout<<"Betting price should be between [1-"<<this->money_amount<<"]:";
            cin>>bet_amount;
        }
        cout<<endl;
        race_horses=this->rc->get_horses();
        cout<<"===== Select Horse ====="<<endl;
        for(int i=0,t=race_horses.size();i<t;i++)
        {
            cout<<i+1<<"."<<race_horses[i]<<endl;
        }
        cout<<"Select horse:";
        cin>>choice;
        cout<<endl;
        rc->race(true);
        standings=this->rc->get_standings();
        auto position=find_if(standings.begin(),standings.end(),[&](pair <horse,int> &p) {return p.first==race_horses[choice-1];})->second;
        message="Horse:"+race_horses[choice-1].get_name()+" Bet Amount:"+to_string(bet_amount);
        if(position==1)
        {
            outcome="Bet_Status:Winning";
        }
        else if(position<=3)
        {
            outcome="Bet_Status:Money Back";
        }
        else 
        {
            outcome="Bet_Status:Losing";
        }
        this->bets.push_back(make_pair(message,outcome));
        if(position==1)
        {
            this->money_amount+=bet_amount*2;
            wins++;
        }
        else if(position>3)
        {
            this->money_amount-=bet_amount;
            loses++;
        }
        else{
            no_money_loss++;
        }
        cout<<endl<<"====== User Round Summary ======"<<endl;
        cout<<"* User's amount:"<<this->money_amount<<endl;
        cout<<"* User's winning bets:"<<wins<<endl;
        cout<<"* User's no money loss bets:"<<no_money_loss<<endl;
        cout<<"* User's money loss bets:"<<loses<<endl<<endl;

        cout<<"===== User's Next Choice ====="<<endl;
        cout<<"Do you want to continue to the next race(yes/no):";
        cin>>answer;
        for_each(answer.begin(),answer.end(),[](char &ch) {ch=tolower(ch);});
        while(answer!="yes" && answer!="no")
        {
            cout<<"Invallid choice!Do you to continue to the next race(yes/no):";
            cin>>answer;
        }
        if(answer=="no")
        {
            break;
        }
        this->rc->reset_race();
    }
    this->bet_summary();
    cout<<endl;
}

void Bet_App::bet_summary()
{
    cout<<endl<<"===== User's Summary ====="<<endl;
    cout<<"Money Amount:"<<this->money_amount<<endl;
    cout<<"-------"<<endl;
    for(auto &b:this->bets)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
}