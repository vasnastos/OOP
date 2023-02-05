#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T> int binary_search(vector <T> &v,const T value)
{
    sort(v.begin(),v.end());
    int r=v.size()-1;
    int l=0;
    while(r>=l)
    {
        int mid_index=(r+l)/2;
        if(v[mid_index]<value)
        {
            l=mid_index+1;
        }
        else if(v[mid_index]>value)
        {
            r=mid_index-1;
        }
        else
            return mid_index;
    }
    return -1;
}

int main()
{
    vector <int> v1{5,6,7,8,4,12,34,67,9,22};
    vector <string> v2{"anna","vasilis","bill","maria","nikos","giannis"};
    vector <double> v3{5.67,7.8,9.1,2.19,4.4,2.3,5.6};

    cout<<"Position of Integer(34):"<<binary_search(v1,34)<<endl;
    cout<<"Position of String(maria):"<<binary_search(v2,string("maria"))<<endl;
    cout<<"Position of Double(5.67):"<<binary_search(v3,5.67)<<endl;
    return 0;
}

// Position of Integer(34):8
// Position of String(maria):3
// Position of Double(5.67):4