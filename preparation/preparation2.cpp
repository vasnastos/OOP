#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.1415
#include <cstdlib>
using namespace std;

class Sphere
{
    double radius;
    public:
        Sphere(double r):radius(r) {}
        ~Sphere() {cout<<"~Destructed object:"<<this<<endl;}

        void set_radius(double r) {this->radius=r;}
        double get_radius()const {return this->radius;}

        double get_volume() {return (4.0/3.0)*PI*pow(this->radius,2);}

        friend void show(Sphere &s)
        {   
            cout<<"Sphere radius:"<<s.radius<<endl;
            cout<<"Sphere volume:"<<s.get_volume()<<endl;
        }
};

void statistics(vector <Sphere> &spheres,double *average_radius,double *average_volume)
{
    *(average_radius)=0;
    *(average_volume)=0;
    for(auto &x:spheres)
    {
        *(average_radius)+=x.get_radius();
        *(average_volume)+=x.get_volume();
    }

    *(average_radius)/=spheres.size();
    *(average_volume)/=spheres.size();
}

int main()
{
    {
        Sphere s1(4.5);
        show(s1);
    }

    /*
        Εναλλακτικά
        Sphere *s1=new Sphere(4.5);
        delete s1;
    */

    vector <Sphere> spheres;
    int insertion;
    srand(123456);
    while(true)
    {
        cout<<"Insert sphere(0(no)|1(yes)):";
        cin>>insertion;
        if(insertion==0)
        {
            break;
        }

        spheres.push_back(Sphere(rand()%101));
    }

    double average_radius,average_volume;
    statistics(spheres,&average_radius,&average_volume);
    cout<<"Spheres inserted:"<<spheres.size();
    cout<<"Average radius:"<<average_radius<<endl;
    cout<<"Average volume:"<<average_volume<<endl;
    return 0;
}