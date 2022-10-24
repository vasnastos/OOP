#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>
using namespace std;

class Book
{
    private:
        string title;
        int year;
        double price;
    public:
        Book():title(""),year(-1),price(-1000) {}
        Book(string t,int y,double p):title(t),year(y),price(p) {}
        ~Book() {}
        double get_price()const {return this->price;}
        string get_title()const {return this->title;}
        int get_year()const {return this->year;}
        bool operator<(const Book &b)const 
        {
            return this->price<b.price;
        }
        bool operator>(const Book &b)const 
        {
            return this->price>b.price;
        }
        Book operator=(const Book &b)
        {
            this->title=b.title;
            this->year=b.year;
            this->price=b.price;
            return *this;
        }
        string to_String()const
        {
            return this->title+"-"+to_string(this->year)+"-"+to_string(this->price);
        }
        friend ostream &operator<<(ostream &os,const Book &b)
        {
            return os<<b.title<<","<<b.year<<","<<b.price;
        }
};


void book_stats(vector <Book> &books,Book *max,Book *min,map <int,vector <double>> *avg)
{
    *max=books[0];
    *min=books[0];
    (*avg)[books[0].get_year()].push_back(books[0].get_price());
    for(int i=1;i<books.size();i++)
    {
        if(books[i]>*max)
        {
            *max=books[i];
        }
        if(books[i]<*min)
        {
            *min=books[i];
        }
        (*avg)[books[i].get_year()].push_back(books[i].get_price());
    }
}

int main()
{
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    auto rand_int=uniform_int_distribution<int>(2010,2020);
    auto rand_price=uniform_real_distribution<double>(10,200);
    vector <Book> books;
    for(int i=0;i<20;i++)
    {
        books.emplace_back(Book("Book"+to_string(i+1),rand_int(mt),rand_price(mt)));
    }
    Book max,min;
    map <int,vector <double>> average;
    book_stats(books,&max,&min,&average);
    cout<<"Max Book:["<<max.to_String()<<"]"<<endl;
    cout<<"Min Book:["<<min.to_String()<<"]"<<endl;
    for(auto &ph:average)
    {
        cout<<"Year "<<ph.first<<"->"<<(static_cast<double>(accumulate(ph.second.begin(),ph.second.end(),0,[](int &s,double &val) {return s+val;}))/ph.second.size())<<endl;
    }
    cout<<endl<<"Books"<<endl;
    cout<<"========"<<endl;
    for(auto &book:books)
    {
        cout<<book<<endl;
    }
    return EXIT_SUCCESS;
}