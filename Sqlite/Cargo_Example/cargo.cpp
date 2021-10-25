#include "cargo.hpp"

Cargo::Cargo(int cid,std::string c_destination,std::string c_description,double c_weight,bool c_fragile):id(cid),destination(c_destination),description(c_description),weight(c_weight),fragile(c_fragile) {}

Cargo::Cargo():id(-1),destination(""),description(""),weight(-1.1),fragile(false) {}

void Cargo::set_weight(double w)
{
    this->weight=w;
}

void Cargo::set_destination(std::string c_destination)
{
    this->destination=c_destination;
}

void Cargo::set_description(std::string c_description)
{
    this->description=c_description;
}

int Cargo::get_id()const
{
    return this->id;
}

double Cargo::get_weight()const
{
    return this->weight;
}

std::string Cargo::get_description()const
{
    return this->destination;
}

std::string Cargo::get_description()const
{
    return this->description;
}

double Cargo::get_weight()const
{
    return this->weight;
}

bool Cargo::get_fragile()const
{
    return this->fragile;
}

bool Cargo::make_safe()
{
    if(!this->fragile)
    {
        this->fragile=true;
        this->weight+=5.0;
        return true;
    }
    return false;
}

void Cargo::show()
{
    std::cout<<std::boolalpha;
    std::cout<<this->id<<" "<<this->destination<<" "<<this->description<<" "<<this->weight<<" "<<this->fragile<<std::endl;
}

std::vector <std::string> Cargo::to_table_view()
{
    return {std::to_string(this->id),this->destination,this->description,std::to_string(this->weight),bool2String(this->fragile)};
}

std::ostream &operator<<(std::ostream &os,const Cargo &c)
{
    os<<c.id<<","<<c.destination<<","<<c.weight<<c.fragile<<std::endl;
    os<<"Description:"<<c.description;
    return os;
}

Cargo::operator std::string()const
{
    std::stringstream ss;
    ss<<this->id<<","<<this->destination<<","<<this->description<<","<<this->weight<<","<<bool2String(this->fragile)<<std::endl;
    return ss.str();
}

std::string bool2String(bool val)
{
    if(val) return "True";
    return "False";
}