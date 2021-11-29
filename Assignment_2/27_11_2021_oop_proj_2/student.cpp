#include "student.hpp"

Student::Student(int sid,string sfullname,int ssemester,int scredits):id(sid),fullname(sfullname),semester(ssemester),credits(scredits) {}


void Student::add_course(Course &c)
{
    this->courses.push_back(c);
}