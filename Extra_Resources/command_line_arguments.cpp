#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
    cout<<"Command line arguments provided:"<<argc<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"CMD_ARG["<<i<<"]:"<<argv[i]<<endl;
    }
    return 0;
}