#include <iostream>
#include <vector>
using namespace std;

template <class T> T max(vector <T> &v)
{
    T max=v.at(0);
    for(int i=1,t=v.size();i<t;i++)
    {
        if(v.at(i)>max)
        {
            max=v.at(i);
        }
    }
    return max;
}

int main()
{
    vector <int> v{1,2,34,5,6,6,6,7,1,8,6,9,6,6};
    vector <double> v1{1.56,1.45,1.78,1.56,1.56,1.98,1.56,1.5,19.5,23.4,1.789};
    vector <string> v2{"nissan","toyota","audi","ford","mithsubishi","ford","ford","ford","auid","ford"};
    string mob="ford";

    cout<<"Vector V(max):"<<max(v)<<endl;
    cout<<"Vector V1(max):"<<max(v1)<<endl;
    cout<<"Vector V2(max):"<<max(v2)<<endl;
    return 0;
}