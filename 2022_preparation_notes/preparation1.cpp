#include <iostream>
#include <cstdlib>
#include <vector>
#define THRESHOLD 200
using namespace std;

// calculate min,max, mean , std from a vector with 50 random numbers
void statistics(vector <double> &v,double &minv,double &maxv,double &meanv,double &stdv)
{
    minv=v[0];
    maxv=v[0];
    meanv=v[0];
    stdv=0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]<minv)
        {
            minv=v[i];
        }
        else if(v[i]>maxv)
        {
            maxv=v[i];
        }
        meanv+=v[0];
    }
    meanv/=v.size();

    for(auto &x:v)
    {
        stdv=pow(x-meanv,2);    
    }
    stdv=sqrt(stdv/v.size());
}

int main()
{
    srand(123456);
    vector <double> samples;
    for(int i=0;i<50;i++)
    {
        samples.push_back(rand()/(THRESHOLD+1));   
    }

    double max_element,min_element,mean_value,standard_deviation;

    cout<<"=== Statistics ==="<<endl;
    cout<<"Max Element:"<<max_element<<endl;
    cout<<"Min Element:"<<min_element<<endl;
    cout<<"Mean Value:"<<mean_value<<endl;
    cout<<"Standard Deviation:"<<standard_deviation<<endl;
    return 0;
}
