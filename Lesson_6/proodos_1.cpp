#include <iostream>
#include <sstream>

using namespace std;

enum class ACCOUNT_TYPE
{
    CHECKING=0,
    SAVINGS=1,
    MONEY_MARKET=2
};

string get_account_type(const ACCOUNT_TYPE &acc)
{
    if(acc==ACCOUNT_TYPE::CHECKING)
    {
        return "CHECKING";
    }
    else if(acc==ACCOUNT_TYPE::SAVINGS)
    {
        return "SAVINGS";
    }
    else
    {
        return "MONEY_MARKET";
    }
}

class Account
{
    private:
        string name;
        double balance;
        ACCOUNT_TYPE type;
    public:
        static int counter;
        Account():name("noname"),balance(0.0),type(ACCOUNT_TYPE::CHECKING) {Account::counter++;}
        Account(string n,double b,ACCOUNT_TYPE t):name(n),balance(b),type(t) {Account::counter++;}
        Account(const Account &acc):name(acc.name),balance(acc.balance),type(acc.type) {Account::counter++;}
        void deposit(double b)
        {
            this->balance+=b;
        }
        double withdraw(double b)
        {
            if(this->balance<b)
            {
                this->balance-=b;
                return this->balance;
            }
            this->balance-=b;
            return b;
        }        
        bool operator<(const Account &acc)const
        {
            return this->balance<acc.balance;
        }

        operator string()const
        {
            stringstream ss;
            ss<<this->name<<" "<<this->balance<<" "<<get_account_type(this->type);
            return ss.str();
        }
};

int Account::counter=0;

int main()
{
    Account acc1;
    Account acc2("Ken Lay",100000,ACCOUNT_TYPE::MONEY_MARKET);
    Account acc3(acc2);
    cout<<"Accounts created:"<<Account::counter<<endl;
    double lb;
    cout<<"Give amount you want to withdraw:";
    cin>>lb;
    double price=acc2.withdraw(lb);
    acc1.deposit(0.2*price);
    acc3.deposit(0.8*price);
    cout<<string(acc1)<<endl;
    cout<<string(acc2)<<endl;
    cout<<string(acc3)<<endl;
    return EXIT_SUCCESS;
}
