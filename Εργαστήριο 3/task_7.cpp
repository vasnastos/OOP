#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Point
{
    double x_point;
    double y_point;
    public:
        Point():x_point(0.0),y_point(0.0) {}
        Point(double x_val,double y_val):x_point(x_val),y_point(y_val) {}
        ~Point() {}
        void set_x_point(double xval) {this->x_point=xval;}
        void set_y_point(double yval) {this->y_point=yval;} 

        double get_x_point()const {return this->x_point;}
        double get_y_point()const {return this->y_point;}
        double distance(const Point &point)const
        {
            return sqrt(pow(this->x_point-point.x_point,2)+pow(this->y_point-point.y_point,2));
        }
};

void find_k_neighbors(double *distance_matrix,int size,int kParams)
{
    int *indeces=new int[size];
    double *neighbors_=new double[size];
    
    for(int i=0;i<size;i++)
    {
        indeces[i]=i;
        neighbors_[i]=distance_matrix[i];
    }
    
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size-1;j++)
        {
            if(neighbors_[i]>neighbors_[j])
            {
                double temp=neighbors_[i];
                neighbors_[i]=neighbors_[j];
                neighbors_[j]=temp;

                int temp_i=indeces[i];
                indeces[i]=indeces[j];
                indeces[j]=temp_i;
            }
        }
    }

    for(int i=0;i<kParams;i++)
    {
        cout<<"Neighbor:"<<indeces[i]<<"\tDistance:"<<distance_matrix[indeces[i]]<<endl;
    }
    delete[] indeces;
    delete[] neighbors_;
}

int main()
{
    const int K=5;
    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    uniform_real_distribution <double> random_points(0,60);
    Point *points=new Point[30];
    double **distance_matrix=new double*[30];
    for(int i=0;i<30;i++)
    {
        distance_matrix[i]=new double[30];
    }

    for(int i=0;i<30;i++)
    {
        points[i].set_x_point(random_points(mt));
        points[i].set_y_point(random_points(mt));
        distance_matrix[i][i]=INT32_MAX;
        for(int j=0;j<30;j++)
        {
            if(i==j)
            {
                continue;
            }
            distance_matrix[i][j]=points[i].distance(points[j]);
        }
    }
    
    for(int i=0;i<30;i++)
    {
        cout<<"("<<points[i].get_x_point()<<","<<points[i].get_y_point()<<")"<<endl;
        find_k_neighbors(distance_matrix[i],30,K);
        cout<<endl<<endl;
    }

    for(int i=0;i<30;i++)
    {
        delete[] distance_matrix[i];
    }
    delete[] distance_matrix;
    return EXIT_SUCCESS;
}