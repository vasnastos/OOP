#include "course.hpp"

Course::Course(string c, int s, string t, int cr) :code(c), semester(s), title(t), credits(cr) {}

ostream& operator<<(ostream& os, const Course& c)
{
    return os << "Κωδικός:" << c.code << " Τιτλός:" << c.title << " Εξάμηνο:" << c.semester << " Διδακτικές Μονάδες:" << c.credits;
}