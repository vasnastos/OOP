#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a+b;
}

double add(double a, double b)
{
    return a+b;
}

string add(string a, string b)
{
    return a + b;
}

int main()
{
    int a=6, b=8;
    double d=4.3, e=6.28;
    string g="John ", h="Doe";

    cout<<"Addition of a and b equals: "<<add(a,b)<<endl;

    cout<<"Addition of d and e equals: "<<add(d,e)<<endl;

    cout<<"Addition of g and h equals: "<<add(g,h)<<endl;
}