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
        Student();
        Student(string n, int a, double g);
        //Setters
        void set_name(string n);
        void set_age(int a);
        void set_grade(double g);
        //Getters
        string get_name();
        int get_age();
        double get_grade();
};