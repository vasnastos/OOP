#include <iostream>
using namespace std;

class A
{
    private:
        int x;
    public:
        A(int _x):x(_x) {}
        int getX()const {return this->x;}
};

class B:public A
{
    private:
        int y;
    public:
        B(int _x,int _y):A(_x),y(_y) {}
        int getY()const {return this->y;}
};

int main()
{
    B b(13,12);
    cout<<"Y:"<<b.getY()<<" X:"<<b.getX()<<endl; 
    return 0;
}