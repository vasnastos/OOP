#include <iostream>
#include <vector>

using namespace std;

template <class T>int count_if(vector <T> &v,T elem)
{
    int times=0;
    for(auto &x:v)
    {
        if(x==elem)
        {
            times++;
        }
    }
    return times;
}

struct point
{
    int x,y;
    point(int x_,int y_):x(x_),y(y_) {}
    bool operator==(const point &p)const 
    {
        return p.x==this->x && this->y==p.y;
    }
};

int main()
{
    vector <int> v1{1,12,4,5,7,4,8,4,4,12,19,3,4};
    vector <double> v2{2.1,3.1,5.6,3.1,2.7,8.9,34,35,2.1,3.8,2.1,2.1};
    vector <point> v3{{1,3},{2,5},{5,6},{1,3}};
    cout<<"Number 4 found "<<count_if(v1,4)<<" times in vector"<<endl;
    cout<<"Number 2.1 found "<<count_if(v2,2.1)<<" times in vector"<<endl;
    cout<<"Point {1,3} found "<<count_if(v3,{1,3})<<" times in vector"<<endl;
    return EXIT_SUCCESS;
}