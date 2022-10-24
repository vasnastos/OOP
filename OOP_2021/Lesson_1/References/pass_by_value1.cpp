#include <iostream>

void increase_by_reference(int &a)
{
    a++;
    std::cout<<"Memory adress:"<<&a<<std::endl;
}

void reduce_by_pointer(int *a)
{
    (*a)--;
    std::cout<<"Memory adress:"<<&a<<std::endl;
}

void reduce_by_value(int b)
{
    b--;
    std::cout<<"Memory adress:"<<&b<<std::endl;
}

int main()
{
    int a1=19;
    std::cout<<"Memory position:"<<&a1<<std::endl;
    std::cout<<"A1:"<<a1<<std::endl;
    increase_by_reference(a1);
    std::cout<<"A1:"<<a1<<std::endl;

    std::cout<<std::endl<<"Memory position:"<<&a1<<std::endl;
    std::cout<<"A1:"<<a1<<std::endl;
    reduce_by_pointer(&a1);
    std::cout<<"A1:"<<a1<<std::endl;
    std::cout<<std::endl<<"Memory position:"<<&a1<<std::endl;
    std::cout<<"A1:"<<a1<<std::endl;
    reduce_by_value(a1);
    std::cout<<"A1:"<<a1<<std::endl;
    return 0;
}