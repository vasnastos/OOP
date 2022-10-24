#include "window.hpp"
#include <locale>

void window::panel1()
{
    std::setlocale(LC_ALL,"UTF-8");
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    this->insertbutton=new wxButton(panel,wxID_ANY,wxT("INSERT EMPLOYEE"),wxDefaultPosition,wxSize(150,30));
    this->showbutton=new wxButton(panel,wxID_ANY,wxT("SHOW EMPLOYEES"),wxDefaultPosition,wxSize(150,30));
    this->insertbutton->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::popinsert,this);
    this->showbutton->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::showemps,this);
    wxBoxSizer *psizer=new wxBoxSizer(wxHORIZONTAL);
    psizer->AddSpacer(50);
    psizer->Add(this->insertbutton,0,wxALIGN_CENTER);
    psizer->AddSpacer(50);
    psizer->Add(this->showbutton,0,wxALIGN_CENTER);
    panel->SetSizer(psizer);
    this->sizer->AddSpacer(40);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel2()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    auto size=this->GetSize();
    this->results=new wxTextCtrl(panel,wxID_ANY,"Employees\n================",wxDefaultPosition,wxSize(size.GetWidth()*0.9,size.GetHeight()*0.5),wxTE_MULTILINE|wxTE_READONLY);
    wxBoxSizer *s=new wxBoxSizer(wxHORIZONTAL);
    s->Add(this->results,0,wxALIGN_CENTER);
    panel->SetSizer(s);
    this->sizer->AddSpacer(40);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

window::window():wxFrame(nullptr,wxID_ANY,wxT("EMPLOYEES APP"),wxDefaultPosition,wxSize(600,600))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->wpop=NULL;
    this->panel1();
    this->panel2();
    this->SetSizer(this->sizer);  
}

window::~window() {}

void window::popinsert(wxCommandEvent &event)
{
    delete this->wpop;
    this->wpop=new popupWidget(this);
    auto *btn=(wxWindow*)event.GetEventObject();
    wxPoint pt=btn->ClientToScreen(wxPoint(0,0));
    wxSize sz=btn->GetSize();
    this->wpop->Position(pt,sz);
    this->wpop->Popup();
}

void window::showemps(wxCommandEvent &event)
{
   wxString value=wxT("ΥΠΑΛΛΗΛΟΙ\n=================\n");
    for(int i=0,t=popupWidget::employees.size();i<t;i++)
    {
        wxString name(wxString::FromUTF8(popupWidget::employees.at(i).name));
        wxMessageBox(name,wxT("MHNYMA"),wxICON_INFORMATION);
        value+=wxString(std::to_string(i+1))+"."+name+" "+wxString(std::to_string(popupWidget::employees.at(i).salary))+wxT("\n");
    }
    this->results->SetValue(value);
}

bool App::OnInit()
{
    window *w=new window;
    w->Show(true);
    return true;
}