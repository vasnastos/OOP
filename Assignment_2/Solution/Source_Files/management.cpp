#include "management.hpp"
#include <algorithm>


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

// getters-->Σημαντικοί για κατασκευή παραθύρου
vector <Course> Management::get_courses()const
{
	return this->courses;
}

vector <Student> Management::get_students()const
{
	return this->students;
}

void Management::insert_student()
{
	system("cls");
	string id,name;
	cout << "=== ΕΙΣΑΓΩΓΗ ΦΟΙΤΗΤΗ ===" << endl;
	int semester, credits;
	cout << "Δώσε AM φοιτητή:";
	cin >> id;
	bool student_exists;
	while (1)
	{
		student_exists = false;
		for (auto student : this->students)
		{
			if (student.get_id() == id)
			{
				student_exists = true;
				break;
			}
		}
		if (!student_exists)
		{
			break;
		}
		cout << "Το ΑΜ:" << id << " υπάρχει ήδη στο σύστημα!Εισάγεται ένα έγκυρο ΑΜ:";
		cin >> id;
	}
	
	cin.ignore();
	cout << "Δώσε όνομα φοιτητή:";
	getline(cin, name);
	cout << "Δώσε Εξάμηνο φοιτητή:";
	cin >> semester;
	cout << "Δώσε Δ. Μονάδες φοιτητή:";
	cin >> credits;
	this->students.push_back(Student(id, name, semester, credits));
	this->display_students();
	system("pause");
	
}

void Management::update_student()
{
	auto student_index = this->select_student();
	if (student_index == -1)
	{
		return;
	}
	string am, name;
	int semester, credits;
	cout << "=== Ενημέρωση στοιχείων φοιτητή ===" << endl;
	cout << "Εισαγωγή νέου Αριθμού Μητρώου[- για παράλειψη]:";
	cin >> am;
	cin.ignore();
	cout << "Εισαγωγή νέου ονόματος[- για παράλειψη]:";
	getline(cin,name);
	cout << "Εισαγωγή νέου εξαμήνου[<=0 για παράλειψη]:";
	cin >> semester;
	cout << "Εισαγωγή νέου αριθμού διδακτικών μονάδων[<=0 για παράλειψη]:";
	cin >> credits;
	if (am != "-")
	{
		this->students[student_index].set_id(am);
	}
	if (name != "-")
	{
		this->students[student_index].set_name(name);
	}
	if (semester > 0)
	{
		this->students[student_index].set_semester(semester);
	}
	if (credits > 0)
	{
		this->students[student_index].set_credits(credits);
	}
	string erasechoice;
	int coursei;
	while (true)
	{
		cout << "Θέλετε να διαγράψετε κάποιο μάθημα από τον φοιτητή[" << this->students[student_index].get_id() << "](YES-Y/NO-N):";
		cin >> erasechoice;
		for_each(erasechoice.begin(), erasechoice.end(), [](char& k) {k = toupper(k); });
		if (erasechoice == "NO" || erasechoice=="N")
		{
			break;
		}
		else if (erasechoice == "YES" || erasechoice=="Y")
		{
			vector <Course> student_courses = this->students[student_index].get_courses();
			if (student_courses.empty()) return;
			cout << "=== Διαγραφή μαθήματος ===" << endl;
			for (int i = 0, t = student_courses.size(); i < t; i++)
			{
				cout << i << "." << student_courses[i] << endl;
			}
			cout << "Διάλεξε μάθημα:";
			cin >> coursei;
			while (coursei < 0 || coursei >= student_courses.size())
			{
				cout << "Επέλεξε μία από τις διαθέσιμες επιλογές[0-" << student_courses.size() - 1 << "]:";
				cin >> coursei;
			}
			cout << "Διαγράφηκε το μάθημα->" << student_courses[coursei].get_title() << endl;
			this->students[student_index].erase_course(coursei);
			system("pause");
		}
		else
		{
			cout << "Μη έγκυρη επιλογή!Επιλέξτε μία από τις διαθέσιμες επιλογές[YES-Y/NO-N]:";
			cin >> erasechoice;
		}
	}
	this->display_students();
	system("pause");
}

void Management::delete_student()
{
	auto student_index = this->select_student();
	if (student_index == -1)
	{
		return;
	}
	this->students.erase(this->students.begin()+student_index);
	this->display_students();
	system("pause");
}

void Management::enroll_to_lesson()
{
	int student_selected = this->select_student();
	string answer;
	vector <Course> student_available_courses;
	do {
		student_available_courses.clear();
		for (auto& course : this->courses)
		{
			if (this->students[student_selected].get_semester() % 2 == course.get_semester() % 2
				&& this->students[student_selected].get_semester() >= course.get_semester()
				&& this->students[student_selected].get_credits_left() >= course.get_credits()
				&& this->students[student_selected].is_course_valid(course))
			{
				student_available_courses.push_back(course);
			}
		}
		if (student_available_courses.empty()) return;
		int course_choice;
		cout << "=== Επιλογή μαθήματος ====" << endl;
		for (int i = 0; i < student_available_courses.size(); i++)
		{
			cout << i << "." << student_available_courses[i] << endl;
		}
		cout << "Διάλεξε μάθημα:";
		cin >> course_choice;
		while (course_choice < 0 || course_choice >= student_available_courses.size())
		{
			cout << "Μη έγκυρη επιλογή[0-" << student_available_courses.size() - 1 << "]:";
			cin >> course_choice;
		}
		this->students[student_selected].add_course(student_available_courses[course_choice]);
		cout << "Θέλετε να επιλέξετε και άλλο μάθημα για τον φοιτητή " << this->students[student_selected].get_id() << "(YES-Y/NO-N):";
		cin >> answer;
		for_each(answer.begin(), answer.end(), [](char& k) {k = toupper(k); });
		while (answer != "YES" && answer != "NO" && answer!="Y" && answer!="N")
		{
			cout << "Επιλέξτε μία από τις διαθέσιμες επιλογές(YES-Υ/NO-N):";
			cin >> answer;
		}
	} while (answer=="YES" || answer=="Y");
	this->students[student_selected].info();
	system("pause");
}


void Management::display_students()
{
	std::cout << "=== ΦΟΙΤΗΤΕΣ ===" << std::endl;
	for (auto& student : this->students)
	{
		std::cout <<"* " << student << std::endl;
	}
}


int Management::select_student()
{
	system("cls");
	if (this->students.empty())
	{
		return -1;
	}
	int cr;
	cout << "=== Επιλογή φοιτητή ===" << endl;
	for (int i = 0, t = this->students.size(); i < t; i++)
	{
		cout << i << "." << this->students.at(i) << endl;
	}
	cout << "Διάλεξε φοιτητή:";
	cin >> cr;
	while (cr<0 || cr>this->students.size() - 1)
	{
		cout << "Μη έγκυρη είσοδος παρακαλώ επιλέξτε ξάνα μία έγκυρη επιλογή[0-" << this->students.size() << "]:";
		cin >> cr;
	}
	return cr;
}
