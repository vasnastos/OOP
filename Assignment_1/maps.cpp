#include <iostream>
#include <map>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    map <int,char> amap;//unorder
    for(int i=0;i<=10;i++)
    {
        amap.insert(std::make_pair(i,'a'+i));
    }
    cout<<"Map size:"<<amap.size();
    cout<<"Map elements"<<std::endl;
    cout<<(amap.find(2)!=amap.end()?"Key 2 exists in map":"Key 2 exists in map")<<endl<<endl;
    cout<<"***************************"<<std::endl;
    for(auto &x:amap)
    {
        cout<<x.first<<":"<<x.second<<std::endl;
    }
    return EXIT_SUCCESS;
}