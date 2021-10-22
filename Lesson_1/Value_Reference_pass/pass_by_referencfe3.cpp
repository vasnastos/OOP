#include <iostream>

void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}

void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

int main()
{
    int a1=12;
    int a2=14;
    std::cout<<"A1:"<<a1<<"\tA2:"<<a2<<std::endl;
    swap(a1,a2);
    std::cout<<"A1:"<<a1<<"\tA2:"<<a2<<std::endl;

    int b1=15,b2=16;
    std::cout<<"B1:"<<b1<<"\tB2:"<<b2<<std::endl;
    swap(&b1,&b2);
    std::cout<<"B1:"<<b1<<"\tB2:"<<b2<<std::endl;
    return 0;
}