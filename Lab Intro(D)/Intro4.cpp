#include<iostream>

using namespace std;

template <class T> T add(T a, T b)
{
    return a + b;
}

int main()
{
    int a=4, b=6;
    double c=3.4, d=5.9;
    string e="John ", f="Doe";

    cout<<"Integer addition, equals: "<<add(a,b)<<endl;

    cout<<"Double addition, equals: "<<add(c,d)<<endl;

    cout<<"String addition, equals: "<<add(e,f)<<endl;
}