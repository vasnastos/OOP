#include "horse.hpp"

mt19937 mt(steady_clock::now().time_since_epoch().count());

horse::horse(int h_id,std::string h_name,int h_power,int h_startup_speed,int h_stamina):id(h_id),name(h_name),power(h_power),startup_speed(h_startup_speed),stamina(h_stamina) {}

horse::horse(int h_id,string h_name):id(h_id),name(h_name)
{
   auto random_values_creation=uniform_int_distribution<int>(50,100);
   this->power=random_values_creation(mt);
   this->stamina=random_values_creation(mt);
   this->startup_speed=random_values_creation(mt);
}

std::string horse::get_name()const {return this->name;}

int horse::get_id()const {return this->id;}

bool horse::operator==(const horse &h)const{
    return this->id==h.id;
}

bool horse::move_forward(int step,double random_factor)
{
    if(step==1)
    {
        if(this->startup_speed>random_factor)
        {
            return true;
        }
    }
    else if(step>=2 && step<=8)
    {
        if(this->power>random_factor)
        {
            return true;
        }
    }
    else 
    {
        if(static_cast<double>(this->power+this->stamina)/2.0>random_factor)
        {
            return true;
        }
    }
    return false;
}
