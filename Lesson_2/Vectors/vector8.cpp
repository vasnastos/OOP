#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> //sort()

using namespace std;

int main()
{
    vector <pair<string, int>> vec;
    vec.push_back(make_pair("Petros", 23));
    vec.push_back(make_pair("Giwrgos",25));
    vec.push_back(make_pair("Maria", 19));
    vec.push_back(make_pair("Kwstas", 48));
    vec.push_back(make_pair("Nikos", 32));
    vec.push_back(make_pair("Katerina", 56));

    cout<<"Before sort"<<endl;
    for(auto it=0; it!=vec.size(); it++)
    {
        cout<<"vec["<<it<<"] = "<<vec[it].first <<" : " <<vec[it].second<<endl;
    }

    sort(vec.begin(), vec.end(), [](pair<string, int> &p1, pair<string, int> &p2){return p1.second < p2.second;});
    
    cout<<endl<<"After sort"<<endl;
    for(auto it=0; it!=vec.size(); it++)
    {
        cout<<"vec["<<it<<"] = "<<vec[it].first <<" : " <<vec[it].second<<endl;
    }
}