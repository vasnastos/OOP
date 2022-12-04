#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
    int age;
    public:
        Person(string _name,int _age):name(_name),age(_age) {}
        ~Person() {}
        void set_name(string _name) {this->name=_name;}
        void set_age(int _age) {this->age=_age;}
        string get_name()const {return this->name;}
        int get_age()const {return this->age;}

        virtual string to_string()
        {
            return "Name:"+this->name+" Age:"+std::to_string(this->age);
        }

        virtual void say(string msg)
        {
            cout<<"The person says:"<<msg<<endl;
        }
};

class Student:public Person
{
    int semester;
    public:
        Student(string _name,int _age,int _semester):Person(_name,_age),semester(_semester) {}
        ~Student() {}
        void set_semester(int _semester) {this->semester=_semester;}
        int get_semester()const {return this->semester;}
        friend ostream &operator<<(ostream &os,const Student &s)
        {
            return os<<"Name:"<<s.get_name()<<" Age:"<<s.get_age()<<" Semester:"<<s.semester;
        }

        string to_string()
        {
            return Person::to_string()+" Semester:"+std::to_string(this->semester);
        }

        void say(string msg)
        {
            cout<<"This student says:"<<msg<<endl;
        }
};


int main()
{
    Person *p=new Person("Person1",45);
    Student *st=new Student("Student1",25,7);
    Person *p1=new Student("Student2",26,8);
    cout<<"--- Student1 ---"<<endl;
    cout<<st<<" "<<st->to_string()<<endl;
    st->say("Hello");
    cout<<endl;

    cout<<"--- Person1 ---"<<endl;
    cout<<p<<" "<<p->to_string()<<endl;
    p->say("Hello");
    cout<<endl;

    cout<<"--- Student2 ---"<<endl;
    cout<<p1<<" "<<p1->to_string()<<endl;
    p1->say("Hello");


    delete st;
    delete p;
    delete p1;
    return 0;
}