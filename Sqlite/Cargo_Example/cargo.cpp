#include "cargo.hpp"

Cargo::Cargo(int cid,std::string c_destination,double c_weight,bool c_fragile):id(cid),destination(c_destination),weight(c_weight),fragile(c_fragile) {}

Cargo::~Cargo() {}

void Cargo::set_weight(double w)
{
    this->weight=w;
}

double Cargo::get_weight()const
{
    return this->weight;
}

bool Cargo::make_safe()
{

}

void Cargo::show()
{
    
}