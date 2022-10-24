#include "student.hpp"

Student::Student(string sid, string sfullname, int ssemester, int scredits) :id(sid), fullname(sfullname), semester(ssemester), credits(scredits),credits_left(scredits) {}

Student::~Student() {}

void Student::add_course(Course& c)
{
    this->courses.push_back(c);
    this->credits_left-=c.get_credits();
}

string Student::get_id()const
{
    return this->id;
}

string Student::get_name()const{
    return this->fullname;
}

int Student::get_semester()const
{
    return this->semester;
}

int Student::get_credits()const
{
    return this->credits;
}

vector <Course> Student::get_courses()const
{
    return this->courses;
}

bool Student::is_valid_for_enroll(const Course &c)
{
    return std::find(this->courses.begin(),this->courses.end(),c)==this->courses.end() && c.get_semester()<=this->semester && c.get_credits()<=this->credits_left;
}

void Student::display()
{
    cout<<*this<<endl;
    cout<<"=== ΜΑΘΗΜΑΤΑ ==="<<endl;
    for(auto &c:this->courses)
    {
        cout<<c<<endl;
    }
}

ostream& operator<<(ostream& os, const Student& s)
{
    os << s.id << " " << s.fullname << " " << s.semester << " " << s.credits;
    return os;
}