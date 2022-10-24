#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
    unordered_map <string,double> vals;
    vals["Vasilis"]=7600.9;
    vals["Ioannis"]=5697.34;
    vals["Maria"]=4569.78;
    for(auto itr=vals.begin();itr!=vals.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    return EXIT_SUCCESS;   
}