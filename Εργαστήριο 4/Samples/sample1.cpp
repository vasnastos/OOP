#include <iostream>
using namespace std;

class Vehicle
{
    string registration_num;
    int fuel_capacity;
    public:
        Vehicle(string rg,int fc):registration_num(rg),fuel_capacity(fc) {}
        string get_registration_number()
        {
            return this->registration_num;
        }
        int get_fuel_capacity()
        {
            return this->fuel_capacity;
        }
};

class Car:public Vehicle{
    double cc;
    public:
        Car(double cc,string rg,int fc):cc(cc),Vehicle(rg,fc) {}
        ~Car() {}
        void display()
        {
            cout<<this->cc<<","<<this->get_registration_number()<<","<<this->get_fuel_capacity()<<endl;
        }
};

int main()
{
    Car c(1500,"AIO9087",75);
    c.display();
    return 0;
}