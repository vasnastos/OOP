#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "product.hpp"
using namespace std;

class VendingMachine
{
    private:
        vector <Product> products;
        map <int,double> coins;
        map <double,int> coin_buffer;
        vector <string> machine_memory;
        double paying_amount;
    public:
        VendingMachine(vector <double> &available_coin_types);
        void reset_coin_buffer();
        void reset_payout();
        void change(double pay_amount);
        void refill();
        void payout(string product,bool has_milk=false);
        friend std::ostream &operator<<(ostream &os,const VendingMachine &vm);
};