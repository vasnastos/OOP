#include <iostream>

using namespace std;


int main()
{
    int table[5];
    for(int i=0;i<5;i++)
    {
        cout<<"Give table["<<i<<"]:";
        cin>>table[i];
    }

    for(int i=4;i>=0;i--)
    {
        cout<<"table["<<i<<"]:"<<*(table+i)<<endl;
    }
    return 0;
}