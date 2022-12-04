#include <iostream>
using namespace std;

class Car
{
    private:
        string CarModel;
        string CarName;
        double CarPrice;
        string CarOwner;
    public:
        Car(string car_model,string car_name,double car_price,string car_owner):CarModel(car_model),CarName(car_name),CarPrice(car_price),CarOwner(car_owner) {}
        ~Car() {}

        void setCarModel(string car_model) {this->CarModel=car_model;}
        void setCarName(string car_name) {this->CarName;}
        void setCarPrice(double car_price) {this->CarPrice=car_price;}
        void setCarOwner(string car_owner) {this->CarOwner;}

        string getCarModel()const {return this->CarModel;}
        string getCarName()const {return this->CarName;}
        double getCarPrice()const {return this->CarPrice;}
        string getCarOwner()const {return this->CarOwner;}

        void display()
        {
            cout<<this->CarModel<<"\t"<<this->CarName<<"\t"<<this->CarPrice<<"\t"<<this->CarOwner<<endl;
        }
};

void sort_table(Car *cars,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1l;j<size-1;j++)
        {
            if(cars[i].getCarPrice()>cars[j].getCarPrice()) {
                Car temp=cars[i];
                cars[i]=cars[j];
                cars[j]=temp;
            }
        }
    }
}

int main()
{
    Car c1{"Toyota","Auris",10000,"Angelos"};
    c1.display();
}   