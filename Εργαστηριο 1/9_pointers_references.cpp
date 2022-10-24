#include <iostream>
#include <fstream>
using namespace std;

int read_employees(string *employee_names,double *employee_salaries)
{
    int number_of_employees;



    return number_of_employees;     
}

void statistics(string *employee_names,double *employee_salaries,int number_of_employees,string &highest_paid_employee,string lowest_paid_employee,double &average_salary)
{
    double highest_salary=employee_salaries[0];
    double lowest_salary=employee_salaries[0];
    highest_paid_employee=lowest_paid_employee=employee_names[0];
    for(int i=1;i<number_of_employees;i++)
    {
        if(employee_salaries[i]>highest_salary)
        {
            highest_paid_employee=employee_names[i];
            highest_salary=employee_salaries[i];
        }
        else if(employee_salaries[i]<lowest_salary)
        {
            lowest_paid_employee=employee_salaries[i];
            lowest_salary=employee_salaries[i];
        }
        average_salary+=employee_salaries[i];
    }
    average_salary/=number_of_employees;
}

int main()
{
    string *employee_names;
    double *employee_salaries;
    string highest_paid_employee,lowest_paid_employee;
    double average_employees_salary;
    int number_of_employes=read_employees(employee_names,employee_salaries);
    statistics(employee_names,employee_salaries,number_of_employes,highest_paid_employee,lowest_paid_employee,average_employees_salary);

    cout<<"======== Statistics =========="<<endl;
    cout<<"Highest paid employee:"<<highest_paid_employee<<endl;
    cout<<"Lowest paid employee:"<<lowest_paid_employee<<endl;
    cout<<"Average salary:"<<average_employees_salary<<endl;
    return 0;
}