#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/textctrl.h>
#include <algorithm>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#pragma execution_character_set("utf-8")

using namespace std;

class Frame :public wxFrame
{
private:
	wxListCtrl* ctrl;
	wxButton* b;
public:
	Frame() :wxFrame(nullptr, wxID_ANY, wxT("ΠΑΡΑΔΕΙΓΜΑ ΧΡΗΣΗΣ ΛΙΣΤΑΣ"), wxDefaultPosition, wxSize(500, 500))
	{
		wxBoxSizer* bx = new wxBoxSizer(wxVERTICAL);
		bx->AddSpacer(15);
		this->ctrl = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(400, 200), wxLC_REPORT);
		this->ctrl->InsertColumn(0, wxT("ΑΡΙΘΜΟΣ"),wxLIST_FORMAT_CENTER,this->ctrl->GetSize().GetWidth());
		this->b = new wxButton(this, wxID_ANY, wxT("DELETE"), wxDefaultPosition, wxSize(70, 30));
		this->b->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Frame::del, this);
		bx->Add(this->ctrl, 0, wxALIGN_CENTER);
		bx->AddSpacer(30);
		bx->Add(this->b, 0, wxALIGN_CENTER);
		this->fill_list();
		this->SetSizer(bx);
	}

	void fill_list()
	{
		const int number = 101;
		srand(time(nullptr));
		for (int i = 0; i < 10; i++)
		{
			wxListItem it;
			it.SetAlign(wxLIST_FORMAT_CENTER);
			this->ctrl->InsertItem(i,it);

			this->ctrl->SetItem(i, 0, wxString(std::to_string(rand() % number)));
		}
	}

	void del(wxCommandEvent& ev)
	{
		auto it=this->ctrl->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
		this->ctrl->DeleteItem(it);
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