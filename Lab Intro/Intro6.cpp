#include <iostream>
#include <random>   //--> mt19937 random generator
#include <chrono>   //--> for better randomness
#include <iomanip>  //--> to set precision of decimal numbers

using namespace std;

int main()
{
    //creation of random generator 
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_real_distribution<> dist(0, 150);


    
    double distances[5];
    
    for(int i=0;i<5;i++)
    {
        distances[i] = dist(gen);
    }

    cout<<"1D table"<<endl;

    //list representation of table
    /*
    for(int i=0;i<5;i++)
    {
        cout<<setprecision(3)<<"distances["<<i<<"] : "<<distances[i]<<endl;
    } 
    */

    //row representation of table
    for(int i=0;i<5;i++)
    {
        cout<<setprecision(3)<<distances[i]<<" ";
    } 
    cout<<endl<<endl;


    double dists[5][5];

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dists[i][j] = dist(gen);
        }
    }

    cout<<"2D table"<<endl;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<setprecision(3)<<dists[i][j]<<" ";
        }
        cout<<endl;
    }

}