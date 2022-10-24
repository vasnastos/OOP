#include <wx/wx.h>
#include <wx/listctrl.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <numeric>

struct  Student
{
	int id;
	std::string name;
	std::vector <double> grades;
	Student(int i, std::string n) :id(i), name(n) {}
	void add_grade(double gr)
	{
		this->grades.push_back(gr);
	}
	double average()
	{
		double s = 0.0;
		for (auto& g : this->grades)
		{
			s += g;
		}
		return s/this->grades.size();
	}
};

class Frame :public wxFrame
{
private:
	wxListCtrl* ctrl;
	std::vector <Student> students;
public:
	Frame() :wxFrame(nullptr, wxID_ANY, wxT("LIST EXAMPLE"), wxDefaultPosition, wxSize(500, 500))
	{
		wxBoxSizer* bx = new wxBoxSizer(wxVERTICAL);
		this->ctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(400, 400), wxLC_REPORT);
		this->ctrl->InsertColumn(0, wxT("Student Name"), wxLIST_FORMAT_CENTER, this->ctrl->GetSize().GetWidth() / 2);
		this->ctrl->InsertColumn(1, wxT("Student id"), wxLIST_FORMAT_CENTER, this->ctrl->GetSize().GetWidth() / 2);
		this->ctrl->SetFont(wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		wxPanel* panel = new wxPanel(this,wxID_ANY);
		wxBoxSizer* ps = new wxBoxSizer(wxHORIZONTAL);
		wxButton* b = new wxButton(panel, wxID_ANY, wxT("Create"), wxDefaultPosition, wxSize(80, 30));
		wxButton* b1 = new wxButton(panel, wxID_ANY, wxT("Show"), wxDefaultPosition, wxSize(80, 30));
		
		b->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&Frame::open,this);
		b1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Frame::showst, this);
		wxBoxSizer* panelsizer = new wxBoxSizer(wxHORIZONTAL);
		panelsizer->Add(b, 0, wxALIGN_CENTER);
		panelsizer->AddSpacer(10);
		panelsizer->Add(b1, 0, wxALIGN_CENTER);
		panelsizer->AddSpacer(10);
		panel->SetSizer(panelsizer);
		bx->Add(panel, 0, wxALIGN_CENTER);
		bx->AddSpacer(20);
		bx->Add(this->ctrl, 0, wxALIGN_CENTER);
		this->SetSizer(bx);
	}

	void open(wxCommandEvent& ev)
	{
		this->students.clear();
		std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		auto size=std::uniform_int_distribution<int>(50, 100);
		auto totallessons = std::uniform_int_distribution<int>(5, 9);
		auto grade = std::uniform_real_distribution<double>(0.1, 10.0);
		const int studentsnum = size(mt);
		for (int i = 0; i < studentsnum; i++)
		{
			Student s(i, "Student_" + std::to_string(i));
			const int ln = totallessons(mt);
			for (int j = 0; j < ln; j++)
			{
				s.add_grade(grade(mt));
			}
			this->students.push_back(s);
		}
		int counter = 0;
		for (auto& student : this->students)
		{
			wxListItem it;
			it.SetAlign(wxLIST_FORMAT_CENTER);
			this->ctrl->InsertItem(counter,it);

			this->ctrl->SetItem(counter, 0, wxString(std::to_string(student.id)));
			this->ctrl->SetItem(counter, 1, wxString(student.name));
			counter++;
		}
	}

	void showst(wxCommandEvent &ev)
	{
		auto item = this->ctrl->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
		auto id = std::stoi(std::string(this->ctrl->GetItemText(item)));
		auto students_itr = std::find_if(this->students.begin(), this->students.end(), [&](const Student& s) {return s.id == id; });
		std::string message = "Student Selected:"+students_itr->name+"\nGrades\n******\n";
		for (auto& gr : students_itr->grades)
		{
			message += "Grade:" + std::to_string(gr) + "\n";
		}
		message += "------\nAverage:" + std::to_string(students_itr->average());
		wxMessageBox( wxString(message), wxT("Show Average"), wxICON_INFORMATION);
	}
};

class App :public wxApp
{
public:
	bool OnInit()wxOVERRIDE
	{
		Frame* f = new Frame;
		f->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP_NO_MAIN(App);
int main(int argc,char **argv)
{
	wxEntry(argc, argv);
}