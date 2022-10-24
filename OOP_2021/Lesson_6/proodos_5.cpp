#include <iostream>

using namespace std;

int main()
{
    int b1[5]{2,7,1,3,6};
    int *b2=new int[5];
    for(int i=0;i<5;i++)
    {
        b2[i]=b1[i];
    }
    for(int i=0;i<5;i++)
    {
        cout<<b2[i]<<endl;
    }
    delete[] b2;
}