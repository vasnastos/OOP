#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    vector <int> numbers;
    for(int i=0;i<100;i++)
    {
        numbers.emplace_back(i);
    }
    std::shuffle(numbers.begin(),numbers.end(),std::default_random_engine{});
    
    // Διαγραφή αριθμού 56
    numbers.erase(find(numbers.begin(),numbers.end(),56));

    // Εμφάνιση στοιχείων του διανύσματος-->1ος Τρόπος
    cout<<"SHOW-->(1)"<<endl;
    for(auto &num:numbers)
    {
        cout<<num<<endl;
    }
    
    // Εμφάνιση στοιχείων διανύσματος-->2ος Τρόπος
    cout<<endl<<"SHOW-->(2)"<<endl;
    for(int i=0;i<numbers.size();i++)
    {
        cout<<numbers.at(i)<<endl;
    }

    cout<<endl<<"SHOW-->(3)"<<endl;
    // Εμφάνιση στοιχείων διανύσματος-->3oς Τρόπος
    for(auto itr=numbers.begin();itr!=numbers.end();itr++)
    {
        cout<<*itr<<endl;
    }

    //Μέτρηση αριθμών που διαιρούνται με το τρία
    cout<<"Divide by 3-:"<<count_if(numbers.begin(),numbers.end(),[](int &a) {return a%3==0;})<<endl;

    // Εμφάνιση όλων των αριθμών 
    cout<<endl;
    for_each(numbers.begin(),numbers.end(),[](int &num) {cout<<num<<endl;});

    // Διαγραφή στοιχείων που διαιρούνται με το τρια
    auto itr=remove_if(numbers.begin(),numbers.end(),[](const int &a) {return a%3==0;});
    numbers.erase(itr,numbers.end());
    cout<<endl;
    for_each(numbers.begin(),numbers.end(),[](int &num) {cout<<num<<endl;});

}