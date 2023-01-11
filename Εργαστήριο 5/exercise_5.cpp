#include <iostream>
#include <vector>
using namespace std;

class Person
{
    string name;
    public:
        Person():name("") {}
        Person(string _name):name(_name) {}
        ~Person() {}
        string get_name()const {return this->name;}
};

class Movie
{
    string title;
    int year;
    Person director;
    vector <Person> actors;
    public:
        Movie(string mtitle):title(mtitle) {}
        void set_director(const Person &p)
        {
            this->director=p;
        }

        void add_cast(const Person &p)
        {
            this->actors.emplace_back(p);
        }

        void display_info()
        {
            cout<<"Movie:"<<this->title<<" Year:"<<this->year<<"  Director:"<<this->director.get_name()<<endl;
            cout<<"Actors"<<endl;
            cout<<"==="<<endl;
            for(const auto &actor:this->actors)
            {
                cout<<"Actor:"<<actor.get_name()<<endl;
            }
            cout<<endl;
        }
};

int main()
{
    Person p1("Actor1");
    Person p2("Actor2");
    Person p3("Actor3");

    Person d1("Director1");
    Person d2("Director2");

    Movie m1("Movie1");
    Movie m2("Movie2");

    m1.set_director(d1);
    m2.set_director(d2);

    m1.add_cast(p1);
    m1.add_cast(p2);

    m2.add_cast(p2);
    m2.add_cast(p3);


    m1.display_info();
    cout<<endl;
    m2.display_info();
    return 0;
}