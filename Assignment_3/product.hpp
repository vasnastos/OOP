#include <iostream>


using namespace std;

class Product
{
    private:
        string title;
        double price;
        int quantity;
    public:
        Product(string atitle,double aprice,int quantity);
        void set_quantity(int new_quantity);
        void reduce_quantity();
        string get_title()const;
        double get_price()const;
        int get_quantity()const;
};