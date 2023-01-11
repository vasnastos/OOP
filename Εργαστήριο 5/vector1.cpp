#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector <int> v; // Άδειο vector
    vector <int> v1(10); //vector με 10 αντίγραφα της προκαθορισμένης τιμής.
    vector <int> v2(10,5); //vector με 10 αντίγραφα της τιμής 5.

    cout<<"Vector 1:"<<v.size()<<endl;
    cout<<"Vector 2:"<<v1.size()<<endl;
    cout<<"Vector 3:"<<v2.size()<<endl;

    cout<<"Vector 1 Capacity:"<<v.capacity()<<endl;
    cout<<"Vector 2 Capacity:"<<v1.capacity()<<endl;
    cout<<"Vector 3 Capacity:"<<v2.capacity()<<endl;

    return 0;
    // v.size() // μεγεθος vector
    // v.capacity // χωρητικότητα vector


    // Output
    // Vector 1:0
    // Vector 2:10
    // Vector 3:10
    // Vector 1 Capacity:0
    // Vector 2 Capacity:10
    // Vector 3 Capacity:10
}


