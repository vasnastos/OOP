#include <iostream>
#include <random>
#include <chrono>
#define NROWS 10
#define NCOLS 10
using namespace std;
using namespace std::chrono;

int main()
{
    int table[NROWS][NCOLS];
    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> rand_int(1,1000);
    for(int i=0;i<NROWS;i++)
    {
        for(int j=0;j<NCOLS;j++)
        {
            table[i][j]=rand_int(mt);
        }
    }
    for(int j=0;j<NCOLS;j++)
    {
        int summary=table[0][j];
        int max_elem=table[0][j];
        int min_elem=table[0][j];
        for(int i=1;i<NROWS;i++)
        {
            summary+=table[i][j];
            if(table[i][j]>max_elem)
            {
                max_elem=table[i][j];
            }
            else if(table[i][j]<min_elem)
            {
                min_elem=table[i][j];
            }
        }
        cout<<"Column "<<j<<" Max element:"<<max_elem<<" Min element:"<<min_elem<<" Average:"<<double(summary)/NROWS<<endl;
    }
    return 0;
}