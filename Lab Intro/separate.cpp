#include"separate.hpp"

//Constructors
Student::Student() {}

Student::Student(string n, int a, double g)
{
    name = n;
    age = a;
    grade = g;
}

//Setters
void Student::set_name(string n)
{
    name = n;
}

void Student::set_age(int a)
{
    age = a;
}

void Student::set_grade(double g)
{
    grade = g;
}

//Getters
string Student::get_name()
{
    return name;
}

int Student::get_age()
{
    return age;
}

double Student::get_grade()
{
    return grade;
}

int main()
{
    //Create object with constructor
    Student s1("Panagiotis", 21, 18.5);

    cout<<"Data of student s1 --> "<<endl
    <<"Name : "<<s1.get_name()<<endl
    <<"Age : "<<s1.get_age()<<endl
    <<"Grade : "<<s1.get_grade()<<endl;
}

//Compilation of codes
//g++ separate.hpp separate.cpp -o separate
//separate.exe