#include <iostream>

void increase_by_reference(int &a)
{
    a++;
    std::cout<<"Memory adress:"<<&a<<std::endl;
}

void reduce_by_value(int &a)
{
    a--;
    std::cout<<"Memory adress:"<<&a<<std::endl;
}


int main()
{
    int a1=19,a2=45;
    std::cout<<"A1:"<<a1<<std::endl;
    increase_by_reference(a1);
    std::cout<<"A1:"<<a1<<std::endl<<std::endl;
    std::cout<<"A2:"<<a2<<std::endl;
    reduce_by_value(a2);
    std::cout<<"A2:"<<a2<<std::endl;
    return 0;
}