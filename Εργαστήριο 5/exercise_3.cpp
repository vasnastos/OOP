#include <iostream>
#include <string>
using namespace std;

class Person
{
    protected:
        int age;
    public:
        static int number_of_instances;
        Person(int _age):age(_age) {Person::number_of_instances++;}
        virtual ~Person() {}
        virtual double compute_earnings()const=0;

        virtual string to_string()const=0;
};

class Teacher:public Person
{
    string profession;
    public:
        Teacher(int _age,string _profession):Person(_age),profession(_profession) {}
        ~Teacher() {}
        double compute_earnings()const
        {
            return 1000;
        }
        string to_string()const {
            return "Age:"+std::to_string(this->age)+"  Profession:"+this->profession+"  Earnings:"+std::to_string(this->compute_earnings());
        }
};

class FootBaller:public Person
{
    string team;
    public:
        FootBaller(int _age,string _team):Person(_age),team(_team) {}
        ~FootBaller() {}
        double compute_earnings()const
        {
            return 100000;
        }
        string to_string()const {
            return "Age:"+std::to_string(this->age)+"  Team:"+this->team+"  Earnings:"+std::to_string(this->compute_earnings());
        }
};

int main()
{
    Person *persons[5];
    int object;
    int age;
    string value;

    // 1. Insert data
    for(int i=0;i<5;i++)
    {
        while(true)
        {
            cout<<"Select object(1|Teacher, 2|FootBaller):";
            cin>>object;
            if(object==1 || object==2)
            {
                break;
            }
        }
        cout<<endl<<endl;
        if(object==1)
        {
            cout<<"Insert teacher's age:";
            cin>>age;

            cout<<"Insert teacher's profession:";
            cin>>value;
            persons[i]=new Teacher(age,value);
        }
        else if(object==2)
        {
            cout<<"Insert footballer's age:";
            cin>>age;

            cout<<"Insert footballer's team:";
            cin>>value;
            persons[i]=new FootBaller(age,value);
        }
        cout<<endl<<endl;
    }

    // 2. Number of persons
    cout<<"Persons created:"<<Person::number_of_instances<<endl<<endl;

    // 3. Display the persons available
    cout<<"Persons List"<<endl;
    cout<<"===="<<endl;
    for(int i=0;i<5;i++)
    {
         cout<<persons[i]->to_string()<<endl;
    }

    for(int i=0;i<5;i++)
    {
        delete persons[i];
    }
    return 0;
}