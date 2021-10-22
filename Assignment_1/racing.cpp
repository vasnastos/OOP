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

void racing::print_race()
{
    for(auto &horse:this->horses)
    {
        int horse_position=horse.get_position();
        for(int i=0;i<this->rounds;i++)
        {
            if(i==horse_position)
            {
                std::cout<<"H";
                continue;
            }
            std::cout<<".";
        }
        std::cout<<"|"<<std::endl;
    }
}

void racing::print_ranking()
{
    std::sort(this->ranking.begin(),this->ranking.end(),[](std::pair <int,int> &p1,std::pair <int,int> &p2) {return p1.first<p2.first;});
    for(auto &m:this->ranking)
    {
        if(m.first==INT_MAX)
        {
            std::cout<<"DNF."<<this->horse_names[m.second]<<std::endl;
        }
        else
        std::cout<<m.first<<"."<<this->horse_names[m.second]<<std::endl;
    }
}

void racing::set_horses(int number_of_horses)
{
    auto random_genarator=std::uniform_int_distribution<int>(0,100);
    this->horses.clear();
    for(int i=1;i<=number_of_horses;i++)
    {
        this->horses.emplace_back(horse(i,"horse_"+std::to_string(i),random_genarator(mt),random_genarator(mt),random_genarator(mt)));
    }
}

void racing::game_started()
{
    const int rounds_played=this->rounds*2;
    auto rf=std::uniform_int_distribution<int>(0,100);
    int rank=1;
    this->print_race();
    press_any_key();
    for(int i=0;i<rounds_played;i++)
    {
        for(auto &h:this->horses)
        {
            if(!h.is_finished(this->rounds))
                h.move_forward(1,rf(mt));
            else
            {
                if(std::find_if(this->ranking.begin(),this->ranking.end(),[&](std::pair<int,int> &p) {return p.second==h.get_id();})==this->ranking.end())   
                {
                    this->ranking.emplace_back(std::pair <int,int>(rank,h.get_id()));
                    rank++;
                }
            }
        }
        this->print_race();
        press_any_key();
    }
    for(auto &h:this->horses)
    {
        if(std::find_if(this->ranking.begin(),this->ranking.end(),[&](std::pair<int,int> &p) {return p.second==h.get_id();})==this->ranking.end())
        {
            this->ranking.emplace_back(std::pair<int,int>(INT_MAX,h.get_id()));
        }
    }
    this->print_ranking();
}

void racing::game_automatically_executed()
{
    auto rf=std::uniform_int_distribution<int>(0,100);
    const int rounds_will_be_played=this->rounds * 2;
    int rank=1;
    this->print_race();
    std::cout<<std::endl;
    for(int i=0;i<rounds_will_be_played;i++)
    {
        for(auto &horse:this->horses)
        {
            if(!horse.is_finished(this->rounds))
              horse.move_forward(1,rf(mt));
            else
            {
                if(std::find_if(this->ranking.begin(),this->ranking.end(),[&](std::pair <int,int> &p) {return horse.get_id()==p.second;})!=this->ranking.end()) continue;
                this->ranking.emplace_back(std::pair <int,int>(rank,horse.get_id()));
                rank++;
            }
        }
        this->print_race();
        std::cout<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    for(auto &horse:this->horses)
    {
        if(std::find_if(this->ranking.begin(),this->ranking.end(),[&](std::pair <int,int> &p) {return p.second==horse.get_id();})==this->ranking.end())
        {
            this->ranking.emplace_back(std::pair <int,int>(INT_MAX,horse.get_id()));
            rank++;
        }
    }
    this->print_ranking();
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