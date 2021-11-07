#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct student
{
    string id;
    string gender;
    string race;
    int math_score;
    int reading;
    int writing;

    void print()
    {
        cout<<this->id<<" "<<this->gender<<" "<<this->race<<" "<<this->math_score<<" "<<this->reading<<" "<<this->writing<<endl;
    }
};

vector <student> read_data(string filepath)
{
    vector <student> students;
    fstream fs(filepath);
    if(!fs.is_open())
    {
        cerr<<"No such file found on your filesystem"<<endl;
    }
    string line,word;
    vector <string> data;
    bool start=true;
    int autoincrement_id=1;
    while(getline(fs,line))
    {
        if(start)
        {
            start=false;
            continue;
        }
        stringstream ss(line);
        data.clear();
        while(getline(ss,word,','))
        {
            data.emplace_back(word);
        }
        students.push_back({"student_"+to_string(autoincrement_id),data[0],data[1],std::stoi(data[2]),std::stoi(data[3]),std::stoi(data[4])});
        autoincrement_id++;
    }
    return students;
}

int main(int argc,char **argv)
{
    if(argc!=2) {cerr<<"Please proviede the right amount of elements"; return EXIT_FAILURE;}
    vector <student> students=read_data(argv[1]);
    for(auto &student:students)
    {
        student.print();
    }
}

// g++ struct2.cpp -o str
// str archive/StudentsPerformance.csv