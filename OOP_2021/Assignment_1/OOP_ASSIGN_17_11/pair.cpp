#include <iostream>
#include <vector>
using namespace std;

int main()
{ 
    vector <pair <int,double>> numbers;
    for(int i=1;i<10;i++)
    {
        numbers.push_back(pair <int,double>(i,i+0.5));
        // numbers.push_back(make_pair(i,i+0.5))
    }
    cout<<"Size:"<<numbers.size()<<endl;
    int a;
    pair <int,int> p(1,2);
    p.first=3;
    p.second=4;
    cout<<p.first<<"-"<<p.second<<endl;

    // for(int i=0;i<numbers.size();i++)
    // {
    //     cout<<numbers[i].first<<"-"<<numbers[i].second<<endl;
    // }
}