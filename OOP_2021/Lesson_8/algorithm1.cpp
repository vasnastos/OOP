#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <ostream>
#include <iterator>

using namespace std;
using namespace std::chrono;

int main()
{
    mt19937 mt(high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> rand_int(0,100);
    vector <int> v;
    for(int i=0;i<15;i++)
    {
        v.push_back(rand_int(mt));
    }
    cout<<"Checkpoint"<<endl;
    cout<<"Board"<<endl;
    ostream_iterator <int> out(cout,"\n");
    copy(v.begin(),v.end(),out);

    sort(v.begin(),v.end());
    cout<<endl<<"Checkpoint 2"<<endl;
    cout<<"Board"<<endl;
    copy(v.begin(),v.end(),out);


    reverse(v.begin(),v.end());
    cout<<endl<<"Checkpoint 3"<<endl;
    cout<<"Board"<<endl;
    copy(v.begin(),v.end(),out);

    cout<<endl<<"Checkpoint 4(even numbers)"<<endl;
    cout<<"Board"<<endl;
    for_each(v.begin(),v.end(),[](const int &k) {if(k%2==0) {cout<<"* "<<k<<endl;}});
    return EXIT_SUCCESS;
}