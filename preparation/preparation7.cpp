#include <iostream>
#include <vector>
using namespace std;

template <class T> T covariance(vector <T> &v1,vector <T> &v2)
{
    double cv=0;
    double v1_mean=0.0,v2_mean=0.0;
    for(int i=0,t=v1.size();i<t;i++)
    {
        v1_mean+=v1[i];
        v2_mean+=v2[i];
    }
    v1_mean/=v1.size();
    v2_mean/=v2.size();

    for(int i=0,t=v1.size();i<t;i++)
    {
        
    }
    return cv;
}

int main()
{

}