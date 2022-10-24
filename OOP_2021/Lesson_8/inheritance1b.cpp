#include <iostream>
#include <vector>

using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        Person():name("No Name"),age(-1) {}
        Person(string n,int an_age):name(n),age(an_age) {}
        void set_name(string n) {this->name=n;}
        void set_age(int a) {this->age=a;}
        string get_name()const {return this->name;}
        int get_age()const {return this->age;}
};


class Employee:public Person
{
    private:
        double salary;
        string nin;
        int year;
    
    public:
        Employee(string name,int age,double sal,string n,int y):Person(name,age),salary(sal),nin(n),year(y) {}
        ~Employee() {}
        friend ostream &operator<<(ostream &os,const Employee &e)
        {
            os<<"Name:"<<e.name<<endl<<"Age:"<<e.age<<endl;
            os<<"Salary:"<<e.salary<<endl<<"NIN:"<<e.nin<<endl;
            os<<"Init Year:"<<e.year;
            return os;
        }
};

int main()
{
    vector <Employee> employees{
        {"Nikos Papadopoulos",22,1500,"2109876541",2020},
        {"Georgios Papageorgiou",34,1789.34,"123456789",2009},
        {"Maria Nikou",56,3000,"87654912",2005}
    };
    for(auto &employee:employees)
    {
        cout<<employee<<endl<<endl;
    }
    return EXIT_SUCCESS;
}