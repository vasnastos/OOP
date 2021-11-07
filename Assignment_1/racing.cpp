#include "racing.hpp"

std::mt19937 mt1(std::chrono::high_resolution_clock::now().time_since_epoch().count());

racing::racing(int h,int rounds):rounds(rounds)
{
    if(h!=0)
    {
        auto random_value=std::uniform_int_distribution<int>(50,100);
        for(int i=1;i<=h;i++)
        {
            this->horses.emplace_back(horse(i,"horse_"+std::to_string(i),random_value(mt1),random_value(mt1),random_value(mt1)));
            this->horse_names[i]="horse_"+std::to_string(i);
            rank[i]=-1;
        }
        this->positions=new int[h];
    }
}

racing::racing(int horse_number,std::vector <std::string> &names,int rnds)
{
    this->horses.clear();
    int id=1;
    auto random_name=uniform_int_distribution<int>(0,names.size()-1);
    string name;
    auto seed=steady_clock::now().time_since_epoch().count();
    for(int i=0;i<horse_number;i++)
    {
        shuffle(names.begin(),names.end(),default_random_engine(seed));
        name=names.at(random_name(mt1));
        this->horses.emplace_back(i+1,name);
    }
    this->rounds=rnds;
    this->positions=new int[names.size()];
}

racing::~racing() {delete[] positions;}

void racing::race()
{
    const int rounds_will_be_executed=this->rounds * 2;
    for(int i=0,t=this->horses.size();i<t;i++)
    {
        this->positions[i]=1;
    }
    bool can_be_moved;
    std::uniform_real_distribution <double> move_factor(0.0,100.0);
    this->draw_race(); press_any_key();
    int rank=1;
    for(int i=1;i<=rounds_will_be_executed;i++)
    {
        for(int j=0,t=this->horses.size();j<t;j++)
        {
            can_be_moved=this->horses[j].move_forward(this->positions[i],move_factor(mt1));
            if(this->positions[j]==this->rounds) 
            {
                if(find_if(this->ranking.begin(),this->ranking.end(),[&](std::pair <int,int> &p) {return p.first==this->horses[j].get_id();})!=this->ranking.end()) continue;
                this->ranking.emplace_back(std::pair<int,int>(this->horses[j].get_id(),rank));
                rank++;
                continue;
            }
            if(can_be_moved)
            {
                positions[j]++;
            }
        }
        this->draw_race();
        press_any_key();
    }
}

void racing::auto_race()
{
    const int steps_will_be_executed=this->rounds * 2;
    for(int i=0,t=this->horses.size();i<t;i++)
    {
        this->positions[i]=1;
    }
    bool can_be_moved;
    std::uniform_real_distribution <double> move_factor(0,100.0);
    double move_forward;
    this->draw_race();  this_thread::sleep_for(seconds(2)); cout<<endl;
    for(int i=1;i<=steps_will_be_executed;i++)
    {
        move_forward=move_factor(mt1);
        for(int j=0,t=this->horses.size();j<t;j++)
        {
            can_be_moved=this->horses[i].move_forward(this->positions[j],move_factor(mt1));
            if(this->positions[j]==this->rounds)
            {
                
                continue;
            }
            if(can_be_moved)
            {
                positions[j]++;
            }
        }
        this->draw_race();
        this_thread::sleep_for(seconds(2));
        cout<<endl;
    }
}

void racing::draw_race()
{
    for(int i=0,t=this->horses.size();i<t;i++)
    {
        cout<<this->horses.at(i).get_name()<<"  |";
        for(int k=1;k<=this->rounds;k++)
        {
            if(this->positions[i]==k)
            {
                cout<<i+1;
            }
            else
             cout<<".";
        }   
        cout<<"|"<<endl;
    }
}

void racing::print_ranks()
{
    sort(this->ranking.begin(),this->ranking.end(),[](pair <int,int> &p1,pair <int,int> &p2) {return p1.first<p2.first;});
    for(auto &rank:this->ranking)
    {
        cout<<rank.first<<"."<<find_if(horses.begin(),horses.end(),[&](const horse &h) {return h.get_id()==rank.second;})->get_name()<<endl;
    }
}


void press_any_key()
{
    #ifdef _WIN32
    system("pause");
    #else
    cout<<"Press any key....";
    cin.get();
    #endif
    cout<<endl<<endl;
}