#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(vector <int> &v)
{
    for(auto &num:v)
    {
        cout<<"Number:"<<num<<endl;
    }
    cout<<endl;
}

int main(int argc,char *argv[])
{
    mt19937 mt(steady_clock::now().time_since_epoch().count());
    if(argc!=2)
    {
        cout<<"No command line size inputed for the vector"<<endl;
        return EXIT_FAILURE;
    }
    int vector_size=stoi(argv[1]);
    auto random_value=uniform_int_distribution<int>(1,1000);
    auto random_erase_value=uniform_int_distribution<int>(0,vector_size-1);
    vector <int> v;
    for(int i=0;i<vector_size;i++)
    {
        v.emplace_back(random_value(mt));
        // v.push_back(random_value(mt));
    }
    print(v);

    cout<<endl<<"Checkpoint 1(Erase Element)"<<endl;
    v.erase(v.begin()+random_value(mt));
    print(v);

    cout<<endl<<"Checkpoint 2(Add element)"<<endl;
    v.emplace_back(random_value(mt));
    print(v);

    cout<<endl<<"Checkpoint 3(Search for an element)"<<endl;
    auto cv=v[vector_size-random_erase_value(mt)];
    cout<<"Element found at:"<<find(begin(v),end(v),cv)-v.begin()<<endl;

    cout<<endl<<"Checkpoint 4(Summary)"<<endl;
    cout<<accumulate(begin(v),end(v),0,[](int value,int s) {return s+value;})<<endl;

    cout<<endl<<"Checkpoint 5(Popback)"<<endl;
    v.pop_back();
    print(v);

    return EXIT_SUCCESS;
}