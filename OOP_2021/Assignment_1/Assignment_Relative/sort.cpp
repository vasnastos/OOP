#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec{5,1,78,12,34};
    for(auto &x:vec)
    {
        cout<<x<<endl;
    }
    cout<<endl;
    sort(vec.begin(),vec.end());
    cout<<"After Sorting"<<endl;
    for(auto &x:vec)
    {
        cout<<x<<endl;
    }
    vector <pair <int,double>> a{
        {1,1.6},{2,6.7},{1,7.6}
    };
    cout<<endl;
    for(auto &rec:a)
    {
        cout<<"{"<<rec.first<<","<<rec.second<<"}"<<endl;
    }
    sort(a.begin(),a.end());
    cout<<endl<<"After Sorting"<<endl;
    for(auto &rec:a)
    {
        cout<<"{"<<rec.first<<","<<rec.second<<"}"<<endl;
    }
    return EXIT_SUCCESS;
}