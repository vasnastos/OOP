#include <iostream>
#include <vector>
#include <random>
#include <chrono>

class person
{
    private:
        std::string name;
        int age;
        std::string email;
    public:
        person(std::string n,int a,std::string em):name(n),age(a),email(em) {}
        ~person() {}

        // setters
        void set_name(std::string n)
        {
            this->name=n;
        }

        void set_age(int a)
        {
            this->age=a;
        }

        void set_email(std::string mail)
        {
            this->email=mail;
        }

        std::string get_name()const
        {
            return this->name;
        }

        int get_age()const
        {
            return this->age;
        }

        std::string get_email()const{
            return this->email;
        }

        void show()
        {
            std::cout<<this->name<<" "<<this->age<<" "<<this->email<<std::endl;
        }
};

std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());

int main(int argc,char **argv)
{
    auto rt=std::uniform_int_distribution<int>(10,89);
    std::vector <person> persons;
    for(int i=1;i<=10;i++)
    {
        persons.emplace_back(person("Person_"+std::to_string(i),rt(mt),"person"+std::to_string(i)+"@gov.cvb"));
    }

    for(auto &person:persons)
    {
        person.show();
    }
    return EXIT_SUCCESS;
}