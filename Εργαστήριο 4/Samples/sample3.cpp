#include <iostream>
using namespace std;

int main()
{
    int **table=new int*[3];
    for(int i=0;i<3;i++)
    {
        table[i]=new int[3];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            table[i][j]=i+j;
            cout<<"table["<<i<<"]["<<j<<"]:"<<table[i][j]<<endl;
        }
    }

    for(int i=0;i<3;i++)
    {
        delete[] table[i];
    }
    delete[] table;
    return 0;
}