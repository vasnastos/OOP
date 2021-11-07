#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    map<int, string> mp;

    cout << "Is map empty? : " << boolalpha << mp.empty() << endl
         << endl;

    //Εισαγωγή στοιχείων
    mp.insert(pair<int, string>(23, "vasilis"));
    mp.insert(pair<int, string>(35, "maria"));
    mp.insert(pair<int, string>(10, "sotiris"));
    mp.insert(pair<int, string>(105, "kostas"));
    mp.insert({74, "nikoletta"});
    mp.insert({42, "gewrgia"});
    mp.insert({2, "christos"});
    mp[81] = "nikos";
    mp[237] = "panagiwths";
    //mp[81] = "anna";

    cout << "\"Insertion of elements completed\"" << endl
         << endl;

    cout << "Is map empty? : " << boolalpha << mp.empty() << endl
         << endl;

    cout << "Size of map is : " << mp.size() << endl
         << "\n";

    //Διάτρεξη map
    cout << "Key \tElement" << endl;

    for (auto &itr : mp)
    {
        cout << itr.first << "\t" << itr.second << endl;
    }

    /*
    for(auto itr=mp.begin(); itr!=mp.end(); itr++)
    {
        cout<<itr->first<<"\t"<<itr->second<<endl;
    }
    */

    cout << endl
         << "Key of value 23 is : " << mp[23] << endl;
    cout << "Key of value 81 is : " << mp.at(81) << endl
         << endl;

    cout << "Count of elements with key 81 : " << mp.count(81) << endl;

    mp.erase(81);

    auto it = mp.find(74);
    cout << "\nShow function find()" << endl;
    for (it; it != mp.end(); it++)
    {
        cout << it->first << '\t' << it->second << '\n';
    }
    cout << endl;

    std::map<char, int> foo, bar;

    foo['x'] = 100;
    foo['y'] = 200;

    bar['a'] = 11;
    bar['b'] = 22;
    bar['c'] = 33;

    foo.swap(bar);
    std::cout << "foo contains:\n";
    for (auto it = foo.begin(); it != foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (auto it = bar.begin(); it != bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}