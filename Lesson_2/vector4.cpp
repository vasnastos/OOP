#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector <pair <string,int>> &v)
{
    for(auto &c:v)
    {
        cout<<c.first<<"->"<<c.second<<endl;
    }
}

int main(int argc,char **argv)
{
    vector <pair <string,int>> v{{"Vasilis",6},{"Nikos",3},{"Maria",2},{"Christos",4},{"Alexandros",1},{"Ilias",5}};
    cout<<"Before Sort"<<endl;
    print(v);
    cout<<endl<<"After sort"<<endl;
    sort(v.begin(),v.end(),[](pair <string,int> &p1,pair <string,int> &p2) {return p1.second<p2.second;});
    print(v);
    return EXIT_SUCCESS;
}