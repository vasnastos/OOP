#include "racing.hpp"

std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

racing::racing(int h,int rounds):rounds(rounds)
{
    if(h!=0)
    {
        auto random_creator=std::uniform_int_distribution<int>(0,100);
        for(int i=1;i<=h;i++)
        {
            this->horses.emplace_back(horse(i,"horse_"+std::to_string(i),random_creator(mt),random_creator(mt),random_creator(mt)));
            this->horse_names[i]="horse_"+std::to_string(i);
        }
        this->positions=new int[h];
    }
}

racing::racing(std::vector <std::string> &names,int rnds)
{
    this->horses.clear();
    int id=1;
    auto rf=std::uniform_int_distribution<int>(0,100);
    for(auto &name:names)
    {
        this->horses.emplace_back(horse(id,name,rf(mt),rf(mt),rf(mt)));
        this->horse_names[id]=name;
        id++;
    }
    this->rounds=rnds;
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
    std::uniform_real_distribution <double> move_factor(0,100.0);
    double move_forward;
    for(int i=1;i<=rounds_will_be_executed;i++)
    {
        move_forward=move_factor(mt);
        for(int j=0,t=this->horses.size();j<t;j++)
        {
            can_be_moved=this->horses[i].move_forward(i,move_factor(mt));
            if(can_be_moved)
            {
                positions[j]++;
            }
        }
        this->draw_race();
        press_any_key();
    }
}

void racing::draw_race()
{
  
}


void press_any_key()
{
    #ifdef _WIN32
    system("pause");
    #else
    std::cout<<"Press any key....";
    std::cin.get();
    #endif
    std::cout<<std::endl;
}