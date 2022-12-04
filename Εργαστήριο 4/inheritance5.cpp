#include <iostream>
using namespace std;

class Data
{
    int size;
    double *dvector;
    public:
        Data():size(0) {}
        ~Data() {delete[] this->dvector;}

        void append(const int &adata)
        {
            if(this->size==0)
            {
                this->dvector=new double[++this->size];
                this->dvector[this->size-1]=adata;
            }
            else{
                double *temporary_data=new double[this->size];
                for(int i=0;i<this->size;i++)
                {
                    temporary_data[i]=this->dvector[i];
                }
                delete[] this->dvector;
                this->dvector=new double[++this->size];
                for(int i=0;i<this->size;i++)
                {
                    this->dvector[i]=temporary_data[i];
                }
                this->dvector[this->size-1]=adata;
                delete[] temporary_data;
            }
        }

        int get_size()const {return this->size;}
        double at(int i)
        {
            if(i>=this->size || i<0)
            {
                cerr<<"The index "<<i<<" you try to access is inaccessable"<<endl;
                return INT_MIN;
            }
            return this->dvector[i];
        }
};

int main(int argc,char **argv)
{

}