#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> v{2,4,6,7,8,9};
    for(auto itr=v.begin();itr!=v.end();itr++)
    {
        cout<<"*itr:"<<*itr<<endl;
    }
    return 0;
}

