#include <iostream>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print(int **a,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<std::endl;
        }
    }
}

int main()
{
    mt19937 mt(steady_clock::now().time_since_epoch().count());
    int rows=5;
    int columns=6;
    int **a=new int*[rows];
    auto rand_int=uniform_int_distribution<int>(1,1000);
    for(int i=0;i<5;i++)
    {
        a[i]=new int[columns];
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            a[i][j]=rand_int(mt);
        }
    }
    print(a,rows,columns);
    for(int i=0;i<rows;i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return EXIT_SUCCESS;
}