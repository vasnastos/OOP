#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#define SIZE 10
using namespace std;
using namespace std::chrono;

mt19937 mt(high_resolution_clock::now().time_since_epoch().count());

void print_vector(vector <int> &d)
{
    static int fcalls=0;
    for(int i=0;i<d.size();i++)
    {
        cout<<"d["<<i<<"]:"<<d.at(i)<<endl;
    }
    fcalls++;

    cout<<"INFO: print_vector(vector <int> &d) calls:"<<fcalls<<endl<<endl;
}

int main()
{
    uniform_int_distribution <int> rand_int(1,5000);
    vector <int> v;
    vector <int> v2;

    for(int i=0;i<SIZE;i++)
    {
        v.push_back(rand_int(mt));
    }
    print_vector(v);


    for(int i=0;i<SIZE;i++)
    {
        v2.push_back(rand_int(mt));
    }
    print_vector(v2);

    // Συννένωση 2 vectors
    vector <int> v3(v2); // copy constructor
    v3.insert(v3.end(),v2.begin(),v2.end());
    print_vector(v3);

    // Άθροισμα vector
    cout<<"Sum(v3):"<<accumulate(v3.begin(),v3.end(),0,[&](int &s,const int &v) {return s+v;})<<endl;
    // int s=0;
    // for(auto &x:v3)
    // {
    //     s+=x;
    // }
    // cout<<"Sum(v3):"<<s<<endl;

    // Μεγιστο στοιχείο vector  
    cout<<"Max(v3):"<<*std::max_element(v3.begin(),v3.end());

    // Ελάχιστο στοιχείο vector
    cout<<"Mix(v4):"<<*std::min_element(v3.begin(),v3.end());

    // Ταξινόμηση vector
    std::sort(v3.begin(),v3.end()); // Αύξουσα
    // std::sort(v3.begin(),v3.end(),less{}); //Φθίνουσα
    print_vector(v3);

    // Αρχικό και τελικό στοιχείο vector
    cout<<"Front_element(v3):"<<v3.front()<<endl;
    cout<<"Last_element(v3):"<<v3.back()<<endl;
}