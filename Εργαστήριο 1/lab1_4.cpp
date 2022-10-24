#include <iostream>
using namespace std;

void summary(int *a,int *sum,double *avg,int size)
{
    *sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=*(a+i);
    }

    *avg=static_cast<double>(*sum)/size;
}

int main(int argc, char **argv)
{
    int a[]{12,34,67,98,12,23};
    int sum;
    double avg;
    summary(a,&sum,&avg,sizeof(a)/sizeof(a[0]));
    cout<<"Sum:"<<sum<<"\tAverage:"<<avg<<endl;
    return 0;
}