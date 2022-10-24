#include "course.hpp"

Course::Course(string c, int s, string t, int cr) :code(c), semester(s), title(t), credits(cr) {}

int Course::get_credits()const
{
    return this->credits;
}

int Course::get_semester()const
{
    return this->semester;
}

string Course::get_code()const
{
    return this->code;
}

string Course::get_title()const
{
    return this->title;
}

bool Course::operator==(const Course& c)const
{
    return this->code == c.code;
}

ostream& operator<<(ostream& os, const Course& c)
{
    return os << "Κωδικός:" << c.code << " Τιτλός:" << c.title << " Εξάμηνο:" << c.semester << " Διδακτικές Μονάδες:" << c.credits;
}