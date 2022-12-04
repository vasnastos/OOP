#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Course
{
    private:
        string code;
        string name;
        int semester;
        int credits;
    public:
        Course(string _code,string _name,int _semester,int _credits):code(_code),name(_name),semester(_semester),credits(_credits) {}
        ~Course() {}
};

void read_data(string filename)
{

}

int main(int argc,char **argv)
{

}