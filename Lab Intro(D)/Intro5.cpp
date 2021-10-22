#include <iostream>

using namespace std;

class Student
{
    private:
        string name;
        double grade;
    public:
        Student(string n, double g)
        {
            name = n;
            grade = g;
        }

        string get_name()
        {
            return name;
        }

        double get_grade()
        {
            return grade;
        }   

        friend void print_data(Student s);
};

void print_data(Student s)
{
    cout<<"Name : "<<s.name<<endl
    <<"Grade : "<<s.grade<<endl;
}

int main()
{
    Student s1("Petros", 8.5);

    /*Print data with getters

    cout<<"Name : "<<s.name<<endl<<"Grade : "<<s.grade<<endl;  --> Not working
    
    cout<<"Name : "<<s1.get_name()<<endl<<"Grade : "<<s1.get_grade()<<endl;
    */

    //Print data with friend function
    print_data(s1);

}