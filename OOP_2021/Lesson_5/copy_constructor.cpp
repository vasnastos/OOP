#include <iostream>

class course
{
    private:
        int code;
        std::string title;
        int credits;
        int theory;
        int lab;
        static int object_counter;
    public:
        course(int c,std::string t,int cr,int th,int l):code(c),title(t),credits(cr),theory(th),lab(l) {course::object_counter++;}
        course(const course &c):code(c.code),title(c.title),credits(c.credits),theory(c.theory),lab(c.lab) {course::object_counter++;}
        static void objects_created()
        {
            std::cout<<"Objects created:"<<course::object_counter<<std::endl;
        }
};