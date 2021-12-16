#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> vec;
    for(int i=50;i<62;i++)
    {
        vec.push_back(i);
    }

    // Εμφάνιση vector ανά στοιχείο
    cout<<"=== Checkpoint 1 ==="<<endl;
    for(auto &x:vec)
    {
        cout<<x<<endl;
    }

    cout<<endl<<"=== Checkpoint 2 ==="<<endl;
    for(int i=0,t=vec.size();i<t;i++)
    {
        cout<<vec.at(i)<<endl;
    }

    // Εύρεση στοιχείου στο vector
    auto itr=find(vec.begin(),vec.end(),55);
    cout<<"=== Checkpoint 3 ==="<<endl;
    cout<<"=== Element 55 at position:"<<itr-vec.begin()<<endl;

    // Διαγραφή στοιχείου
    cout<<"=== Erase Element ==="<<endl;
    int pos=-1;
    int elem=56;
    for(int i=0;i<vec.size();i++)
    {
        if(vec.at(i)==elem)
        {
            pos=i;
            break;
        }
    }
    if(pos==-1) {cerr<<"Element did not found!!!"<<endl;}
    else  {
        vec.erase(vec.begin()+pos);
        cout<<"Element "<<elem<<" Erased from list"<<endl;
    }

    return EXIT_SUCCESS;
}