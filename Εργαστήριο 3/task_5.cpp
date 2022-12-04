#include <iostream>
#include <string>
#include <chrono>
#include <random>
using namespace std;

class Student
{
    private:
        string name;
        int semester;
        int number_of_grades;
        int grade_index;
        double *grades;
    public:
        Student():name(""),semester(-1),number_of_grades(0),grade_index(0),grades(nullptr) {}
        Student(string name,int semester,int num_of_grades):name(name),semester(semester),number_of_grades(num_of_grades),grade_index(0),grades(new double[num_of_grades]) {}
        ~Student() {delete[] this->grades;}

        void set_name(string student_name) {this->name=student_name;}
        void set_semester(int student_semester) {this->semester=student_semester;}
        void set_number_of_grades(int student_number_of_grades) {
            this->number_of_grades=student_number_of_grades;
            this->grades=new double[this->number_of_grades];
        }

        string get_name()const {return this->name;}
        int get_semester()const {return this->semester;}
        int get_total_grades()const {return this->grade_index;}
        double get_grade(int pos){
            if(pos>=this->grade_index)
            {
                cerr<<"Index Error:"<<pos<<endl;
                return -1;
            }
            return this->grades[pos];
        }

        void add_grade(const double &sgrade)
        {
            if(this->grade_index==this->number_of_grades)
            {
                cerr<<"You can not insert another grade"<<endl;
                return;
            }
            this->grades[this->grade_index++]=sgrade;
        }

        double average()
        {
            double sum=0.0;
            for(int i=0;i<this->grade_index;i++)
            {
                sum+=this->grades[i];
            }
            return sum/this->grade_index;
        }
};

int main()
{
    mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> random_semester(1,8);
    uniform_real_distribution <double> random_grade(0.1,10);

    const int size=10;
    const int total_grades=10;
    Student *students=new Student[size];
    for(int i=0;i<10;i++)
    {
        students[i].set_name("student_"+to_string(i+1));
        students[i].set_semester(random_semester(mt));
        students[i].set_number_of_grades(total_grades);
        for(int j=0;j<total_grades;j++)
        {
            students[i].add_grade(random_grade(mt));
        }
    }

    auto max_average_student=students[0];
    auto min_average_student=students[0];
    double max_average=students[0].average();
    double min_average=students[0].average();

    for(int i=1;i<size;i++)
    {
        if(students[i].average()>max_average)
        {
            max_average=students[i].average();
            max_average_student=students[i];
        }
        else if(students[i].average()<min_average)
        {
            min_average=students[i].average();
            min_average_student=students[i];
        }
    }

    cout<<"Max Average:"<<max_average_student.get_name()<<", "<<max_average_student.get_semester()<<endl;
    cout<<"Min Average:"<<min_average_student.get_name()<<", "<<min_average_student.get_semester()<<endl;
    delete[] students;
    return EXIT_SUCCESS;
}