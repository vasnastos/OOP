#include <iostream>

void reduce_by_pointer(int *a)
{
    (*a)--;
    std::cout<<"Memory adreess:"<<a<<std::endl;
}

void increase_by_pointer(int *a)
{
    (*a)++;
    std::cout<<"Memory adreess:"<<a<<std::endl;
}

int main()
{
    int a1=34,a2=56;
    std::cout<<"A1:"<<a1<<std::endl;
    increase_by_pointer(&a1);
    increase_by_pointer(&a1);
    std::cout<<"A1:"<<a1<<std::endl;
    reduce_by_pointer(&a2);
    reduce_by_pointer(&a2);
    std::cout<<"A2:"<<a2<<std::endl;
    return 0;
}