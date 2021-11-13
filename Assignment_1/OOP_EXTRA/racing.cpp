#include "racing.hpp"

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

Racing::Racing(int number_of_horses,int number_of_rounds):n_horses(number_of_horses),rounds(number_of_rounds)
{
    auto random_value=uniform_int_distribution<int>(50,100);
    vector <string> names{"Blitz","Bolt","Goliath","Hercules","Rogue","Danger","Raider","Storm","Nitro","Hulk"};
    shuffle(names.begin(),names.end(),default_random_engine(chrono::steady_clock::now().time_since_epoch().count()));
    for(int i=0;i<this->n_horses;i++)
    {
        horses.push_back(horse(i+1,names[i],random_value(mt),random_value(mt),random_value(mt)));
        position.push_back(0);
    }
}

Racing::~Racing() {}

void Racing::drawing()
{
    for(int i=0;i<this->horses.size();i++)
    {
        cout<<"|";
        for(int j=0;j<this->rounds;j++)
        {
            if(position[i]==j)
            {
                cout<<i;
            }
            cout<<".";
        }
        cout<<"|"<<endl;
    }
}