#include <iostream>
// #include <cstdlib>

using namespace std;

int main()
{
    int *a;
    double *b;
    char *c;
    a=new int(19);
    // a=(int *)malloc(sizeof(int));
    // *a=78;
    b=new double(21.7);
    c=new char('a');
    cout<<a<<"->"<<*a<<endl;
    cout<<b<<"->"<<*b<<endl;
    cout<<c<<"->"<<*c<<endl;
    delete a;
    delete b;
    delete c;
    return EXIT_SUCCESS;
}