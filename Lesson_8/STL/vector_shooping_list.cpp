#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Item
{
    string name;
    double price;
    public:
        Item(string n,double p):name(n),price(p) {}
        string get_name()const {return this->name;}
        double get_price()const {return this->price;}
        friend ostream &operator<<(ostream &os,const Item &item)
        {
            return os<<"Name:"<<item.name<<"\t"<<"Price:"<<item.price;
        }
};

void display_items(vector <Item> &items)
{
    for(auto &item:items)
    {
        cout<<item<<endl;
    }
}

string BR="\n\n";

int main()
{
    vector <Item> items;
    items.push_back(Item("eggs",2.10));
    items.push_back(Item("milk",0.6));
    items.push_back(Item("sugar",1.3));
    items.push_back(Item("chocolate",2.1));
    cout<<"Checkpoint 1"<<endl;
    display_items(items);
    cout<<BR;
    sort(items.begin(),items.end(),[](const Item &it1,const Item &it2) {return it1.get_price()<it2.get_price();});
    cout<<"Checkpoint 2"<<endl;
    display_items(items);
    cout<<BR;
    auto itr=find_if(items.begin(),items.end(),[&](const Item &it) {return it.get_name()=="sugar";});
    cout<<"Checkpoint 3"<<endl;
    cout<<*itr<<endl;
    cout<<BR;
    items.push_back(Item("honey",9.0));
    items.push_back(Item("milk",0.6));
    items.push_back(Item("eggs",2.1));
    items.push_back(Item("sugar",1.3));
    cout<<"Checkpoint 4"<<endl;
    display_items(items);
    cout<<BR;
    cout<<"Checkpoint 5"<<endl;
    cout<<"Total Cost:"<<accumulate(items.begin(),items.end(),0.0,[&](double s,const Item &it) {return s+it.get_price();});
    return EXIT_SUCCESS;
}