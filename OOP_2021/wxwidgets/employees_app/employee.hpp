#include <sstream>
#include <vector>
#include <string>

struct employee
{
    std::string id;
    std::string name;
    double salary;
    employee(std::string i,std::string n,double s):id(i),name(n),salary(s) {}
    operator std::string()const
    {
        std::stringstream ss;
        ss<<this->id<<"  "<<this->name<<"  "<<this->salary<<std::endl;
        return ss.str();
    }
};