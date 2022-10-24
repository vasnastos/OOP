#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <sstream>


struct student
{
    std::string name;
    std::string id;
    std::string mail;
    int semester;
    std::vector <std::tuple <int,std::string,double>> lessons;
    student(std::string n,std::string i,std::string m,int s)
    {
        this->name=n;
        this->id=i;
        this->mail=m;
        this->semester=s;
    }
    void add_lesson(int id,std::string name,double grade)
    {
        auto lesson_pair=std::make_tuple(id,name,grade);
        if(std::find_if(this->lessons.begin(),this->lessons.end(),[&](std::tuple<int,std::string,double> &tp) {return std::get<0>(tp)==std::get<0>(lesson_pair);})==this->lessons.end())
        {
            this->lessons.emplace_back(std::tuple<int,std::string,double>(id,name,grade));
        }
    }

    bool operator==(const student &s)const
    {
        return this->id==s.id;
    }

    void show()
    {
        std::cout<<"Id:"<<this->id<<std::endl;
        std::cout<<"Name:"<<this->name<<std::endl;
        std::cout<<"Semester:"<<this->semester<<std::endl;
        std::cout<<"Mail:"<<this->mail<<std::endl;
        std::cout<<"==================================="<<std::endl;
        double average_grade=0.0;
        for(auto &exam:this->lessons)
        {
            std::cout<<"Id:"<<std::get<0>(exam)<<"  Name:"<<std::get<1>(exam)<<" Grade:"<<std::get<2>(exam)<<std::endl;
            average_grade+=std::get<2>(exam);
        }
        std::cout<<"Average Grade:"<<average_grade/this->lessons.size()<<std::endl;
    }


};

class front_office
{
    private:
        std::vector <student> students;
    public:

        front_office(std::string students_file,std::string lessons_file)
        {
            std::fstream fs(students_file);
            std::string line,word;
            std::vector <std::string> data;
            while(std::getline(fs,line))
            {
                data.clear();
                if(line[0]=='#') continue;
                std::stringstream ss(line);
                while(std::getline(ss,word,','))
                {
                    data.emplace_back(word);
                }
                this->students.emplace_back(student(data[0],data[1],data[2],std::stoi(data[3])));
            }
            fs.close();
            fs=std::fstream(lessons_file);
            while(std::getline(fs,line))
            {
                data.clear();
                if(line[0]=='#') continue;
                std::stringstream ss(line);
                while(std::getline(ss,word,','))
                {
                    data.emplace_back(word);
                }
                if(data.size()!=4) continue;
                int id=std::stoi(data[0]);
                auto itr=std::find_if(this->students.begin(),this->students.end(),[&](std::tuple<int,std::string,double> &rec) {return std::get<0>(rec)==id;});
                int lid=std::stoi(data[2]);
                std::string lname=data[3];
                double grade=std::stod(data[4]);
                itr->add_lesson(lid,lname,grade);
            }
            fs.close();
        }

        student unique_student_register(std::string name)
        {
            std::unique_ptr <int> unq_ptr;
            for(auto &student:this->students)
            {
                
            }
        }
};

int main()
{
    std::unique_ptr <int> prte(new int(12));
    std::unique_ptr <int> p2=std::move(prte);
    std::cout<<"Memory placed at:"<<p2.get()<<std::endl;
    std::cout<<*p2<<std::endl;
    return 0;
}