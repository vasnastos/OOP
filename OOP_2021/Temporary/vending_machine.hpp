#include <iostream>
#include <map>
#include <ctime>
#include <string>

using namespace std;

const std::string currentDateTime();

class VendingMachine
{
    private:
        map <string,double> products;
        map <string,int> quantity;
        map <double,int> coin_buffer;
        double total_value;
        double temporary_value;
    
    public:
        VendingMachine();
        ~VendingMachine();
        void payout(string product,bool has_milk);
        bool coin_insert();


        // TODO
        void change();
        void refill();
};