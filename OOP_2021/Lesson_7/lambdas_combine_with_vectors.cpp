#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Account
{
    public:
        string name;
        double balance;
        Account(string n,double b):name(n),balance(b) {}
        ~Account() {}
        bool operator==(const Account &acc)const
        {
            return this->balance==acc.balance;
        }
        friend ostream &operator<<(ostream &os,const Account &acc)
        {
            return os<<acc.name<<"--"<<acc.balance;
        }
};


int main()
{
    vector <Account> accounts{
        {"Maria",6000},
        {"Vasilis",1000},
        {"Nikos",7000},
        {"Petros",2000},
        {"Kostas",800},
        {"Konstantina",1500}
    };

    sort(accounts.begin(),accounts.end(),[&](const Account &acc1,const Account &acc2) {return acc1.balance>acc2.balance;});
    cout<<"=== ACCOUNTS[SORT FROM MAX TO MIN] ==="<<endl;
    for(auto &acc:accounts)
    {
        cout<<acc<<endl;
    }
    cout<<endl;
    cout<<"=== MAX ELEMENT ==="<<endl;
    cout<<*max_element(accounts.begin(),accounts.end(),[&](const Account &acc1,const Account &acc2) {return acc1.balance<acc2.balance;})<<endl<<endl;

    cout<<"=== Erase account[Vasilis--1000] ==="<<endl;
    auto search_name="Vasilis";
    auto pos=find_if(accounts.begin(),accounts.end(),[&](const Account &acc1) {return acc1.name==search_name;});
    accounts.erase(pos);
    cout<<"=== ACCOUNTS ==="<<endl;
    for(auto &acc:accounts)
    {
        cout<<acc<<endl;
    }
    cout<<endl;
    reverse(accounts.begin(),accounts.end());
    cout<<"=== ACCOUNTS[Reversed Table] ==="<<endl;
    for(auto &acc:accounts)
    {
        cout<<acc<<endl;
    }
    cout<<endl;

    cout<<"=== Total amount of Money ==="<<endl;
    cout<<"Amount:"<<accumulate(accounts.begin(),accounts.end(),0,[&](int s,const Account &ac) {return s+ac.balance;})<<endl;
    return EXIT_SUCCESS;
}