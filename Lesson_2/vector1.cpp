#include <iostream>
#include <vector>
#include <ostream>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    auto seed=steady_clock::now().time_since_epoch().count();
    vector <int> v{1,2,3,4,5,6,7,8,9};
    cout<<"{";
    std::ostream_iterator <int> output(cout,",");
    copy(v.begin(),v.end(),output);
    cout<<"}"<<endl;
    auto random_engine=default_random_engine(seed);
    shuffle(v.begin(),v.end(),random_engine);
    cout<<"{";
    copy(v.begin(),v.end(),output);
    cout<<"}"<<endl;
    return EXIT_SUCCESS;
}