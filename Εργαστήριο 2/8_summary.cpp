#include <iostream>
using namespace std;

class Student
{
    private:
        string name;
        string lastname;
        double *grades;
        int number_of_grades;
        int grades_added;
    public:
        Student():name(""),lastname(""),number_of_grades(10),grades_added(0),grades(new double[10]) {}
        Student(string student_name,string student_lastname,int student_number_of_grades):name(student_name),lastname(student_lastname),number_of_grades(10),grades_added(0),grades(new double[student_number_of_grades]) {}
        ~Student() {delete[] grades;}

        void add_grade(double g)
        {
            if(this->grades_added==this->number_of_grades)
            {
                cout<<"You can not add another grade:Limit("<<this->number_of_grades<<")"<<endl;
                return;
            }
            this->grades[this->grades_added++]=g;
        }

        double average()
        {
            double avg=0.0;
            for(int i=0;i<this->grades_added;i++)
            {
                avg+=this->grades[i];
            }
            return avg/this->grades_added;
        }
};