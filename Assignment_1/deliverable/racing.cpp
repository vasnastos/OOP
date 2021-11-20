#include "racing.hpp"
#define DNF 99

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void press_enter()
{
    cout<<"Press [Enter] to continue....";
    cin.get();
}

void interrupt()
{
    this_thread::sleep_for(seconds(2));
    cout<<endl;
}

Racing::Racing(int number_of_horses,int number_of_rounds)
{
    if(number_of_horses>10)
    {
        cerr<<"Invallid number of horses("<<number_of_horses<<")"<<endl;
        exit(EXIT_FAILURE);
    }

    if(number_of_rounds>20)
    {
        cerr<<"Invallid number of rounds("<<number_of_rounds<<")"<<endl;
        exit(EXIT_FAILURE);
    }
    this->n_horses=number_of_horses;
    this->rounds=number_of_rounds;
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
                if(find_if(standings.begin(),standings.end(),[&](pair <horse,int> &p) {return p.first==this->horses[j];})==standings.end())
                {
                    standings.emplace_back(pair<horse,int>(horses[j],rank));
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
    for(auto &h:this->horses)
    {
        if(find_if(standings.begin(),standings.end(),[&](pair <horse,int> &p) {return p.first==h;})==standings.end())
        {
            this->standings.emplace_back(pair<horse,int>(h,DNF));
        }
    }
}

void Racing::auto_race()
{
    mt19937 gen(steady_clock::now().time_since_epoch().count());
    const int steps_will_be_made=this->rounds * 2;
    auto rand_real=uniform_real_distribution<double>(0,100);
    bool can_be_moved;
    this->drawing();
    interrupt();
    for(int i=0;i<steps_will_be_made;i++)
    {
        for(int j=0;j<this->horses.size();j++)
        {
            if(this->position[j]==this->rounds-1)
            {
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

void Racing::display_horses()
{
    cout<<"======= Horses ========"<<endl;
    for(auto &h:this->horses)
    {
        cout<<string(h)<<endl;
    }
    cout<<endl<<endl;
}

void Racing::display_standings()
{
    cout<<"======= Standings ========"<<endl;
    for(auto &display:this->standings)
    {
        cout<<(display.second!=DNF?to_string(display.second):"DNF")<<"."<<std::string(display.first)<<endl;
    }
    cout<<endl<<endl;
}

vector <horse> Racing::get_horses()
{
    return this->horses;
}

vector <pair <horse,int>> Racing::get_standings()
{
    return this->standings;
}