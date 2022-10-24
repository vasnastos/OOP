#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
    private:
        int id;
        std::string name;
    public:
        Student(int i,std::string n):id(i),name(n) {}
        ~Student() {}

        int get_id()const {return id;}

        bool operator==(const Student &s)const
        {
            return this->id==s.id;
        }
        friend ostream &operator<<(ostream &os,const Student &s)
        {
            return os<<s.name<<"-"<<s.id;
        }
};

int main()
{
    vector <Student> students{
        {1,"Student_1"},
        {2,"Student_2"},
        {3,"Student_3"},
        {4,"Student_4"},
        {5,"Student_5"},
        {6,"Student_6"},
        {7,"Student_7"},
        {8,"Student_8"},
        {9,"Student_9"},
        {10,"Student_10"}
    };

    // Αναζήτηση φοιτητή με id 7
    int id=7;
    auto st_itr=find_if(students.begin(),students.end(),[&](const Student &s) {return s.get_id()==id;});
    bool exists=st_itr!=students.end();
    if(exists)
    {
        cout<<*st_itr<<"->"<<boolalpha<<exists<<endl;
    }
    else
    {
        cout<<"Student with id:"<<id<<"->"<<boolalpha<<exists<<endl;
    }

    // Αναζήτηση φοιτητή με id 19
    id=19;
    st_itr=find_if(students.begin(),students.end(),[&](const Student &s) {return s.get_id()==id;});
    // st_itr==students.end()
    exists=(st_itr!=students.end());
    if(exists)
    {
        cout<<*st_itr<<"->"<<boolalpha<<exists<<endl;
    }
    else
    {
        cout<<"Student with id:"<<id<<"->"<<boolalpha<<exists<<endl;
    }
}