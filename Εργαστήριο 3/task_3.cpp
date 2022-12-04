#include <iostream>
using namespace std;

int main()
{
    int table[]{2,7,1,3,6};
    int x;
    cout<<"Number of copies:";
    cin>>x;
    const int size=(sizeof(table)/sizeof(table[0]));
    const int new_size=size*x;
    int *dynamic_table=new int[new_size];
    for(int copy_i=0;copy_i<x;copy_i++)
        for(int i=0;i<sizeof(table)/sizeof(table[0]);i++)
        {
            dynamic_table[copy_i*size+i]=table[i];
        }
    // for(int i=0;i<new_size;i++)
    // {
    //     dynamic_table[i]=table[i%size];
    // }
    for(int i=0;i<(sizeof(table)/sizeof(table[0]))*x;i++)
    {
        cout<<"dynamic_table["<<i<<"]:"<<dynamic_table[i]<<endl;
    }
    delete[] dynamic_table;
}