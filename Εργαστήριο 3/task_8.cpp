#include <iostream>
#include <cmath>
using namespace std;

double discriminant(double a,double b,double c)
{
    return pow(b,2)-4*a*c;
}

void solve(double a,double b,double c,bool &found,double &x1,double &x2)
{
    auto delta=discriminant(a,b,c);
    if(delta>0)
    {
        found=true;
        x1=(-b+sqrt(delta))/(2*a);
        x2=(-b-sqrt(delta))/(2*a);
    }
    else if(delta==0)
    {
        found=true;
        x1=x2=-b*2*a;
    }
    else{
        found=false;
        x1=INT_MIN;
        x2=INT_MIN;
    }
}

int main()
{
    double a,b,c;
    cout<<"---- Give factors for quadratic ---"<<endl;
    cout<<"Give a factor:";
    cin>>a;
    cout<<"Give b factor:";
    cin>>b;
    cout<<"Give c factor:";
    cin>>c;

    bool found;
    double x1,x2;

    solve(a,b,c,found,x1,x2);
    if(found)
    {
        cout<<"x1:"<<x1<<endl;
        cout<<"x2:"<<x2<<endl;
    }
    else
    {
        cout<<"x1, x2 can not be calculated"<<endl;
    }
    return 0;
}
