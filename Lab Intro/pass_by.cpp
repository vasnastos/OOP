#include<iostream>

using namespace std;

void swap_by_value(int a, int b)
{
    int temp;
    temp = b;
    b = a;
    a = temp;
}

void swap_by_reference(int &a, int &b)
{
    int temp;
    temp = b;
    b = a;
    a = temp;
}

int main()
{
    int a = 3;
    int b = 4;

    swap_by_value(a,b);
    cout<<"Values after calling swap_by_value() "<<endl
    <<"a = "<<a<<" , b = "<<b<<endl;

    swap_by_reference(a,b);
    cout<<"Values after calling swap_by_reference() "<<endl
    <<"a = "<<a<<" , b = "<<b<<endl;
}