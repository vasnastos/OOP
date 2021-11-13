#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <sstream>
#include <codecvt>
#include <iomanip>
#ifdef __WIN32__
    #include <windows.h>
#endif
#include "course.hpp"


using namespace std;

// vector <course>  import_dit_courses(string inputfile)
void import_dit_courses(string inputfile)
{
    vector <Course> courses;
    #ifdef __WIN32__
        SetConsoleOutputCP(65001);
    #endif
    setlocale(LC_CTYPE,".OPC");
    fstream fs(inputfile,ios::in);
    locale a_loc("");
    fs.imbue(a_loc);
    if(!fs.is_open())
    {
        cerr<<"Error on file opening"<<endl;
        return;
    }
    string line,word;
    vector <string> data;
    bool header_line=true;
    while(getline(fs,line))
    {
        if(line.length()==0) continue;
        if(header_line)
        {
            header_line=false;
            continue;
        }
        stringstream ss(line);
        data.clear();
        while(getline(ss,word,','))
        {
            data.emplace_back(word);
        }
        if(data.size()!=4) continue;
        courses.emplace_back(Course(data[0],stoi(data[1]),data[2],stoi(data[3])));
    }
    fs.close();
    for(auto &course:courses)
    {
        cout<<course<<endl;
    }
}

int main()
{
    import_dit_courses("dit_uoi_course.txt");
    return EXIT_SUCCESS;
}