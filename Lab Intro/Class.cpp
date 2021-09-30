#include<iostream>

using namespace std;

class Student
{
    private:
        string name;
        int age;
        double grade;
    
    public:    
        //Constructors
        Student(){}

        Student(string n, int a, double g)
        {
            name = n;
            age = a;
            grade = g;
        }

        //Setters
        void set_name(string n)
        {
            name = n;
        }

        void set_age(int a)
        {
            age = a;
        }

        void set_grade(double g)
        {
            grade = g;
        }

        //Getters
        string get_name()
        {
            return name;
        }

        int get_age()
        {
            return age;
        }

        double get_grade()
        {
            return grade;
        }

        //Destructor
        ~Student()
        {
            //cout<<"Object destroyed"<<endl;
        }
};

int main()
{
    //Create object with constructor;
    Student s1("Panagiotis", 21, 18.5);

    cout<<"Data of student s1 --> "<<endl
    <<"Name : "<<s1.get_name()<<endl
    <<"Age : "<<s1.get_age()<<endl
    <<"Grade : "<<s1.get_grade()<<endl;

    Student s2;
    s2.set_name("Pavlos");
    s2.set_age(23);
    s2.set_grade(16.4);

    cout<<"Data of student s2 --> "<<endl
    <<"Name : "<<s2.get_name()<<endl
    <<"Age : "<<s2.get_age()<<endl
    <<"Grade : "<<s2.get_grade()<<endl;
}