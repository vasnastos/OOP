#include <iostream>

using namespace std;

void fun(int avalue)
{
    cout<<avalue<<endl;
}

void fun(double avalue)
{
  cout<<avalue<<endl;
}

void fun(int avalue,double bvalue)
{
    cout<<"{"<<avalue<<","<<bvalue<<"}"<<endl;
}

class A
{
    public:
        // A() {}
        void fun(int avalue)
        {
            cout<<this<<"->"<<avalue<<endl;
        }

        void fun(double avalue)
        {
        cout<<this<<"->"<<avalue<<endl;
        }

        void fun(int avalue,double bvalue)
        {
            cout<<this<<"->"<<"{"<<avalue<<","<<bvalue<<"}"<<endl;
        }       
};


int main()
{
    cout<<"Export values by functions"<<endl;
    fun(4);
    fun(4.5);
    fun(4,4.5);
    cout<<"=============================="<<endl<<endl;

    cout<<"Export values by methods"<<endl;
    A a;
    a.fun(4);
    a.fun(4.5);
    a.fun(4,4.5);
    cout<<"=============================="<<endl<<endl;
    return EXIT_SUCCESS;
}