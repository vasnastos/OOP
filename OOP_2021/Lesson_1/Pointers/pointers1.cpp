#include <iostream>
#include <cstdlib>

int main()
{
    int a;
    std::cout<<"Give number a:";
    std::cin>>a;
    int *pa;
    pa=&a;
    int *pb=new int(13);
    std::cout<<"Memory adreess:"<<pa<<std::endl;
    std::cout<<"Value:"<<*pa<<std::endl;
    std::cout<<"Memory adress:"<<pb<<std::endl;
    std::cout<<*pb<<std::endl;
    delete pb;
    return 0;
}