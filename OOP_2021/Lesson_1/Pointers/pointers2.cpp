#include <iostream>
#include <random>
#include <chrono>
#include <ostream>
#include <iterator>
#include <algorithm>

int main()
{
    std::mt19937 mt(std::chrono::high_resolution_clock().now().time_since_epoch().count());
    int *a=new int(14);
    int *b=new int[10];
    auto un_id=std::uniform_int_distribution<int>(1,1000);
    for(int i=0;i<10;i++)
    {
        b[i]=un_id(mt);
    }
    std::ostream_iterator <int> output(std::cout,",");
    std::copy(b,b+10,output);
    delete a;
    std::cout<<"Memery used:"<<a<<std::endl;
    std::cout<<"A variable value:"<<*a<<std::endl;
    delete[] b;
    return 0;
}