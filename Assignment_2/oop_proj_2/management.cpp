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
	string id,name;
	int semester, credits;
	cout << "Δώσε AM φοιτητή:";
	cin >> id;
	cout << "Δώσε Όνομα φοιτητή:";
	cin.ignore();
	getline(cin,name);
	cout << "Δώσε Εξάμηνο φοιτητή:";
	cin >> semester;
	cout << "Δώσε Δ. Μονάδες φοιτητή:";
	cin >> credits;
	this->students.push_back(Student(id, name, semester, credits));
}