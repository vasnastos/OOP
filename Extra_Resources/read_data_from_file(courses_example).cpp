#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

class Course
{
    private:
        string code;
        string name;
        int semester;
        int credits;
    public:
        Course() {}
        Course(string _code,string _name,int _semester,int _credits):code(_code),name(_name),semester(_semester),credits(_credits) {}
        ~Course() {}
        string to_string()const
        {
            return this->code+" "+this->name+" "+std::to_string(this->semester)+" "+std::to_string(this->credits);
        }

        void set_code(string _code)
        {
            this->code=_code;
        }

        void set_name(string _name)
        {
            this->name=_name;
        }

        void set_semester(int _semester)
        {
            this->semester=_semester;
        }

        void set_credits(int _credits)
        {
            this->credits=_credits;
        }
};

Course* read_data(string filename,int &size)
{
    fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        cerr<<"File did not open properly"<<endl;
        return nullptr;
    }
    Course *data=nullptr;
    string line,word;
    int line_counter=0;
    int i=0;
    while(getline(fs,line))
    {
        if(line_counter==0)
        {
            size=stoi(line);
            data=new Course[size];
            line_counter++;
            continue;
        }
        else if(line_counter==1)
        {
            line_counter++;
            continue;
        }
        stringstream ss(line);
        int j=0;
        while(getline(ss,word,','))
        {
            switch (j++)
            {
            case 0:
                data[i].set_code(word);
                break;
            case 1:
                data[i].set_semester(stoi(word));
                break;
            case 2:
                data[i].set_name(word);
                break;
            case 3:
                data[i].set_credits(stoi(word));
                break;
            default:
                break;
            }
        }
        line_counter++;
        i++;
    }
    fs.close();
    return data;
}

int main(int argc,char **argv)
{
    SetConsoleOutputCP(65001);
    if(argc!=2)
    {
        cerr<<"You did not provide the right amount of arguments"<<endl;
        return EXIT_FAILURE;
    }
    int size=0;
    Course *data=read_data(argv[1],size);
    for(int i=0;i<size;i++)
    {
        cout<<data[i].to_string()<<endl;
    }
    delete[] data;
    return 0;
}   