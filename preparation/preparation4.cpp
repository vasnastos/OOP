#include <iostream>
#include <fstream>
#include <vector>
#include "random.hpp"
#include <algorithm>


using namespace std;

class Course
{
    private:
        string id;
        string name;
        int semester;
        int credits;
        double average_grade;
    public:
        Course() {}
        Course(string course_id,string course_name,int course_semester,int course_credits,double avg):id(course_id),name(course_name),semester(course_semester),credits(course_credits),average_grade(avg) {}
        ~Course() {}

        // setters-getters
        void set_id(string cid) {this->id=cid;}
        void set_name(string cname) {this->name=cname;}
        void set_semester(int csemester) {this->semester=csemester;}
        void set_credits(int ccredits) {this->credits=ccredits;}
        void set_average_grade(double avg) {this->average_grade=avg;}

        string get_id()const {return this->id;}
        string get_name()const {return this->name;}
        int get_semester()const {return this->semester;}
        int get_credits()const {return this->credits;}
        double get_average_grade()const {return this->average_grade;}

        bool equal_semester(const Course &oth)
        {
            return this->semester==oth.semester;
        }

        friend Course higher_average(const Course &course1,const Course &course2)
        {
            if(course1.average_grade==course2.average_grade)
            {
                return course1;
            }
            else if(course1.average_grade>course2.average_grade)
            {
                return course1;
            }
            else 
            {
                course2;
            }
        }

        void show()
        {
            cout<<this->id<<"\t"<<this->name<<"\t"<<this->semester<<"\t"<<this->credits<<"\t"<<this->average_grade<<endl;
        }
};

// Read the courses from course_dit.txt 
vector <Course> read_courses()
{
    string line,word;
    vector <Course> courses;
    vector <string> data;
    fstream fp;
    fp.open(".\\datasets\\course_dit.txt");
    while(getline(fp,line))
    {
        data.clear();
        stringstream ss(line);
        while(getline(ss,word,','))
        {
            data.emplace_back(word);
        }
        courses.push_back(Course(data[0],data[1],stoi(data[2]),stoi(data[3]),rand_grade()));
    }
    fp.close();
    return courses;
}


int main()
{
    vector <Course> courses=read_courses();


    // Find the courses that are in the same semester as the first course
    for(int i=1,t=courses.size();i<t;i++)
    {
        if(courses[i].equal_semester(courses[0]))
        {
            courses[i].show();
        }
    }
    cout<<endl;


    // Sort the courses based on the average grade
    sort(courses.begin(),courses.end(),[&](const Course &course1,const Course &course2) {return course1.get_average_grade()>course2.get_average_grade();});
    cout<<"=== Sorted Courses ==="<<endl;
    for(auto &x:courses)
    {
        x.show();
    }
    return 0;
}
