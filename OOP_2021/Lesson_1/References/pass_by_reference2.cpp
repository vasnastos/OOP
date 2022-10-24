#include <iostream>
#include <random>
#include <chrono>

std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

void summary_operator(int &s,double &avg,int *acv,int ns)
{
    s=0;
    for(int i=0;i<ns;i++)
    {
        s+=acv[i];
    }
    avg=static_cast<double>(s)/static_cast<double>(ns);
}

void fill_number(int ns,int *vcg)
{
    auto un_ran=std::uniform_int_distribution<int>(1,1000);
    for(int i=0;i<ns;i++)
    {
        vcg[i]=un_ran(mt);
    }
}

int main()
{
    int summary,*table_s;
    table_s=new int[10];
    fill_number(10,table_s);
    double average_grade;
    summary_operator(summary,average_grade,table_s,10);
    std::cout<<"Table components:10"<<std::endl;
    std::cout<<"Summary:"<<summary<<std::endl;
    std::cout<<"Table average:"<<average_grade<<std::endl;
    return 0;
}