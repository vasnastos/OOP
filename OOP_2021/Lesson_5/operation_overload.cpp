// Δημιουργήστε μια κλάση customer με 2 ιδιωτικά μέλη δεδομένων name και balance (υπόλοιπο λογαριασμού). Υπερφορτώστε τους τελεστές < και == για τα αντικείμενα customer έτσι 
// ώστε η σύγκριση μεταξύ τους να γίνεται με βάση το υπόλοιπο του λογαριασμού. 
// Στο κύριο πρόγραμμα δημιουργήστε αντικείμενα customer και χρησιμοποιήστε τους 
// τελεστές < και ==.

#include <iostream>

using namespace std;

class customer
{
    private:
        string name;
        double balance;
    public:
        customer(string n,double b):name(n),balance(b) {}
        bool operator<(const customer &c)const
        {
            return this->balance<c.balance;
        }
        bool operator==(const customer &c)const
        {
            return this->balance==c.balance;
        }

        std::string get_name()const 
        {
            return this->name;
        }
};

int main()
{
    customer c1("Vasilis",1000);
    customer c2("Christos",2000);
    customer c3("Angelos",1000);
    if(c1<c2)
    {
        std::cout<<"Customer "<<c1.get_name()<<" has lower balance than customer "<<c2.get_name()<<std::endl;
    }
    if(c1==c3)
    {
        std::cout<<"Customer "<<c1.get_name()<<" has equal balance than customer "<<c3.get_name()<<std::endl;
    }
}