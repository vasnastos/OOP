#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
    int b=10;
    int &a=b;
    a++;
    cout<<"A:"<<a<<"\t"<<"B:"<<b<<endl;
    return 0;
}