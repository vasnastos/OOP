#include <wx/wx.h>

class Frame :public wxFrame
{
private:
	wxButton* b1;
public:
	Frame() :wxFrame(nullptr, wxID_ANY, wxT("TEST"), wxDefaultPosition, wxSize(500, 500))
	{
		this->b1 = new wxButton(this, wxID_ANY, wxT("ADD"), wxDefaultPosition, wxSize(80, 20));
		wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
		sizer->Add(this->b1);
		this->SetSizer(sizer);
	}
};

class App :public wxApp
{
public:
	bool OnInit()
	{
		Frame* f = new Frame;
		f->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(App);