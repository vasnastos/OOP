#include <iostream>
#include <chrono>
#include <random>
#define components 3
#define nitems 1000
using namespace std;
using namespace std::chrono;
mt19937 mt(high_resolution_clock::now().time_since_epoch().count());

double* momentum(double *velocity,double mass)
{
    double *m=new double[nitems];
    for(int i=0;i<components;i++)
    {
        m[i]=velocity[i]*mass;
    }
    return m;
}

double* rand_vec()
{
    uniform_real_distribution<double> rand_real(-100,100);
    double *vector=new double[2];
    for(int i=0;i<2;i++)
    {
        vector[i]=rand_real(mt);
    }
    return vector;
}

int main()
{
    uniform_real_distribution <double> rand_real(1.0,10);
    double **items=new double*[nitems];
    double **momentum_vals=new double*[nitems];
    
    for(int i=0;i<nitems;i++)
    {
        items[i]=rand_vec();
        momentum_vals[i]=momentum(items[i],rand_real(mt));
    }

    double avg;
    for(int j=0;j<components;j++)
    {
        avg=0.0;
        for(int i=0;i<nitems;i++)
        {
            avg+=items[i][j];
        }
        cout<<"Component "<<j<<":"<<avg/nitems<<endl;
    }

    delete[] momentum_vals;
    for(int i=0;i<nitems;i++)
    {
        delete[] items[i];
    }
    delete[] items;
    return EXIT_SUCCESS;
}