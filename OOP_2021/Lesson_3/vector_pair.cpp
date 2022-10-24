#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class person
{
    string name;
    int age;
    string email;
    public:
        person(string n,int a,string e):name(n),age(a),email(e) {}
        void info()
        {
            cout<<this->name<<","<<this->age<<","<<this->email;
        }
};  

void print_accounts(vector <pair <person,double>> accounts)
{
    for(auto &record:accounts)
    {
        record.first.info();
        cout<<"-->BAL:"<<record.second<<endl;
    }
    cout<<"============"<<endl<<endl;
}

int main()
{
    vector <pair <person,double>> accounts{
        {person("person_1",20,"person_1@mail.com"),40000},
        {person("person_2",25,"person_2@mail.com"),47000},
        {person("person_3",40,"person_3@mail.com"),20000},
        {person("person_4",29,"person_4@mail.com"),3000},
        {person("person_5",80,"person_5@mail.com"),60000}
    };
    print_accounts(accounts);
    sort(accounts.begin(),accounts.end(),[](pair <person,double> &p1,pair<person,double> &p2) {return p1.second<p2.second;});
    print_accounts(accounts);
    return EXIT_SUCCESS;
}