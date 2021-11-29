#include "student.hpp"
#include <fstream>
#include <sstream>
#ifdef __WIN32__
    #include <windows.h>
#endif

int main()
{
    // Διάβασμα αρχείου δεδομένων και εμφάνιση των μαθημάτων
    #ifdef __WIN32__
        SetConsoleOutputCP(65001);
    #endif
    string filename="../dit_uoi_course.txt";
    fstream fs(filename,ios::in);
    string line,word;
    vector <string> data;
    vector <Course> courses;
    auto start=true;
    while(getline(fs,line))
    {
        if(start)
        {
            start=false;
            continue;
        }
        data.clear();
        stringstream ss(line);
        while(getline(ss,word,','))
        {
            data.push_back(word);
        }
        if(data.size()!=4) continue;
        courses.push_back(Course(data[0],stoi(data[1]),data[2],stoi(data[3])));
    }
    fs.close();
    for(auto &course:courses)
    {
        cout<<course<<endl;
    }
    return 0;

}


