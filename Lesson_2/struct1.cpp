#include <iostream>

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;

    public:
        Time():hours(0),minutes(0),seconds(0) {}
        Time(int h,int m,int s):hours(h),minutes(m),seconds(s) {}
        void print()
        {
            cout<<(this->hours<10?"0"+to_string(this->hours):to_string(this->hours))<<":"<<(this->minutes<10?"0"+to_string(this->minutes):to_string(this->minutes))<<":"<<(this->seconds<10?"0"+to_string(this->seconds):to_string(this->seconds))<<endl;
        }

        int to_seconds()
        {
            return this->seconds+this->minutes*60+this->hours*3600;
        }

        void to_time(int seconds)
        {
            this->hours=seconds/3600;
            this->minutes=(seconds%3600)/60;
            this->seconds=(seconds%3600)%60;
        }

        void reduce(int seconds_given)
        {
            int time_to_seconds=this->to_seconds();
            if(time_to_seconds<seconds_given)
            {
                cerr<<"Invallid time redution"<<endl;
                return;
            }
            time_to_seconds-=seconds_given;
            this->to_time(time_to_seconds);
        }
};

int main()
{
    Time t1(10,2,6);
    Time t2(12,7,8);
    Time t3(14,34,56);
    const int seconds(7609);
    t1.print();
    t2.print();
    t3.print();
    cout<<endl;

    t1.reduce(seconds);
    t2.reduce(seconds);
    t3.reduce(seconds);

    t1.print();
    t2.print();
    t3.print();
    return EXIT_SUCCESS;
}

