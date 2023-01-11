#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Employee
{
    string id;
    double salary;
    vector <double> bonus;
    public:
        static int autoincreament_id;
        Employee(double employee_salary,string salary_bonus):salary(employee_salary)
        {
            stringstream ss(salary_bonus);
            string line;
            while(getline(ss,line,','))
            {
                this->bonus.emplace_back(stod(line));
            }
            Employee::autoincreament_id++;
            this->id="Employee"+std::to_string(Employee::autoincreament_id);
        }

        double compute_salary()const
        {
            double total=this->salary*12;
            for(int i=0,t=this->bonus.size();i<t;i++)
            {
                total+=(this->bonus.at(i))-(this->bonus.at(i)*((i+1)%2==0?0.06:0.05));
            }
            return total;
        }

        void details()const
        {
            cout<<this->id<<endl;
            cout<<"Salary:"<<this->salary<<endl;
            for(int i=0;i<this->bonus.size();i++)
            {
                cout<<"Bonus:"<<this->bonus.at(i)<<"\tHold:"<<((i+1)%2==0?"6%":"5%")<<endl;
            }
            cout<<"==="<<endl;
            cout<<"Total Salary:"<<this->compute_salary()<<endl;
        }

        string to_string()const
        {
            stringstream ss;
            ss<<"Employee:"<<this->id<<"\tSalary:"<<this->salary<<"\tTotal salary:"<<this->compute_salary()<<endl;
            return ss.str();
        }

};

int Employee::autoincreament_id=0;

int main()
{
    std::string line,word;
    vector <string> data;
    vector <Employee> employees;


    // 1. Read data from input file
    fstream fp;
    fp.open("in.txt",std::ios::in);
    while(std::getline(fp,line))
    {
        data.clear();
        stringstream ss(line);
        while(getline(ss,word,' '))
        {
            data.emplace_back(word);
        }
        if(data.size()!=2) continue;
        employees.emplace_back(Employee(stod(data[0]),data[1]));
    }
    fp.close();
    cout<<"\tCHECKPOINT 1"<<endl;
    cout<<"=============="<<endl;
    for(const auto &employee:employees)
    {
        cout<<employee.to_string()<<endl;
    }
    cout<<endl;

    // 2. Sort the employee data based 
    sort(employees.begin(),employees.end(),[&](const Employee &e1,const Employee &e2) {return e1.compute_salary()<e2.compute_salary();});
    cout<<"\tCHECKPOINT 2"<<endl;
    cout<<"=============="<<endl;
    for(const auto &employee:employees)
    {
        cout<<employee.to_string()<<endl;
    }
    cout<<endl;

    // 3. 2 employees with max salaries
    cout<<"\tCHECKPOINT 3"<<endl;
    cout<<"=============="<<endl;
    for(int i=0;i<2;i++)
    {
        cout<<employees[i].to_string()<<endl;
    }
    return 0;
}
