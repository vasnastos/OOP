#include "window.hpp"

window::window(std::string title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(400,450))
{
    auto size=this->GetSize();
    wxBoxSizer *boxsizer=new wxBoxSizer(wxVERTICAL);
    // Στοίχιση στο panel
    // wxPanel *panel=new wxPanel(this,-1);
    // wxBoxSizer *panelsizer=new wxBoxSizer(wxHORIZONTAL);
    this->button1=new wxButton(this,wxID_ANY,wxT("ΕΙΣΑΓΩΓΗ"),wxDefaultPosition,wxSize(80,20));
    this->button2=new wxButton(this,wxID_ANY,wxT("ΔΙΑΓΡΑΦΗ"),wxDefaultPosition,wxSize(80,20));
    this->ctrl=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(size.GetWidth()*0.5,size.GetHeight()*0.34),wxTE_MULTILINE);
    boxsizer->Add(this->button1,0,wxALIGN_CENTER);
    boxsizer->AddSpacer(20);
    boxsizer->Add(this->button2,0,wxALIGN_CENTER);
    boxsizer->AddSpacer(20);
    boxsizer->Add(this->ctrl,0,wxALIGN_CENTER);
    this->SetSizer(boxsizer);
    this->Centre();
}

bool App::OnInit()
{
    window *w=new window("ΠΑΡΑΔΕΙΓΜΑ ΣΤΟΙΒΑΣ");
    w->Show();
    return true;
}