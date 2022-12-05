#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
#include <string>
#define NC 10
using namespace std;


mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

class Student
{
    protected:
        string name;
        double *grades;
        int courses;
    public:
        Student() {}
        Student(string n,int number_of_grades):name(n),grades(new double[number_of_grades]),courses(number_of_grades) {
            for(int i=0;i<this->courses;i++)
            {
                uniform_real_distribution <double> rand(0.1,10);
                for(int i=0;i<this->courses;i++)
                {
                    this->grades[i]=rand(mt);
                }
            }
        }
        ~Student() {delete[] this->grades;}
        void set_grades(int *grades_vector)
        {
            for(int i=0;i<this->courses;i++)
            {
                this->grades[i]=grades_vector[i];
            }
        }

        virtual double average()
        {
            return accumulate(this->grades,this->grades+this->courses,0,[&](double &s,const double &grade) {return s+grade;})/this->courses;
        }   

        virtual string to_string()
        {
            return "Name:"+this->name+"\nCourses:"+std::to_string(this->courses)+"\nAverage:"+std::to_string(this->average())+"\n";
        }
};

class UniversityStudent:public Student
{
    int semester;
    string affiliation;
    public:
        static double *factors;
        static void load_factor();
        static void free();
        UniversityStudent() {}
        UniversityStudent(int sem,string aff,string us_name,int us_courses):semester(sem),affiliation(aff),Student(us_name,us_courses) {}
        ~UniversityStudent() {}
        double average()
        {
            double s=0.0;
            for(int i=0;i<NC;i++)
            {
                s+=UniversityStudent::factors[i]*this->grades[i];
            }
            return s/NC;
        }
        string to_string()
        {
            return Student::to_string()+"Average(Factors):"+std::to_string(this->average())+"\n";
        }
};

double UniversityStudent::*factors=nullptr;

void UniversityStudent::load_factor()
{
    delete[] UniversityStudent::factors;
    factors=new double[NC];
    uniform_real_distribution <double> rand(0.1,1.9);
    while(accumulate(factors,factors+NC,0,[&](double &s,const double &cn) {return s+cn;})!=NC)
    {
        for(int i=0;i<NC;i++)
        {
             UniversityStudent::factors[i]=rand(mt);
        }
    }
}

void UniversityStudent::free()
{
    delete[] UniversityStudent::factors;
}

class SchoolStudent:public Student
{
    int schoolGrade;
    int years;
    public:
        static double *factors;
        static void load_factor();
        static void free();
        SchoolStudent() {}
        SchoolStudent(int _schoolGrade,int _years,string us_name,int us_courses):schoolGrade(_schoolGrade),years(_years),Student(us_name,us_courses) {}
        ~SchoolStudent() {delete[] this->grades;}
        double average()
        {
            double s=0.0;
            for(int i=0;i<NC;i++)
            {
                s+=SchoolStudent::factors[i]*this->grades[i];
            }
            return s/NC;
        }
        string to_string()
        {
            return Student::to_string()+"Average(Factors):"+std::to_string(this->average())+"\n";
        }
};

double SchoolStudent::*factors=nullptr;

void SchoolStudent::load_factor()
{
    delete[] UniversityStudent::factors;
    factors=new double[NC];
    uniform_real_distribution <double> rand(0.1,1.9);
    while(accumulate(factors,factors+NC,0,[&](double &s,const double &cn) {return s+cn;})!=NC)
    {
        for(int i=0;i<NC;i++)
        {
             UniversityStudent::factors[i]=rand(mt);
        }
    }
}

void SchoolStudent::free()
{
    delete[] UniversityStudent::factors;
}

int main()
{
    UniversityStudent::load_factor();
    SchoolStudent::load_factor();

    Student **students=new Student*[5];
    students[0]=new UniversityStudent(7,"University of Ioannina","UStudent1",NC);
    students[1]=new SchoolStudent(4,6,"SchStudent1",NC);
    students[2]=new UniversityStudent(3,"University of Patras","UStudent2",NC);
    students[3]=new SchoolStudent(2,6,"SchStudent2",NC);
    students[4]=new UniversityStudent(3,"University of Western Macedonia","UStudent3",NC);

    cout<<"--- Students ---"<<endl;
    cout<<"**********"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<students[i]->to_string()<<endl;
    }
    cout<<endl<<endl;

    cout<<"--- Students ---"<<endl;
    cout<<"**********"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<students[i]->to_string()<<endl;
    }
    cout<<endl<<endl;

    for(int i=0;i<5;i++)
    {
        delete[] students[i];
    }
    delete[] students;

    UniversityStudent::free();
    SchoolStudent::free();
    return 0;
}