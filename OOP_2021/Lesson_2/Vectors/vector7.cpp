#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < 5; i++)
    {
        vec1.insert(vec1.begin() + i, i * 3);
        vec2.push_back(i * 4);
    }

    //iterator
    vector<int>::iterator itr;
    int i = 0;
    cout << "Print contents with \"manual\" iterator" << endl;
    for (itr = vec1.begin(); itr != vec1.end(); itr++)
    {
        cout << "vec1[" << i << "] = " << *itr << endl;
        i++;
    }

    i = 0;
    cout << "Print contents with \"auto\" iterator" << endl;
    for (auto itr2 = vec2.begin(); itr2 < vec2.end(); itr2++)
    {
        cout << "vec2[" << i << "] = " << *itr2 << endl;
        i++;
    }

    i = 0;
    cout << "Print contents of vec2 with advanced for" << endl;
    for (auto &itr2 : vec2)
    {
        cout << "vec2[" << i << "] = " << itr2 << endl;
        i++;
    }

    i = 0;
    cout << "Print contents with \"double\" iterators" << endl;
    for (auto it = vec1.begin(), it2 = vec2.begin(); it < vec1.end(), it2 < vec2.end(); it++, it2++)
    {
        cout << "vec1[" << i << "] = " << *it << "   vec2[" << i << "] = " << *it2 << endl;
        i++;
    }

    vec1.swap(vec2);
    cout << "Print contents of vectors after swap" << endl;
    for (auto it = vec1.begin(), it2 = vec2.begin(); it < vec1.end(), it2 < vec2.end(); it++, it2++)
    {
        cout << "vec1[" << i << "] = " << *it << "   vec2[" << i << "] = " << *it2 << endl;
        i++;
    }
}