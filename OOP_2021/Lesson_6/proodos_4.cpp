#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class A
{
    int x,y;
    public:
        static int count;
        A(int x_,int y_):x(x_),y(y_) {A::count++;}
        A(const A &a):x(a.x),y(a.y) {A::count++;}
        int getx()const {return this->x;}
        int gety()const {return this->y;}

};

int A::count=0;


int main()
{
    srand(time(nullptr));
    const int maxV=20;
    vector <A> v
    {
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV},
        {rand()%maxV,rand()%maxV}
    };
    A a(v.at(0));
    A a1(v.at(1));
    cout<<"Objects created:"<<A::count<<endl;//18
}