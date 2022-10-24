#include <iostream>
using namespace std;

class customer
{
    string name;
    double balance;
    public:
        customer(string n,double b):name(n),balance(b) {}
        bool operator==(const customer &c)const {return this->name==c.name && this->balance==c.balance;}
        bool operator<(const customer &c)const {return this->balance<c.balance;}
        friend ostream &operator<<(ostream &os,const customer &c)
        {
            return os<<c.name<<"-"<<c.balance<<endl;
        }
};

int main()
{
    customer c1("Dimitris",1000.0);
    customer c2("Vasilis",800.0);
    customer c3("Eyaggelia",500.0);
    customer c4("Maria",1500.0);

    if(c1<c2)
    {
        cout<<"Customer["<<c2<<"]-->"<<"significant client than ["<<c1<<"]"<<endl;
    }
    else if(c2<c1)
    {
        cout<<"Customer["<<c1<<"]-->"<<"significant client than ["<<c2<<"]"<<endl;
    }

    if(c3==c4)
    {
        cout<<"Customer ["<<c3<<"] equals to customer ["<<c4<<"]"<<endl;
    }
    else{
        cout<<"Customer ["<<c3<<"] not equals to customer ["<<c4<<"]"<<endl;
    }
    return EXIT_SUCCESS;
}