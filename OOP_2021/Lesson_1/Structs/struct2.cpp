#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

struct Point
{
    int x,y;
    Point(int x_,int y_):x(x_),y(y_) {}
    double distance()const
    {
        return sqrt(pow(this->x,2)+pow(this->y,2));
    }
    void show()
    {
        std::cout<<"X:"<<this->x<<"\tY:"<<this->y<<"\tDistance:"<<this->distance()<<std::endl;
    }
};

bool operator<(const Point &p1,const Point &p2)
{
    return p1.distance()<p2.distance();
}

int main()
{
    std::mt19937 mt_p(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    auto rnum=std::uniform_int_distribution<int>(1,30);
    std::vector <Point> points;
    for(int i=0;i<10;i++)
    {
        points.emplace_back(Point(rnum(mt_p),rnum(mt_p)));
    }
    for(auto &point:points)
    {
        point.show();
    }
    for(int i=0,t=points.size();i<t;i++)
    {
        for(int j=i+1,r=points.size();j<r;j++)
        {
            if(points[j]<points[i])
            {
                Point temp=points[i];
                points[i]=points[j];
                points[j]=temp;
            }
        }
    }
    std::cout<<"========================================="<<std::endl;
    for(auto &point:points)
    {
        point.show();
    }
    return 0;
}