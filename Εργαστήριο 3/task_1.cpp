#include <iostream>
using namespace std;

int main()
{
    int *int_ptr=new int;
    double *double_ptr=new double;
    char *char_ptr=new char;

    *int_ptr=45;
    *double_ptr=54.21;
    *char_ptr='a';

    cout<<int_ptr<<"\t"<<*int_ptr<<endl;
    cout<<double_ptr<<"\t"<<*double_ptr<<endl;
    cout<<char_ptr<<"\t"<<*char_ptr<<endl;

    delete int_ptr;
    delete double_ptr;
    delete char_ptr;
    return 0;
}