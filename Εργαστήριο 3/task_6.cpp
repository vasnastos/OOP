#include <iostream>
#include <random>
#include <chrono>
using namespace std;

class Account
{
    private:
        string name;
        double balance;
    public:
        Account():name("Noname"),balance(-1.0) {}
        Account(string _name,double _balance):name(_name),balance(_balance) {}
        ~Account() {}
        
        void set_name(string account_name)
        {
            this->name=account_name;
        }
        void set_balance(double account_balance)
        {
            this->balance=account_balance;
        }
        string get_name()const {return this->name;}
        double get_balance()const {return this->balance;}

        void deposit(double added_balanced)
        {
            this->balance+=added_balanced;
        }
        void withdraw(double added_balanced)
        {
            if(this->balance<added_balanced)
            {
                cerr<<"Can not withdarw that amount of money"<<endl;
                return;
            }
            this->balance-=added_balanced;
        }
};

class Bank{
    private:
        Account accounts[10];
        int account_index;
    public:
        Bank():account_index(0) {}
        void add_account(string account_name,double account_balance)
        {
            if(this->account_index==10)
            {
                cout<<"You can not add another account!!!\nPlease modify another account"<<endl;
                return;
            }
            this->accounts[this->account_index].set_name(account_name);
            this->accounts[this->account_index].set_balance(account_balance);
            this->account_index++;
        }
        void print_accounts()
        {
            for(int i=0;i<10;i++)
            {
                cout<<this->accounts[i].get_name()<<"\t"<<this->accounts[i].get_balance()<<endl;
            }
        }


        void deposit(string client_name,double client_added_balanced)
        {
            bool found=false;
            for(int i=0;i<10;i++)
            {
                if(this->accounts[i].get_name()==client_name)
                {
                    this->accounts[i].deposit(client_added_balanced);
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cerr<<"Client "<<client_name<<" does not exist on the records"<<endl;
            }
        }

        void withdraw(string client_name,double client_removed_balance)
        {
            bool found=false;
            for(int i=0;i<10;i++)
            {
                if(this->accounts[i].get_name()==client_name)
                {
                    this->accounts[i].withdraw(client_removed_balance);
                    found=true;
                    break;
                }
            }
            if(!found)
            {
                cerr<<"Client "<<client_name<<" does not exist on the records"<<endl;
            }
        }
};



int main()
{
    mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_real_distribution <double> rand_real(10000,50000);

    Bank bank;
    for(int i=0;i<10;i++)
    {
        bank.add_account("client_"+to_string(i+1),rand_real(mt));
    }
    bank.print_accounts();

    bank.deposit("client_5",300);
    bank.withdraw("client_7",200);
    bank.print_accounts();
    return 0;
}