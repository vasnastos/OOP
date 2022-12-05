#include <iostream>
using namespace std;

class A
{
    int x;
    public:
        A(int _x):x(_x) {}
        A(const A &a):x(a.x) {}
        ~A() {}
        int getX() {return this->x;}
};

int main()
{
    A a1(15);
    A a2(a1);
    cout<<&a1<<" x:"<<a1.getX()<<endl;
    cout<<&a2<<" x:"<<a2.getX()<<endl;
    return 0;
}