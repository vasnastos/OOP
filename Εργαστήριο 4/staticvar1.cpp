#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Point
{
    double x,y;
    public:
        Point(double _x,double _y):x(_x),y(_y) {}
        void display()
        {
            cout<<"("<<this->x<<","<<this->y<<")"<<endl;
        }
        friend double distance(const Point &p1,const Point &p2)
        {
            return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)); 
        }
};

int main()
{
    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    uniform_real_distribution <double> rand_(1,60);
    int option;
    Point *p1,*p2;
    while(true)
    {
        cout<<"Create points(1|Yes,0|No):";
        cin>>option;
        if(option==1)
        {
            p1=new Point(rand_(mt),rand_(mt));
            p2=new Point(rand_(mt),rand_(mt));
            p1->display();
            p2->display();
            cout<<"Distance:"<<distance(*p1,*p2)<<endl;
            delete p1;
            delete p2;
        }
        else if(option==0)
        {
            break;
        }
    }
    return 0;
}