#include <iostream>
#include <random>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        cerr<<"You did not provide the right amount of arguments"<<endl;
        return EXIT_FAILURE;
    }
    int size=stoi(argv[1]);
    int **table=new int*[size];
    for(int i=0;i<size;i++)
    {
        table[i]=new int[size];
    }


    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> rand_int(1,1000);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            table[i][j]=rand_int(mt);
        }
    }
    for(int j=0;j<size;j++)
    {
        int summary=table[0][j];
        int max_elem=table[0][j];
        int min_elem=table[0][j];
        for(int i=1;i<size;i++)
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
        cout<<"Column "<<j<<" Max element:"<<max_elem<<" Min element:"<<min_elem<<" Average:"<<double(summary)/size<<endl;
    }
    for(int i=0;i<size;i++)
    {
        delete[] table[i];
    }
    delete[] table;
    return 0;
}