#include<iostream>

using namespace std;

//Works on C and C++
typedef struct
{
    char name[20];
    int age;
    double grade;
}student;

/*Εναλλακτική δήλωση struct

struct student
{
    char name[20];
    int age;
    double grade;
}; 

*/

int main()
{
    student s1;
    
    cout<<"Give name of student s1 : ";
    cin>>s1.name;
    cout<<endl<<"Give age of student s1 : ";
    cin>>s1.age;
    cout<<endl<<"Give grade of student s1 : ";
    cin>>s1.grade;

    cout<<"Student s1 has the following data :"<<endl
    <<"Name : "<<s1.name<<endl
    <<"Age : "<<s1.age<<endl
    <<"Grade : "<<s1.grade<<endl;
}