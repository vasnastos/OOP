#include "course.hpp"

Course::Course(std::string course_code,int course_semester, std::string course_title, int course_credits) :code(course_code), semester(course_semester), title(course_title), credits(course_credits) {}

Course::~Course() {}

std::string Course::get_code()const
{
	return this->code;
}

std::string Course::get_title()const
{
	return this->title;
}

int Course::get_semester()const
{
	return this->semester;
}

int Course::get_credits()const
{
	return this->credits;
}

bool Course::operator==(const Course &c)const
{
	return this->code==c.code;
}

std::ostream& operator<<(std::ostream& os, const Course& c)
{
	return os << c.code << " " << c.title << " " << c.semester << " " << c.credits;
}