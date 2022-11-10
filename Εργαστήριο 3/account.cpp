#include <iostream>
using namespace std;

class Account
{

};

class Bank
{
    private:
        Account accounts[10];
};

int main()
{
    Account acct("Christos");
    acct.deposit(50.0);
    cout<<acct.get_name()<<"-"<<acct.get_balance()<<endl;

    Account acct1("Vasilis", 100.0);
    cout<<acct1.get_name()<<"-"<<acct1.get_balance()<<endl;
    acct.withdraw(70.0);
    cout<<acct1.get_name()<<"-"<<acct1.get_balance()<<endl;
}