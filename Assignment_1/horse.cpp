#include "horse.hpp"

horse::horse(int h_id,std::string h_name,int h_power,int h_startup_speed,int h_stamina):id(h_id),name(h_name),power(h_power),startup_speed(h_startup_speed),stamina(h_stamina),position(0)
{
}

bool horse::move_forward(int step,int random_factor)
{
    if(this->position==1)
    {
        if(this->startup_speed>random_factor)
        {
            this->position++;
            return true;
        }
    }
    else if(this->position>=2 && this->position<=8)
    {
        if(this->power>random_factor)
        {
            this->position++;
            return true;
        }
    }
    else 
    {
        if(static_cast<double>(this->power+this->stamina)/2>random_factor)
        {
            this->position++;
            return true;
        }
    }
    return false;
}

bool horse::is_finished(int &number_of_rounds)
{
    return this->position==number_of_rounds-1;
}

void horse::set_position(int h_position)
{
    this->position=h_position;
}

int horse::get_position()const {return this->position;}

std::string horse::get_name()const
{
    return this->name;
}

int horse::get_id()const
{
    return this->id;
}