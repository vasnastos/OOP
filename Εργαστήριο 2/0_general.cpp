#include <iostream>
#include <random> // Βιβλιοθήκη για δημιουργία τυχαίων τιμών
#include <chrono> // Σαν seed το timestamp του υπολογιστή.
using namespace std;

struct Random
{
    mt19937 mt;
    uniform_int_distribution <int> random_generator;
    Random():random_generator(uniform_int_distribution <int>(1,200)),mt(chrono::high_resolution_clock::now().time_since_epoch().count()) {} // Member initialization list
    int randint() {return random_generator(mt);}
};


int main()
{
    int *a=new int[10]; //dynamic memory allocation
    double *b=new double(120.45);
    cout<<"==== CHECKPOINT 1 ====="<<endl;
    for(int i=0;i<10;i++)
    {
        a[i]=i+1;
        cout<<"a["<<i<<"]:"<<a[i]<<endl;
    }
    cout<<"B:"<<*b<<"->"<<b<<endl;


    cout<<"==== CHECKPOINT 2 ====="<<endl;    
    Random r;
    const int size=20; // Μεταβλητή με σταθερή τιμή. Δεν μπορεί να αλλάξει η τιμή της
    int values[size];
    for(int i=0;i<size;i++)
    {
        values[i]=r.randint();
    }

    for(auto &value:values) // Range for(named variable with same type as the sequence represented in range for),(a sequence[array or an object with begin and end member functions])
    {
        cout<<"Value:"<<value<<endl;
    }

    delete[] a;
    delete b;
    return 0;

}