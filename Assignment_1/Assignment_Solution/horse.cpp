#include "horse.hpp"

horse::horse(int h_id,string h_name,int h_startup_speed,int h_power,int h_stamina):id(h_id),name(h_name),startup_speed(h_startup_speed),power(h_power),stamina(h_stamina)
{
    
}

horse::~horse()  {}

bool horse::move_forward(int step,double r)
{
    if(step==1) 
    {
        // return startup_speed>r;
        if(this->startup_speed>r)
        {
            return true;
        }
    }
    else if(step>=2 && step<=8)
    {
        if(this->power>r)
        {
            return true;
        }
    }
    else
    {
        double average=(double)(this->power+this->stamina)/2;
        if(average>r)
        {
            return true;
        }
    }
    return false;
}

bool horse::operator==(const horse &h)const
{
    return this->id==h.id;
}

horse::operator string()const
{
    stringstream ss;
    ss<<"["<<this->name<<", Startup Speed:"<<this->startup_speed<<", Power:"<<this->power<<", Stamina:"<<this->stamina<<"]";
    return ss.str();
}

ostream &operator<<(ostream &os,const horse &h)
{
    return os<<"[Name:"<<h.name<<" Startup Speed:"<<h.startup_speed<<" Power:"<<h.power<<" Stamina:"<<h.stamina<<"]";
}

string horse::get_name()const{
    return this->name;
}