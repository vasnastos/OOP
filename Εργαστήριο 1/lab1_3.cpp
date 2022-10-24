#include <iostream>

using namespace std;

int main()
{
    int b=10;
    int *a=&b;
    cout<<"A:"<<a<<"\t"<<"B:"<<b<<"*A:"<<*a<<endl;
    delete a;
    return 0;
}