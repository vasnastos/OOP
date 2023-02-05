#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void nearest_class(vector <vector <double>> &samples,vector <double> &test_sample,int &c1,double &min_distance)
{
    double calculated_euclidean_distance;
    min_distance=1e+6;
    c1=-1;
    for(int i=0,s=samples.size();i<s;i++)
    {
        calculated_euclidean_distance=0;
        for(int j=0,size=samples[i].size()-1;j<size;j++)
        {
            calculated_euclidean_distance+=pow(samples[i][j]-test_sample[j],2);
        }
        calculated_euclidean_distance=sqrt(calculated_euclidean_distance);
        if(calculated_euclidean_distance<min_distance)
        {
            c1=i;
            min_distance=calculated_euclidean_distance;
        }
    }
}

int main()
{
    vector <vector <double>> data={{0.12,0.26,0.35,0.55,1},
                                    {0.18,0.37,0.47,0.61,1},
                                    {0.15,0.31,0.43,0.62,1},
                                    {0.19,0.39,0.54,0.65,2},
                                    {0.13,0.26,0.33,0.57,1},
                                    {0.21,0.38,0.52,0.63,2},
                                    {0.17,0.32,0.45,0.60,1},
                                    {0.10,0.23,0.29,0.56,1},
                                    {0.20,0.35,0.50,0.64,2},
                                    {0.16,0.30,0.41,0.59,2}
                                };

    vector <vector <double>> test={
                                    {0.25,0.40,0.45,0.58},
                                    {0.15,0.28,0.38,0.54},
                                    {0.18,0.32,0.41,0.57},
                                    {0.19,0.34,0.44,0.60}
                                };
    
    int correlated_sample_index;
    double eu_distance;
    cout<<"==== Test Data ===="<<endl;
    for(int i=0,t=test.size();i<t;i++)
    {
        nearest_class(data,test.at(i),correlated_sample_index,eu_distance);
        cout<<"[INFO]Test sample:"<<i+1<<"\t"<<"Class:"<<data[correlated_sample_index][data[correlated_sample_index].size()-1]<<"\t\tDistance:"<<eu_distance<<endl;
    }

    return 0;
}

// ==== Test Data ====
// [INFO]Test sample:1     Class:1         Distance:0.0842615
// [INFO]Test sample:2     Class:1         Distance:0.0479583
// [INFO]Test sample:3     Class:2         Distance:0.034641
// [INFO]Test sample:4     Class:1         Distance:0.03