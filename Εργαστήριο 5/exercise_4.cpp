#include <iostream>
#include <vector>
using namespace std;

class Document
{
    protected:
        vector <string> authors;
        string date;
    public:
        Document(string a_date):date(a_date) {}
        ~Document() {}
        vector <string> get_authors() {return this->authors;}
        string get_date()const {return this->date;}
        void add_author(string author_name)
        {
            this->authors.emplace_back(author_name);
        }
        virtual string info()=0;
};

class Book:public Document
{
    string title;
    public:
        Book(string a_date,string a_title):Document(a_date),title(a_title) {}
        
        ~Book() {}
        
        string get_title()const {return this->title;}
        
        string info()
        {
            string message="Title:"+this->title+"\nDate:"+this->date+"\n"+"=====\nAuthors:\n";
            for(const auto &author:this->authors)
            {
                message+=author+"\n";
            }
            return message;
        }
};

class Email:public Document
{
    string sender;
    string subject;
    vector <string> recipients;
    public:
        Email(string email_sender,string email_subject,string a_date):sender(email_sender),subject(email_subject),Document(a_date) {}
        ~Email() {}
        string get_sender()const {return this->sender;}
        string get_subject()const {return this->subject;}
        vector <string> get_recipients()const {return this->recipients;}
        void add_recipient(string name) {this->recipients.emplace_back(name);}
        string info()
        {
            string message=Document::info()+"\nRecipients\n========\n";
            for(const auto &recipient:this->recipients)
            {
                message+=recipient;
            }
            return message;
        }
};

int main()
{
    Book b1("book1","1/1/2010");
    Book b2("book2","30/6/2015");
    Email e1("petros","email","1/6/2017");
    b1.add_author("nikos");
    b1.add_author("maria");
    b2.add_author("kostas");
    e1.add_author("petros");
    e1.add_author("kostas");

}