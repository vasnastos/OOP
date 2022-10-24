#include "student.hpp"

Student::Student(string sid, string sfullname, int ssemester, int scredits) :id(sid), fullname(sfullname), semester(ssemester), credits(scredits),credits_left(scredits) {}


void Student::add_course(Course& c)
{
    this->credits_left -= c.get_credits();
    this->courses.push_back(c);
}

void Student::set_id(string nid)
{
    this->id = nid;
}

void Student::set_name(string name)
{
    this->fullname = name;
}

void Student::set_semester(int sem)
{
    this->semester = sem;
}

void Student::set_credits(int cr)
{
    int difference = cr - this->credits;
    this->credits = cr;
    this->credits_left + difference < 0 ? this->credits_left = 0 : this->credits_left += difference;
}

void Student::erase_course(int &course_choice)
{
    this->credits_left += this->courses[course_choice].get_credits();
    this->courses.erase(this->courses.begin() + course_choice);
}

string Student::get_id()const
{
    return this->id;
}

string Student::get_name()const
{
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

int Student::get_credits_left()const
{
    return this->credits_left;
}

bool Student::is_course_valid(const Course& c)
{
    for (auto& course : this->courses)
    {
        if (c.get_code() == course.get_code())
        {
            return false;
        }
    }
    return true;
}

vector <Course> Student::get_courses()const
{
    return this->courses;
}

void Student::info()
{
    cout << *this << endl;
    cout << "=== ΜΑΘΗΜΑΤΑ ΦΟΙΤΗΤΗ ===" << endl;
    for (auto& c : this->courses)
    {
        cout << "* " << c << endl;
    }
}

ostream& operator<<(ostream& os, const Student& s)
{
    return os << s.id << " " << s.fullname << " " << s.semester << " " << s.credits;
}