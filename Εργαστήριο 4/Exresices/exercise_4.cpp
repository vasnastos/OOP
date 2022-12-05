#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
    protected:
        string registration_number;
        string owner_name;
        int reg_years;
        int enginee_capacity;
        double price;
    public:
        Vehicle(string _registration_number,string _owner_name,int _reg_years,int _enginee_capacity,double _price):registration_number(_registration_number),owner_name(_owner_name),reg_years(_reg_years),price(_price),enginee_capacity(_enginee_capacity) {}
        ~Vehicle() {}
        string to_string()
        {
            return this->registration_number+"-"+this->owner_name+"("+"cc-"+std::to_string(this->reg_years)+")"+"   ENGINEE CAPACITY:"+std::to_string(this->enginee_capacity)+"  PRICE:"+std::to_string(this->price);
        }
        virtual double traffic_tax()
        {
            //Enginee capacity(EC)
            //  EC<=600 - 200*0.782
            //  EC<=1000 - [200 + 0.125(EC - 600)] x 0.782
            //  EC<=1600 - [250 + 0.375(EC - 1.000)] x 0.782
            //  EC<=3000 - [475 + 0.75(EC - 1.600)] x 0.782
            //  EC<=6000 -  [1.525 + 1(EC - 3000)] x 0.782
            //  EC>6000 -  [1.785 + 0.2*years(EC-6000) X 0.782]

            // Years
            // <=5 - years*[0.05*price]
            // <=10 - years*[0.07*price]
            // >10 - [years-10[0.07*price]+ rest_years*[0.09 * price]

            return 0;
        }
};

class Car
{

};

class Truck
{

};