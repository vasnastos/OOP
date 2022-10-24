#pragma once
#include <iostream>
#include <vector>
#include "course.hpp"
using namespace std;

class Student
{
private:
    // αριθμός μητρώου,ονοματεπώνυμο,εξάμηνο,διδακτικές μονάδες
    string id;
    string fullname;
    int semester;
    int credits;
    vector <Course> courses;
public:
    Student(string sid, string sfullname, int ssemester, int scredits);
    void add_course(Course& c);

};