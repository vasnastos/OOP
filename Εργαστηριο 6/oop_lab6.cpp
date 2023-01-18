#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
using namespace std::chrono;

int main()
{
    auto seed=high_resolution_clock::now().time_since_epoch().count();
    // auto seed=1234;
    mt19937 mt(seed);
    vector <string> names;
    vector <double> grades;


    int number_of_students;
    cout<<"Give number of students:";
    cin>>number_of_students;

    uniform_real_distribution <double> rr(0.2,10);
    for(int i=0;i<number_of_students;i++)
    {
        names.push_back("Student"+to_string(i+1));
        grades.push_back(rr(mt));
    }

    // Mean grade
    double mean_grade=0.0;
    for(auto &x:grades)
    {
        mean_grade+=x;
    }
    mean_grade/=grades.size();
    cout<<"Checkpoint 1:Mean Grade:"<<mean_grade<<endl;

    // Median grade
    vector <double> grades_copy(grades);
    sort(grades_copy.begin(),grades_copy.end());
    // sort(grades_copy.begin(),grades_copy.end(),less{});
    cout<<"Checkpoint 2:Median Grade:"<<grades_copy[grades_copy.size()/2]<<endl;


    //Standard deviation
    double std_deviation=0.0;
    for(auto &grade:grades)
    {
        std_deviation+=pow(grade-mean_grade,2);
    }
    cout<<"Checkpoint 3:Standard deviation:"<<std_deviation/grades.size()<<endl;

    // count_grades in intervals;
    // 0 interval[5-8]  1-interval[10]

    // Number of grades in intervals [5-8] and percent of passed students
    vector <string> interval_names{"5-8","8-10"};
    vector <int> intervals;
    intervals.resize(2);
    fill(intervals.begin(),intervals.end(),0);
    /*
        Alternative for fill
        for(auto &x:intervals)
        {
            x=0;
        }
    */

    for(auto &x:grades)
    {
        if(x>=5 && x<8)
        {
            intervals[0]++;
        }
        else if(x>=8 && x<=10)
        {
            intervals[1]++;
        }
    }
    cout<<"Checkpoint 4"<<endl;
    cout<<"================"<<endl;
    for(int i=0,t=interval_names.size();i<t;i++)
    {
        cout<<"Students with grade["<<interval_names[i]<<"]:"<<intervals[i]<<endl;
    }
    cout<<"Percent of passed students:"<<(intervals[0]+intervals[1])*100/grades.size()<<"%"<<endl;
    // cout<<"Percent of passed students:"<<(accumulate(intervals.begin(),intervals.end(),0,[](int &s,const int &cnt) {return s+cnt;}))*100/grades.size()<<"%"<<endl
    return 0;
}