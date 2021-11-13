#include <iostream>

using namespace std;

class Course
{
    private:
        string code;
        int semester;
        string title;
        int credits;
    public:
        Course(string ccode,int csemester,string ctitle,int ccredits);
        ~Course();
        friend ostream &operator<<(ostream &os,const Course &c);
};