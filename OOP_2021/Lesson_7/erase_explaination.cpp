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

    // Διαγραφή πρώτος τρόπος
    int id=7;
    auto itr=find_if(students.begin(),students.end(),[&](const Student &s) {return s.get_id()==id;});
    students.erase(itr);
    cout<<"Student with id:"<<id<<" erased from the list"<<endl;

    // Διαγραφή δεύτερος τρόπος
    id=8;
    int id1=9;
    itr=std::remove(students.begin(),students.end(),[&](const Student &s) {return s.get_id()==id || s.get_id()==id1;});
    students.erase(itr,students.end());
    cout<<"Student with id:"<<id<<" erased from the list"<<endl;

    for(auto &s:students)
    {
        cout<<s<<endl;
    }
    return EXIT_SUCCESS;
}