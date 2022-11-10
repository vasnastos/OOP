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
        Car() {}
        Car(string carmodel,string carname,double carprice,string carowner):CarModel(carmodel),CarName(carname),CarPrice(carprice),CarOwner(carowner) {}
        string getCarModel()const {
            return this->CarModel;
        }

        string getCarName()const {
            return this->CarName;
        }

        string getCarPrice()const
};

int main()
{
    Car cars[10];
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(cars[i].get_price()>cars[j].get_price())
            {
                auto temp=cars[i];
                cars[i]=cars[j];
                cars[j]=temp;
            }
        }
    }
}