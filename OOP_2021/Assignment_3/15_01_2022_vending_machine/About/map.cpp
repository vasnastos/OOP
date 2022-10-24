#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <int,double> amap{
        {1,0.1},
        {2,0.2},
        {3,0.3},
        {4,0.4},
        {5,0.5}
    };
    
    map <string,string> phone_list;
    phone_list["Vasilis"]="1234567890";
    phone_list["Christos"]="2345678901";
    for(auto &record:phone_list)
    {
        cout<<record.first<<" "<<record.second<<endl;
    }

    // for(auto &x:amap)
    // {
    //     cout<<"Element==>"<<x.first<<" "<<x.second<<endl;
    // }

    // cout<<endl;
    // amap[6]=0.6;
    // for(auto &x:amap)
    // {
    //     cout<<"Element==>"<<x.first<<" "<<x.second<<endl;
    // }
    // return EXIT_SUCCESS;
}