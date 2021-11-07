#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template <class T>
void print(vector <T> &vec)
{
     for(auto &name:vec)
    {
        cout<<name<<endl;
    }
    cout<<endl;
}

int main(int argc,char **argv)
{
    vector <int> v{3,7,9,12,34,56,76,14,22};
    vector <string> v1{"Maria","Nikos","Vasilis","Alexandros","Christos","Eleni","Vaggelis"};
    cout<<"Vector with Integers"<<endl;
    print(v);
    sort(v.begin(),v.end());
    print(v);
    cout<<"Vector with strings"<<endl;
    print(v1);
    sort(v1.begin(),v1.end());
    print(v1);
    return EXIT_SUCCESS;
}