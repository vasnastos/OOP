#include <iostream>
#include <map>

std::map <std::string,double> hpossibility
{
  {"sleep",0.75},
  {"tailing",0.45},
  {"barking",0.6}
};

class Dog
{
    private:
        std::string name;
        std::string status;
    public:
        Dog(std::string n,std::string s):name(n),status(s) {}
        ~Dog() {}

        // Setters
        void set_name(std::string n)
        {
            this->name=n;
        }

        void set_status(std::string s)
        {
            this->status=s;
        }

        // getters
        std::string get_name()const
        {
            return this->name;
        }

        std::string get_status()const{
            return this->status;
        }

        bool is_hungry(double pval,double possibility)
        {
            return pval>possibility * hpossibility[this->status];
        }

        void show()
        {
            std::cout<<"Name:"<<this->name<<"\tStatus:"<<this->status<<std::endl;
        }
};

int main()
{
    Dog d1("Alf","Sleep");
    Dog d2("Ralf","tailing");
    Dog d3("Azor","Hungry");

    std::cout<<"Dog d1:"<<d1.get_name()<<" "<<d1.get_status()<<std::endl;
    std::cout<<"Dog d2:"<<d2.get_name()<<" "<<d2.get_status()<<std::endl;
    std::cout<<"Dog d3:"<<d3.get_name()<<" "<<d3.get_status()<<std::endl;

    d1.show();
    d2.show();
    d3.show();
}