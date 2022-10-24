#include <iostream>

using namespace std;

void swap(int &a,int &b) {
    int temp=a;
    a=b;
    b=a;
}

int main()
{
    int a=10,b=12;
    cout<<"a:"<<a<<"\tb:"<<b<<endl;// a:10 b:12
    swap(a,b);
    cout<<"a:"<<a<<"\tb:"<<b<<endl;// a:12 b:10
    return 0;
}