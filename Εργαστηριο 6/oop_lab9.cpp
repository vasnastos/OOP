#include <iostream>
#include <vector>
using namespace std;

template <class T> int count(vector <T> &v,const T element)
{
    int c=0;
    for(auto &x:v)
    {
        if(x==element)
        { 
            c++;
        }
    }
    return c;
    // std::count(v.begin(),v.end(),x)  // Στην βιβλιοθήκη algorithm
}

int main()
{
    vector <int> v{1,2,34,5,6,6,6,7,1,8,6,9,6,6};
    vector <double> v1{1.56,1.45,1.78,1.56,1.56,1.98,1.56,1.5};
    vector <string> v2{"toyota","audi","ford","mithsubishi","ford","ford","ford","auid","ford"};
    string mob="ford";

    cout<<"Vector V(element 6):"<<count(v,6)<<endl;
    cout<<"Vector V1(element 1.56):"<<count(v1,1.56)<<endl;
    cout<<"Vector V2(element ford):"<<count(v2,mob)<<endl;
    return 0;
}