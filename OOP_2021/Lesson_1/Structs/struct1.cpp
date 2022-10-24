#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct person
{
    int age;
    std::string id;
    std::string citizenship;
    std::string mail;
    person(int a,std::string i,std::string c,std::string m):age(a),id(i),citizenship(c),mail(m)
    {
    }
    std::string toString()
    {
        return "Age:"+std::to_string(this->age)+"\nId:"+this->id+"\nCitizenship:"+this->citizenship+"\nMail:"+this->mail;
    }
};

int main()
{
    std::vector <person> persons;
    std::fstream fs("person.txt",std::ios::in);
    std::string line,word;
    while(std::getline(fs,line))
    {
        std::vector <std::string> data;
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
            data.emplace_back(word);
        }
        persons.emplace_back(person(std::stoi(data[0]),data[1],data[2],data[3]));
    }
    fs.close();
    for(auto &person:persons)
    {
        std::cout<<person.toString()<<std::endl;
    }
    return 0;
}