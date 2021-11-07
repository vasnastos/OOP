#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vector<int> vec2;
    vector<int> v;

    //Εισαγωγή δεδομένων στο τέλος
    cout << "Creation of vectors vec and vec2" << endl;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
        vec2.emplace_back(i * 2);
    }

    //Εμφάνιση στοιχείων
    for (int j = 0; j < 5; j++)
    {
        cout << "\tvec[" << j << "] = " << vec.at(j) << "  vec2[" << j << "] = " << vec2.at(j) << endl;
    }

    cout << endl
         << "vec and vec2, after swap()" << endl;
    vec.swap(vec2);
    for (int j = 0; j < 5; j++)
    {
        cout << "\tvec[" << j << "] = " << vec.at(j) << "  vec2[" << j << "] = " << vec2.at(j) << endl;
    }

    //boolalpha
    //Χρησιμοποιείται σε ροές και μετατρέπει για κάθε ροή το 0 και το 1
    //σε false και true αντίστοιχα
    cout << endl
         << "\"Creation of vector v completed\"" << endl;
    cout << "Is vector v empty ? : " << boolalpha << v.empty() << endl;
    cout << "Size of vector v : " << v.size() << endl;

    v.push_back(22);
    v.push_back(34);
    v.push_back(278);
    cout << "\"Insertion of elements to vector v completed\"" << endl;

    cout << "Size of vector v : " << v.size() << endl;
    cout << "Vector v elements" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }
    cout << "Is vector v empty ? : " << boolalpha << v.empty() << endl
         << endl;

    v.assign(3, 0);
    cout << "Vector after assign() function" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }

    v.insert(v.begin(), 4);
    v.insert(v.end() - 1, 6);
    cout << "Vector after insert() function" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }

    cout << "Size of vector is " << v.size() << endl
         << endl;

    v.pop_back();
    cout << "Size of vector (after pop) is " << v.size() << endl;
    cout << "Vector elements : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }

    auto it = v.begin();
    v.erase(it);
    cout << endl
         << "Size of vector (after erase) is " << v.size() << endl;
    cout << "Vector elements : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }

    v.clear();
    cout << endl
         << "Size of vector (after clear) is " << v.size() << endl;
    cout << "Vector elements : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "\tv[" << i << "] = " << v[i] << endl;
    }
}