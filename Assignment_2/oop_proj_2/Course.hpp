#pragma once
#include <iostream>

using namespace std;

class Course
{
private:
    // kωδικός, τίτλος, εξάμηνο διδασκαλίας και διδακτικές μονάδες
    string code;
    string title;
    int semester;
    int credits;
public:
    Course(string c, int s, string t, int cr);
    friend ostream& operator<<(ostream& os, const Course& c);
};