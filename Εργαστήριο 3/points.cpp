#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

class Point
{
    double x_point;
    double y_point;
    public:
        Point() {}
        Point(double x_coordinate,double y_coordinate):x_point(x_coordinate),y_point(y_coordinate) {}
        ~Point() {}
        
        void set_x(double new_x_point) {this->x_point=new_x_point;}
        void set_y(double new_y_point) {this->y_point=new_y_point;}
        double get_x()const {return this->x_point;}
        double get_y()const {return this->y_point;}

        double distance(const Point &point)
        {
            return sqrt(pow(this->x_point-point.x_point,2)+pow(this->y_point-point.y_point,2));
        }

        friend std::ostream &operator<<(std::ostream &os,const Point &point)
        {
            return os<<"X_point:"<<point.x_point<<"\tY_point:"<<point.y_point<<std::endl;
        }
};

void find_neighrest_neighbors(double *neighbors,int size,int kParams)
{
    cout.precision(6);
    int *indeces=new int[size];
    for(int i=0;i<size;i++)
    {
        indeces[i]=i;
    }
    
    // Sort distance table
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size-1;j++)
        {
            if(neighbors[i]>neighbors[j])
            {
                double temp=neighbors[i];
                neighbors[i]=neighbors[j];
                neighbors[j]=temp;

                int temp_index=indeces[i];
                indeces[i]=indeces[j];
                indeces[j]=temp_index;
            }
        }
    }

    // Print neighrest neighbors
    for(int i=0;i<kParams;i++)
    {
        cout<<"Neighbor:"<<indeces[i]<<"\t"<<"Distance:"<<neighbors[i]<<endl;
    }
    delete[] indeces;
}

int main()
{
    mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
    Point *points;
    double *neighbors;
    
    std::uniform_int_distribution <int> random_size(20,100);
    std::uniform_real_distribution <double> random_val(0,20);
    const int size=random_size(mt);
    const int neighrest_neighbors=5;

    points=new Point[size];
    neighbors=new double[size];
    cout.precision(4);
    for(int i=0;i<size;i++)
    {
        points[i].set_x(random_val(mt));
        points[i].set_y(random_val(mt));
        std::cout<<"Point["<<i<<"]:"<<points[i];
    }
    cout<<endl<<endl;

    std::shuffle(points,points+size,std::default_random_engine{});

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j) 
            {
                neighbors[j]=(double)INT_MAX;
                continue; 
            }
            
            neighbors[j]=points[i].distance(points[j]);
        }
        // Find neighrest neighbors
        cout.precision(4);
        std::cout<<points[i];
        find_neighrest_neighbors(neighbors,size,neighrest_neighbors);
        cout<<endl;
    }

    delete[] points;
    delete[] neighbors;
    return 0;
}