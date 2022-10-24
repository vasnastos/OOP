#include <iostream>
#include <string>

class date
{
    int day;
    int month;
    int year;
    public:
        date():day(1),month(1),year(2021) {}
        date(int d,int m):day(d),month(m),year(2021) {}
        date(int d,int m,int y):day(d),month(m),year(y) {}

        // getters
        int get_day()const
        {
            return this->day;
        }

        int get_month()const
        {
            return this->month;
        }

        int get_year()
        {
            return this->year;
        }

        int get_year()const
        {
            return this->year;
        }

        virtual std::string desc()const{
            return std::to_string(this->day)+"/"+std::to_string(this->month)+"/"+std::to_string(this->year);
        }
};

class holiday:public date
{
    private:
      std::string name;
    public:
        holiday(std::string n,int d,int m,int y):date(d,m,y),name(n) {}
        std::string desc()const
        {
            return date::desc()+"-->"+this->name;
        }
};

int main()
{
    holiday h("Christmas",25,12,2021);
    std::cout<<h.desc()<<std::endl;
    return EXIT_SUCCESS;
}