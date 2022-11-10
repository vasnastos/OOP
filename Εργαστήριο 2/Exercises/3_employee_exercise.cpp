// Να κατασκευαστεί κλάση employee που θα περιέχει τα ακόλουθα μέλη δεδομένα
// ID: Τυχαίος αριθμός
// Name: όνομα υπαλλήλου
// Lastname: επώνυμο υπαλλήλου
// Salary: μισθός υπαλλήλου
// child_number

// 1. Να δημιουργηθεί κατασκευαστεί κατασκευαστής που θα αρχικοποιεί τα μέλη της κλάσης με βάση τις παραμέτρους που θα δέχεται
// 2. Να υλοποιηθούν setters και getters για όλα τα μέλη δεδομένα της κλάσης
// 3. Να υλοποιηθεί συνάρτηση increase_salary(percent) που θα αυξάνει τον μισθό ενός υπαλλήλου με βάση την παράμετρο ποσοστο.
// 4. Να υλοποιηθεί συνάρτηση annual_salary που θα υπολογίζει τον ετήσιο μισθό ενός υπαλλήλου.
// Ο μισθός υπολογίζεται ως εξής:
//     Τους Μονούς μήνες(1,3,5,....) υπάρχει παρακράτηση φόρου 5%
//     Τους ζυγούς μήνες(2,4,6) υπάρχει παρακράτηση φόρου 6% 
//     Αν ένας υπάλληλος έχει 1 παιδί η ετήσια επιστροφή φόρου είναι 1%
//     Αν ένας υπάλληλος έχει 2 παιδί η ετήσια επιστροφή φόρου είναι 2%
//     Αν ένας υπάλληλος έχει 3 παιδιά η ετήσια επιστροφή φόρου είναι 4%

// 5. Να κατασκευαστεί συνάρτηση display που θα εμφανίζει τα στοιχεία ενός υπαλλήλου καθώς και τον συνολικό μισθό

// Α. Στην κύρια συνάρτηση, Να δημιουργηθεί δυναμικός πίνακας με 10 υπαλλήλους
// Β. Όσοι υπάλληλοι έχουν ετήσιο μισθό κάτω από 10000 να υπάρχει αύξηση μισθού κατά 10%
// Γ. Να εμφανιστούν τα στοιχεία όλων των υπαλλήλων.
// ΠΡΟΕΡΕΤΙΚΑ: Να κατασκευαστεί συνάρτηση η οποία θα αποθηκεύει τα δεδομένα των υπαλλήλων σε ένα αρχείο.

#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;
using namespace std::chrono;
auto seed=high_resolution_clock::now().time_since_epoch().count();

struct Random{
    mt19937 mt=mt19937(seed);
    uniform_int_distribution<int> dist;
    Random() {}
    int rand_int(int lb,int ub) {
        uniform_int_distribution<int> dist(lb,ub);
        return dist(mt);
    }
    int rand_double(int lb,int ub)
    {
        uniform_real_distribution<double> ds(lb,ub);
        return ds(mt);
    }
};

class Employee
{
    static Random generator;
    private:
        int id;
        string name;
        string lastname;
        double salary;
        int child_number;
    public:
        Employee():id(Employee::generator.rand_int(0,10000)),name(""),lastname(""),salary(-1),child_number(-1) {}
        Employee(int employee_id,string employee_name,string employee_lastname,double employee_salary,int employee_child_number) {
            this->id=Employee::generator.rand_int(0,10000);
            this->name=employee_name;
            this->lastname=employee_lastname;
            this->salary=employee_salary;
            this->child_number=employee_child_number;
        }
        ~Employee() {}
        
        // setters
        void set_id(int new_id) {this->id=new_id;}
        void set_name(string new_name) {this->name=new_name;}
        void set_lastname(string new_lastname) {this->lastname=new_lastname;}
        void set_salary(double new_salary) {this->salary=new_salary;}
        void set_child_number(int new_child_number) {this->child_number=new_child_number;}

        // getters
        int get_id()const {return this->id;}
        string get_name()const {return this->name;}
        string get_lastname()const {return this->lastname;}
        double get_salary()const {return this->salary;}
        int get_child_number()const {return this->child_number;}

        // member function read_salary
        void increase_salary(double percentance_)
        {
            this->salary+=(percentance_*this->salary);
        }

        // member function annual salary
        double annual_salary()
        {
            int ann_salary=0;
            for(int i=1;i<=12;i++)
            {
                if(i%2==0)
                {
                    ann_salary+=this->salary*0.94;
                }
                else
                {
                    ann_salary+=this->salary*0.95;
                }
            }
            if(this->child_number==1)
            {
                ann_salary+=0.01*this->salary;
            }
            else if(this->child_number==2)
            {
                ann_salary+=this->salary*0.02;
            }
            else{
                ann_salary+=this->salary*0.03;
            }
            return ann_salary;
        }
};

Random Employee::generator=Random();

void employee_random_table_generator(Employee *employees,int number_of_employees)
{
    Random rand_generator;
    for(int i=0;i<number_of_employees;i++)
    {
        employees[i].set_name("Employee_Name_"+to_string(i+1));
        employees[i].set_lastname("Employee_Lastname_"+to_string(i+1));
        employees[i].set_salary(rand_generator.rand_double(500,5000));
        employees[i].set_child_number(rand_generator.rand_int(1,6));
    }
}

// ΠΡΟΕΡΕΤΙΚΟ ΕΡΩΤΗΜΑ
void save(Employee *employees,int size)
{
    fstream fs;
    fs.open("employees.txt",ios::out);
    for(int i=0;i<size;i++)
    {
        fs<<employees[i].get_id()<<"-"<<employees[i].get_name()<<"-"<<employees[i].get_lastname()<<"-"<<employees[i].get_salary()<<"-"<<employees[i].get_child_number()<<endl;
    }
    fs.close();

    // c-like save to file code
    // FILE *fp=fopen("employees.txt","w");
    // for(int i=0;i<size;i++)
    // {
    //     fprintf(fp,"%d-%s-%s-%lf-%d\n",employees[i].get_id(),employees[i].get_name().c_str(),employees[i].get_lastname().c_str(),employees[i].get_salary(),employees[i].get_child_number());
    // }
    // fclose(fp);
}

int main()
{
    Employee *employees=new Employee[10];
    employee_random_table_generator(employees,10);
    for(int i=0;i<10;i++)
    {
        cout<<"Employee:"<<employees[i].get_id()<<endl;
        cout<<"\t"<<employees[i].get_name()<<"-"<<employees[i].get_lastname()<<"-"<<employees[i].get_salary()<<"-"<<employees[i].get_child_number()<<endl;
        if(employees[i].annual_salary()<10000)
        {
            employees[i].set_salary(employees[i].get_salary()+0.1*employees[i].get_salary());
            cout<<"Salary(Renew):"<<employees[i].annual_salary();
        }
        else
        cout<<"Salary:"<<employees[i].annual_salary();
        cout<<endl<<endl;
    }
    // save(employees,size);
    delete[] employees;
}
