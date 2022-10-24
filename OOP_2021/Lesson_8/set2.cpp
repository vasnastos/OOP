#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set <int> aset;
    for(int i=0;i<20;i++)
    {
        aset.insert(i);
    }

    cout<<"Set"<<endl;
    for(auto itr=aset.begin();itr!=aset.end();itr++)
    {
        cout<<"* "<<*itr<<endl;
    }
    return EXIT_SUCCESS;
}