#include <iostream>
#include <vector>
using namespace std;

class Customer
{
    string name;
    string location;
    public:
        Customer(string n,string loc):name(n),location(loc) {}
        void sendOrder() {}
        void receiveOrder() {}
};

class Order
{
    string date;
    string number;
    vector <Customer> customers;
    public:
        Order(string d,string n):date(d),number(n) {}
        void confirm() {}
        void close() {}
};

class SpecialOrder:public Order
{
    public:
        SpecialOrder(string d,string n):Order(d,n) {}
        void dispatch() {}
};

class NormalOrder:public Order
{
    public:
        NormalOrder(string d,string n):Order(d,n) {}
        void dispatch() {}
        void receive() {}
};