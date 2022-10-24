#include "student.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Management
{
private:
	vector <Course> courses;
	vector <Student> students;
public:
	Management();
	~Management();
	void insert_student();
    void load_sample();
    void display_courses();
	void display_students();
	vector <Student> get_students()const;
};