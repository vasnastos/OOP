// Γράψτε κώδικα που να πραγματοποιεί υπερφόρτωση σε μια συνάρτηση με όνομα fun 
// έτσι ώστε να υπάρχουν 3 εκδόσεις της, μια που να δέχεται 1 int παράμετρο, 
// μια που να δέχεται 1 double παράμετρο και μια που να δέχεται 1 int και 1 
// double πράμετρο. Κάθε συνάρτηση, απλά να εμφανίζει τις τιμές των παραμέτρων της. 
// Καλέστε και τις 3 συναρτήσεις από το κύριο πρόγραμμα.
// Επαναλάβατε το παράδειγμα ορίζοντας τις ανωτέρω συναρτήσεις ως συναρτήσεις μέλη μιας κλάσης A.
#include <iostream>

void fun(int p1)
{
    std::cout<<p1<<std::endl;
}

void fun(double p1)
{
    std::cout<<p1<<std::endl;
}

void fun(int p1,double p2)
{
    std::cout<<p1<<"--"<<p2<<std::endl;
}

class A
{
    public:
        void fun(int p1)
        {
            std::cout<<p1<<std::endl;
        }

        void fun(double p1)
        {
            std::cout<<p1<<std::endl;
        }

        void fun(int p1,double p2)
        {
            std::cout<<p1<<"--"<<p2<<std::endl;
        }       
};

void call_functions()
{
    fun(10);
    fun(10.5);
    fun(10,10.5);
}

void call_methods()
{
    A a;
    a.fun(10);
    a.fun(10.5);
    a.fun(10,10.5);
}

int main()
{
    call_functions();
    call_methods();
}