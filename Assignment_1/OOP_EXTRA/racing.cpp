#include "racing.hpp"
#define DNF 1000

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void press_enter()
{
    cout<<"Press [Enter] to continue....";
    cin.get();
    cout<<endl;
}

void interrupt()
{
    this_thread::sleep_for(seconds(2));
    cout<<endl;
}

Racing::Racing(int number_of_horses,int number_of_rounds):n_horses(number_of_horses),rounds(number_of_rounds)
{
    auto random_value=uniform_int_distribution<int>(50,100);
    vector <string> names{"Blitz","Bolt","Goliath","Hercules","Rogue","Danger","Raider","Storm","Nitro","Hulk"};
    shuffle(names.begin(),names.end(),default_random_engine(chrono::steady_clock::now().time_since_epoch().count()));
    for(int i=0;i<this->n_horses;i++)
    {
        horse a_horse(i+1,names[i],random_value(mt),random_value(mt),random_value(mt));
        horses.push_back(a_horse);
        position.push_back(0);
        standings.push_back(make_pair(a_horse,DNF));
    }
    // position
    // 5 loops->{2,1,3,5,4}
    // 1.position.push_back(2)-->i:0  value:2
    // 2.position.push_back(1)-->i:1  value:1
    // 3.position.push_back(3)-->i:2  value:3
    // 4.position.push_back(5)-->i:3  value:5
    // 5.position.push_back(4)-->i:4  value:4
}

Racing::~Racing() {}

void Racing::race()
{
    mt19937 gen(steady_clock::now().time_since_epoch().count());
    const int steps_will_be_made=this->rounds * 2;
    auto rand_real=uniform_real_distribution<double>(0,100);
    bool can_be_moved;
    this->drawing();
    press_enter();
    int rank=1;
    for(int i=0;i<steps_will_be_made;i++)
    {
        for(int j=0;j<this->horses.size();j++)
        {
            if(this->position[j]==this->rounds-1)
            {
                if(this->standings[j].second==DNF)
                {
                    this->standings[j].second=rank;
                    rank++;
                }
                continue;
            }
            can_be_moved=this->horses[j].move_forward(this->position[j],rand_real(gen));
            if(can_be_moved)
            {
                this->position[j]++;
            }
        }
        this->drawing();
        press_enter();
    }
    this->display_standings();
}

void Racing::auto_race()
{
    mt19937 gen(steady_clock::now().time_since_epoch().count());
    const int steps_will_be_made=this->rounds * 2;
    auto rand_real=uniform_real_distribution<double>(0,100);
    bool can_be_moved;
    this->drawing();
    interrupt();
    int rank=1;
    for(int i=0;i<steps_will_be_made;i++)
    {
        for(int j=0;j<this->horses.size();j++)
        {
            if(this->position[j]==this->rounds-1)
            {
                if(this->standings[j].second==DNF)
                {
                    this->standings[j].second=rank;
                    rank++;
                }
                continue;
            }
            can_be_moved=this->horses[j].move_forward(this->position[j],rand_real(gen));
            if(can_be_moved)
            {
                this->position[j]++;
            }
        }
        this->drawing();
        interrupt();
    }
    this->display_standings();
}


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
            else
                cout<<".";
        }
        cout<<"|"<<endl;
    }
}

void Racing::display_standings()
{
    sort(this->standings.begin(),this->standings.end(),[](pair <horse,int> &p1,pair <horse,int> &p2) {return p1.second<p2.second;});
    cout<<"====== Standings ======="<<endl;
    for(int i=0;i<this->standings.size();i++)
    {
        cout<<this->standings[i].first.get_name()<<"->"<<(this->standings[i].second==DNF?"DNF":to_string(this->standings[i].second))<<endl;

    }
    cout<<endl;
}

void Racing::reset_race()
{
    this->horses.clear();
    this->position.clear();
    this->standings.clear();
    shuffle(this->horses.begin(),this->horses.end(),default_random_engine(high_resolution_clock::now().time_since_epoch().count()));
    auto rand_real=uniform_int_distribution<int>(50,100);
    vector <string> names{"Blitz","Bolt","Goliath","Hercules","Rogue","Danger","Raider","Storm","Nitro","Hulk"};
    for(int i=0;i<this->n_horses;i++)
    {
        horse ahorse(i+1,names.at(i),rand_real(mt),rand_real(mt),rand_real(mt));
        this->horses.push_back(ahorse);
        this->position.push_back(0);
        this->standings.push_back(pair <horse,int>(ahorse,DNF));
    }
}

vector <horse> Racing::get_horses()
{
    return this->horses;
}