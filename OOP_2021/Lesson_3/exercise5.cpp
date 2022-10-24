#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void statistics(int *board,int size,int *max,int *min,double *avg)
{
    *avg=static_cast<double>(board[0]);
    *max=board[0];
    *min=board[0];
    for(int i=1;i<size;i++)
    {
        if(board[i]>*max)
        {
            *max=board[i];
        }
        if(board[i]<*min)
        {
            *min=board[i];
        }
        *avg+=static_cast<double>(board[i]);
    }
    *avg/=size;
}

int main()
{
    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    int *a=new int[10];
    auto rand_int=uniform_int_distribution<int>(1,1000);
    for(int i=0;i<10;i++)
    {
        a[i]=rand_int(mt);
    }
    int max,min;
    double avg;
    statistics(a,10,&max,&min,&avg);
    cout<<"Max Element:"<<max<<endl;
    cout<<"Min Element:"<<min<<endl;
    cout<<"Avarage value:"<<avg<<endl;
    delete[] a;
    return EXIT_SUCCESS;
}