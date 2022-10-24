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
    int credits_left;
    vector <Course> courses;
public:
    Student(string sid, string sfullname, int ssemester, int scredits);
    void add_course(Course& c);
    
    //setters
    void set_id(string nid);
    void set_name(string name);
    void set_semester(int sem);
    void set_credits(int creds);
    void erase_course(int &course_choice);

    // getters
    string get_id()const;
    string get_name()const;
    int get_semester()const;
    int get_credits()const;
    int get_credits_left()const;
    vector <Course> get_courses()const;
    
    void info();
    bool is_course_valid(const Course &c);
    friend ostream& operator<<(ostream& os, const Student& s);
};