#include "course.hpp"

Course::Course(string ccode,int csemester,string ctitle,int ccredits):code(ccode),semester(csemester),title(ctitle),credits(ccredits) {}

Course::~Course() {}

ostream &operator<<(ostream &os,const Course &c)
{
    return os<<c.code<<"-"<<c.title<<"-"<<c.semester<<"-"<<c.credits<<endl;
}