#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Employee
{
private:
	std::string name;
	double salary;
public:
	Employee(std::string n, double s):name(n),salary(s) {}
	~Employee() {}

	void set_name(std::string n)
	{
		this->name = n;
	}

	void set_salary(double s)
	{
		this->salary = s;
	}

	std::string get_name()const { return this->name; }
	double get_salary()const { return this->salary; }

	friend ostream& operator<<(ostream& os, const Employee& e)
	{
		return os << e.name << " " << e.salary;
	}
};

void menu()
{
	system("cls");
	std::cout << "1.Insert employee" << std::endl;
	std::cout << "2.Delete employee" << std::endl;
	std::cout << "3.Update employee record" << std::endl;
	std::cout <<"4.Display Employees"<<std::endl;
	std::cout << "5.Exit" << std::endl;
	std::cout << "Select choice:";
}

void display_employees(vector <Employee> &emps)
{
	for (auto& e : emps)
	{
		cout << e << endl;
	}
}

void employees_selection(vector <Employee>& emps)
{
	for (int i = 0, t = emps.size(); i < t; i++)
	{
		cout << i << "." << emps[i] << endl;
	}
	cout << "Select Employee:";
}

int main()
{
	std::vector <Employee> employees;
	int choice,eindex;
	std::string name;
	double salary;
	while (true)
	{
		menu();
		std::cin >> choice;
		vector<Employee>::iterator eitr;
		switch (choice)
		{
			case 1:
				system("cls");
				cin.ignore();
				std::cout << "Give employees name:";
				std::getline(std::cin, name);
				std::cout << "Give employees salary:";
				std::cin >> salary;
				eitr = std::find_if(employees.begin(), employees.end(), [&](const Employee& e) {return e.get_name() == name; });
				if (eitr != employees.end())
				{
					std::cout << "Employee " << name << " already in system" << std::endl;
					break;
				}
				employees.push_back(Employee(name, salary));
				std::cout << "Employee Inserted:(" << name << "," << salary << ")" << std::endl;
				system("pause");
				break;
			case 2:
				system("cls");
				if (employees.size() == 0) break;
				employees_selection(employees);
				cin >> eindex;
				while (eindex<0 || eindex>=employees.size())
				{
					cout << "Please select a valid index[0-" << employees.size() - 1 << "]";
					cin >> eindex;
				}
				employees.erase(employees.begin() + eindex);
				system("pause");
				break;
			case 3:
				if (employees.size() == 0) break;
				system("cls");
				employees_selection(employees);
				cin >> eindex;
				while (eindex<0 || eindex>employees.size())
				{
					cout << "Please select a valid index[0-" << employees.size() - 1 << "]";
					cin >> eindex;
				}
				cin.ignore();
				cout << "Give new employee name[enter for no change]:";
				getline(cin, name);
				cout << "Give new employee salary[-1 for no change]:";
				cin >> salary;
				if(name!="")
				employees[eindex].set_name(name);
				if(salary>0)
				employees[eindex].set_salary(salary);
				system("pause");
				break;
			case 4:
				display_employees(employees);
				system("pause");
				break;
			case 5:
				exit(EXIT_SUCCESS);
		}
	}
}