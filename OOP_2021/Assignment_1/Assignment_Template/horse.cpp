#include "horse.hpp"

mt19937 mt(steady_clock::now().time_since_epoch().count());

horse::horse(int h_id,std::string h_name,int h_power,int h_startup_speed,int h_stamina) {}

horse::horse(int h_id,string h_name)
{
}

std::string horse::get_name()const {return this->name;}

bool horse::move_forward(int step,double random_factor)
{

}
