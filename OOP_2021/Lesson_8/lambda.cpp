#include <iostream>

using namespace std;

int main()
{
    auto a=[](int a1,int a2){
        return a1+a2;
    };

    auto b=[](int k1,int k2,int k3)
    {
        return (k1,k2+k3)/3.0;
    };

    cout<<a(12,14)<<endl;
    cout<<b(14,56,15)<<endl;
    return EXIT_SUCCESS;
}