#include <iostream>
using namespace std;

int main()
{
     //memory dynamic allocat 
    int *a=new int(15);
    cout<<"Memory:"<<a<<"\tValue:"<<*a<<endl;
    delete a;

    int *b=new int(4);
    int table_summary=0;
    for(int i=0;i<4;i++)
    {
        b[i]=i;
    }
    delete[] b;
}