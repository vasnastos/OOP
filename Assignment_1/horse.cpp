#include "horse.hpp"

horse::horse(int h_id,std::string h_name,int h_power,int h_startup_speed,int h_stamina):id(h_id),name(h_name),power(h_power),startup_speed(h_startup_speed),stamina(h_stamina),position(0)
{
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
        if(static_cast<double>(this->power+this->stamina)/2>random_factor)
        {
            return true;
        }
    }
    return false;
}
