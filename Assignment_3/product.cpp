#include "product.hpp"

Product::Product(string atitle,double aprice,int quantity):title(atitle),price(aprice),quantity(aquantity) {}

void Product::reduce_quantity()
{
    this->quantity--;
}

void Product::set_quantity(int new_quantity)
{
    this->quantity=new_quantity;
}

string Product::get_title()const
{
    return this->title;
}

double Product::get_price()const
{
    return this->price;
}

int Product::get_quantity()const
{
    return this->quantity;
}
