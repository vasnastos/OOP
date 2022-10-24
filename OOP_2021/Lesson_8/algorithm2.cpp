#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Account
{
    string name;
    vector <double> balances;
    public:
        Account(string n):name(n) {}
        void add_balance(double bal)
        {
            this->balances.push_back(bal);
        }

        double balance()const
        {
            return accumulate(this->balances.begin(),this->balances.end(),0.0,[&](double sum,const double &bal) {return sum+bal;});
        }

        bool operator<(const Account &acc)const
        {
            return this->balance()<acc.balance();
        }
        bool operator==(const Account &acc)const
        {
            return this->name==acc.name;
        }        

        friend ostream &operator<<(ostream &os,const Account &acc)
        {
            os<<"Account Owner:"<<acc.name<<endl;
            os<<"****"<<endl;
            for(auto &accb:acc.balances)
            {
                os<<"* "<<accb<<endl;
            }
            return os;
        }
};

void print_accounts(vector <Account> &accounts)
{
    cout<<"System Accounts"<<endl;
    cout<<"****"<<endl;
    for(auto &user:accounts)
    {
        cout<<user<<endl;
    }
    cout<<endl<<endl;
}

vector <Account> search_Accounts(vector <Account> &accounts, double limit)
{
    vector <Account> flimits;
    for_each(accounts.begin(),accounts.end(),[&](const Account &acc) {if(acc.balance()<limit) {flimits.push_back(acc);}});
    return flimits;
}

int over_50000_balance(vector <Account> &accounts)
{
    return count_if(accounts.begin(),accounts.end(),[&](const Account &acc) {return acc.balance()>50000;});
}

int main()
{ 
    vector <Account> accounts{
        {"Owner 1"},
        {"Owner22"},
        {"Owner25"},
        {"Owner71"},
        {"Owner91"},
        {"Owner00012"},
        {"Owner0001230"},
        {"Owner00712"}
    };
    mt19937 mt(steady_clock::now().time_since_epoch().count());
    auto r_index=uniform_int_distribution<int>(0,accounts.size()-1);
    auto r_balance=uniform_real_distribution<double>(1000,100000);
    for(int i=0;i<100;i++)
    {
        accounts[r_index(mt)].add_balance(r_balance(mt));
    }

    cout<<"Checkpoint 1-Accounts"<<endl;
    print_accounts(accounts);

    cout<<"Checkpoint 2-Accounts"<<endl;
    vector <Account> accs=search_Accounts(accounts,80000.0);
    print_accounts(accs);

    cout<<"Checkpoint 3-Over 50000 balance"<<endl;
    cout<<over_50000_balance(accounts)<<endl;

    cout<<"Checkpoint 4-Remove zero balance accounts"<<endl;
    accounts.push_back(Account("MKL987654321"));
    auto itr=remove_if(accounts.begin(),accounts.end(),[&](const Account &acc) {return acc.balance()==0;});
    accounts.erase(itr,accounts.end());
    print_accounts(accounts);
    return EXIT_SUCCESS;
}
