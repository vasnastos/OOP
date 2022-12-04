#include <iostream>
using namespace std;

constexpr int PI=3.1415;

void circle(double radius,double &area,double &perimeter)
{
    area=PI*radius*radius;
    perimeter=2*PI*radius;
}

int main()
{
    double radius,area,perimeter;
    cout<<"Give circle radius:";
    cin>>radius;
    circle(radius,area,perimeter);
    cout<<"Circle area:"<<area<<endl;
    cout<<"Circle perimeter:"<<perimeter<<endl;
    return 0;
}