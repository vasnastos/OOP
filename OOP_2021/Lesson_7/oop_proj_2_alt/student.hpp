#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
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
    int credits_left;
    vector <Course> courses;
public:
    Student(string sid, string sfullname, int ssemester, int scredits);
    ~Student();
    void add_course(Course& c);
    friend ostream& operator<<(ostream& os, const Student& s);
    string get_id()const;
    string get_name()const;
    int get_semester()const;
    int get_credits()const;
    bool is_valid_for_enroll(const Course &c);
    vector <Course> get_courses()const;
    void display();
};