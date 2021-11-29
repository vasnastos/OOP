#include <iostream>
#include <vector>
#include "course.hpp"
using namespace std;

class Student
{
    private:
        // αριθμός μητρώου,ονοματεπώνυμο,εξάμηνο,διδακτικές μονάδες
        int id;
        string fullname;
        int semester;
        int credits;
        vector <Course> courses;
    public:
        Student(int sid,string sfullname,int ssemester,int scredits);
        void add_course(Course &c);

};