#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ostream>
#include <cstring>
#include <iterator>

int main()
{
    std::string s;
    std::cout<<"Give a string:";
    // std::cin>>s;
    std::getline(std::cin,s);
    std::cout<<"Word length:"<<s.length()<<std::endl;
    std::cout<<"Show char by char::"<<std::endl;
    for(auto &c:s)
    {
        std::cout<<"Character:"<<c<<std::endl;
    }
    std::string s_string="department of informatics and telecommunications";
    // Split method 1
    std::cout<<"Split method 1"<<std::endl;
    std::cout<<"=================================="<<std::endl;
    std::vector <std::string> data;
    std::stringstream ss(s_string);
    std::string word;
    while(std::getline(ss,word,' '))
    {
        data.emplace_back(word);
    }
    std::ostream_iterator <std::string> out(std::cout,"\n");
    std::cout<<"Distinct words at string s_string("<<s_string<<"):"<<std::endl; 
    std::copy(data.begin(),data.end(),out);
    std::cout<<std::endl;

    // Split method 2
    std::cout<<"Split method  2"<<std::endl;
    std::cout<<"===================================="<<std::endl;
    const int size=s_string.length();
    char word_preference[size];
    int i=0;
    for(auto &c:s_string)
    {
        word_preference[i]=c;
        i++;
    }
    char* token=strtok(word_preference," ");
    while(token!=NULL)
    {
        std::cout<<std::string(token)<<std::endl;
        token=strtok(NULL," ");
    }
    std::cout<<std::endl;

    // Split method 3
    std::cout<<"Split method 3"<<std::endl;
    std::cout<<"=================================="<<std::endl;
    std::string delimeter=" ";
    size_t pos=0;
    std::string tokenpp;
    std::string temp_word_view=s_string;
    while(pos!=std::string::npos)
    {
        pos=temp_word_view.find(delimeter);
        tokenpp=temp_word_view.substr(0,pos);
        std::cout<<tokenpp<<std::endl;
        temp_word_view.erase(0,pos+delimeter.length());
    }
    return 0;
}