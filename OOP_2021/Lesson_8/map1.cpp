// Write a program that defines a map of integers and strings.
// Search for an element by key using the map's .find() member 
// function. If the element is found, delete it.
// Print out the map content

#include <iostream>
#include <map>

using namespace std;

void show(map <int,string> &users)
{
    for(auto &user:users)
    {
        cout<<user.first<<" "<<user.second<<endl;
    }
}

string BR="\n\n";

int main(int argc,char **argv)
{
    map <int,string> users{
        {1001,"user0001"},
        {1002,"user0002"},
        {1003,"user0003"},
        {1004,"user0004"},
        {1005,"user0005"},
        {1006,"user0006"}
    };

    cout<<"Checkpoint 1"<<endl;
    show(users);
    cout<<BR;

    int id=1004;
    int id2=1007;
    auto itr1=users.find(id);
    if(itr1!=users.end())
    {
        users.erase(itr1);
    }
    else
    {
        cout<<"User "<<id<<" not enrolled on the map"<<endl;
    }
    cout<<"Checkpoint 2"<<endl;
    show(users);
    cout<<BR;

    cout<<"Checkpoint 3"<<endl;
    auto itr2=users.find(id2);
    if(itr2!=users.end())
    {
        users.erase(itr1);
    }
    else
    {
        cout<<"User "<<id2<<" not enrolled on the map"<<endl;
    }
    return EXIT_SUCCESS;
}