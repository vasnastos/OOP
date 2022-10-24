#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    vector<int> vec;
    vector<int> vec2;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
        vec2.push_back(i);
    }

    int j = 0;
    cout << "Before shuffle" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "vec[" << j << "] = " << vec.at(j) << "  vec2[" << j << "] = " << vec2.at(j) << endl;
    }

    int i = 0;

/*
    random_shuffle(vec.begin(), vec.end());
    cout << "After random_shuffle()" << endl;
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << "vec2[" << i << "] = " << *it << endl;
        i++;
    }
*/

    i = 0;
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vec2.begin(), vec2.end(), std::default_random_engine(seed));
    cout << "After shuffle()" << endl;
    for (auto it = vec2.begin(); it != vec2.end(); ++it)
    {
        cout << "vec2[" << i << "] = " << *it << endl;
        i++;
    }
}