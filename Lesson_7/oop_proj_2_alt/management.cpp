#include "management.hpp"


Management::Management()
{
	string filename = "dit_uoi_course.txt";
	fstream fs;
	fs.open(filename, ios::in);
	if (!fs.is_open())
	{
		cerr << "File " << filename << " does not exist" << endl;
		return;
	}
	string line,word;
	bool first_line = true;
	vector <string> data;
	while (getline(fs, line))
	{
		if (first_line)
		{
			first_line = false;
			continue;
		}
		data.clear();
		stringstream ss(line);
		while (getline(ss, word, ','))
		{
			data.push_back(word);
		}
		this->courses.push_back(Course(data[0],stoi(data[1]),data[2],stoi(data[3])));
	}
	fs.close();
}

Management::~Management() {}

void Management::insert_student()
{
	system("cls");
	string id,name;
	int semester, credits;
	cout << "Δώσε AM φοιτητή:";
	cin >> id;
	cin.ignore();
	getline(cin,name);
	cin.ignore();
	cout << "Δώσε Εξάμηνο φοιτητή:";
	cin >> semester;
	cout << "Δώσε Δ. Μονάδες φοιτητή:";
	cin >> credits;
	this->students.push_back(Student(id, name, semester, credits));
	this->display_students();
	system("pause");
}

void Management::load_sample()
{
    std::string line,word;
    std::string status="Students";
    std::fstream fs("students.txt",std::ios::in);
    vector <string> data;
    while(std::getline(fs,line))
    {
        data.clear();
        if(line.length()==0)
        {
            status="Lessons";
            continue;
        }
        if(status=="Students")
        {
            std::stringstream ss(line);
            while(getline(ss,word,','))
            {
                data.push_back(word);
            }
            if(data.size()!=4) continue;
            students.push_back(Student(data[0],data[1],std::stoi(data[2]),std::stoi(data[3])));
        }
        else if(status=="Lessons")
        {
            std::stringstream ss(line);
            while(getline(ss,word,','))
            {
                data.push_back(word);
            }
            auto student_itr=find_if(this->students.begin(),this->students.end(),[&](const Student &s) {return s.get_id()==data[0];});
            for(int i=1,t=data.size();i<t;i++)
            {

                auto itr=find_if(this->courses.begin(),this->courses.end(),[&](const Course &c) {return c.get_code()==data[i];});
                student_itr->add_course(*itr);
            }
        }
    }   
    fs.close();
}


void Management::display_students()
{
	std::cout <<endl <<"=== ΦΟΙΤΗΤΕΣ ===" << std::endl;
	for (auto& student : this->students)
	{
		student.display();
        cout<<endl;
	}
}

vector <Student> Management::get_students()const
{
    return this->students;
}

void Management::display_courses()
{
    vector <Course> courses;
    for(auto &course:this->courses)
    {
        cout<<course<<endl;
    }
}
