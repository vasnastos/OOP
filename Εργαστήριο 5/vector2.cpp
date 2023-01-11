#include <iostream>
#include <random>
#include <chrono>
#define SIZE 30
using namespace std;
using namespace std::chrono;

mt19937 mt(high_resolution_clock::now().time_since_epoch().count());

int main()
{
    uniform_int_distribution <int> rand_int(1,5000);
    vector <int> v;
    
    // Προσθήκη τυχαίων τιμών στο διάστημα [1,5000] στο vector v
    for(int i=0;i<SIZE;i++)
    {
        v.push_back(rand_int(mt));
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<"v["<<i<<"]:"<<v[i]<<endl;
    }
    return 0;
}


