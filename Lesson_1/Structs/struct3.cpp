#include <iostream>
#include <sstream>


enum class RATE
{
    DEP,
    EDIP
};

std::string get_rank(RATE rt)
{
    std::stringstream ss;
    switch(rt)
    {
        case RATE::DEP:
            ss<<"DEP";
            break;
        case RATE::EDIP:
            ss<<"EDIP";
            break;
    }
    return ss.str();
}

struct teacher
{
    std::string name;
    RATE r;
    static int count_obj;
    teacher(std::string n,int i):name(n),r(RATE(i)) {teacher::count_obj++;}
    void show()
    {
        std::cout<<"Name:"<<this->name<<std::endl;
        std::cout<<"Rank:"<<get_rank(this->r)<<std::endl;
    }
};

int teacher::count_obj=0;

struct lesson
{
    std::string lname;
    teacher t;
    static int count_obj;
    int lcapacity;
    int lab_hours;
    int theory_hours;
    lesson(std::string ln,std::string name,int j,int lc,int lh,int th):lname(ln),t(teacher(name,j)),lcapacity(lc),lab_hours(lh),theory_hours(th) {lesson::count_obj++;}
    void clear_lesson(){
        this->lcapacity=0;
    }

    void set_lab_hours(int lab_h)
    {
        this->lab_hours=lab_h;
    }

    void set_theory_hours(int th_hours)
    {
        this->theory_hours=th_hours;
    }

    void show()
    {
        std::cout<<"Lesson:"<<this->lname<<std::endl;
        std::cout<<"Capacity:"<<this->lcapacity<<std::endl;
        std::cout<<"Lab hours:"<<this->lab_hours<<std::endl;
        std::cout<<"Theory hours:"<<this->theory_hours<<std::endl;
        std::cout<<"Teacher Info::"<<std::endl;
        std::cout<<"----------------------------------------"<<std::endl;
        this->t.show();
        std::cout<<std::endl;
    }
};

int lesson::count_obj=0;

int main()
{
    lesson l1{
        "lesson_1",
        "teacher_1",
        1,
        40,
        3,
        3
    };
    lesson l2{
        "lesson_2",
        "teacher_1",
        1,
        60,
        4,
        4
    };
    lesson l3{
        "lesson_3",
        "teacher_2",
        0,
        40,
        3,
        2
    };
    lesson l4{
        "lesson_4",
        "teacher_2",
        0,
        40,
        2,
        1
    };
    l1.show();
    l2.show();
    l3.show();
    l4.show();

    std::cout<<"Teacher objects made:"<<teacher::count_obj<<std::endl;
    std::cout<<"Lesson objects made:"<<lesson::count_obj<<std::endl;
    return 0;
}