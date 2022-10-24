#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


void print_shopping_list(list <string> &sl)
{
    cout<<"=== Shopping list ==="<<endl;
    for(auto itr=sl.begin();itr!=sl.end();itr++)
    {
        cout<<"* "<<*itr<<endl;
    }
    cout<<endl;
}


int main()
{
    cout<<"Checkpoint 1"<<endl;
    list <string> shopping_list;
    print_shopping_list(shopping_list);

    cout<<"Checkpoint 2"<<endl;
    for(auto &x:{"eggs", "milk", "sugar", "chocolate","flour"})
    {
        shopping_list.push_back(x);
    }

    cout<<"Checkpoint 3"<<endl;
    shopping_list.pop_back();
    print_shopping_list(shopping_list);


    cout<<"Checkpoint 4"<<endl;
    shopping_list.push_back("coffee");
    print_shopping_list(shopping_list);

    cout<<"Checkpoint 5"<<endl;
    auto itr=find(shopping_list.begin(),shopping_list.end(),"sugar");
    *itr="honey";
    print_shopping_list(shopping_list);

    cout<<"Checkpoint 6"<<endl;
    shopping_list.erase(find(shopping_list.begin(),shopping_list.end(),"milk"));
    print_shopping_list(shopping_list);

    cout<<"Checkpoint 7"<<endl;
    shopping_list.sort();
    print_shopping_list(shopping_list);

    return EXIT_SUCCESS;
}