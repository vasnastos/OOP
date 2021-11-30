#include "window.hpp"

enum
{
    BUTTON_ADD=1000,
    BUTTON_DELETE=1001
};


window::window(std::string title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(400,450))
{
    auto size=this->GetSize();
    wxBoxSizer *boxsizer=new wxBoxSizer(wxVERTICAL);
    // Στοίχιση στο panel
    // wxPanel *panel=new wxPanel(this,-1);
    // wxBoxSizer *panelsizer=new wxBoxSizer(wxHORIZONTAL);
    auto panel1=new wxPanel(this,wxID_ANY);
    auto panel2=new wxPanel(this,wxID_ANY);
    auto stext1=new wxStaticText(panel1,wxID_ANY,wxT("ΕΙΣΑΓΩΓΗ ΔΕΔΟΜΕΝΩΝ"),wxDefaultPosition,wxSize(180,20));
    auto stext2=new wxStaticText(panel2,wxID_ANY,wxT("ΔΙΑΓΡΑΦΗ ΔΕΔΟΜΕΝΩΝ"),wxDefaultPosition,wxSize(180,20));
    wxColor col("#040d45");
    stext1->SetForegroundColour(col);
    stext2->SetForegroundColour(col);
    this->button1=new wxButton(panel1,BUTTON_ADD,wxT("ΕΙΣΑΓΩΓΗ"),wxDefaultPosition,wxSize(80,20));
    this->button2=new wxButton(panel2,BUTTON_DELETE,wxT("ΔΙΑΓΡΑΦΗ"),wxDefaultPosition,wxSize(80,20));
    this->button1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::add,this);
    this->button2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::delete_id,this);
    auto panel1sizer=new wxBoxSizer(wxHORIZONTAL);
    auto panel2sizer=new wxBoxSizer(wxHORIZONTAL);
    panel1sizer->Add(stext1,0,wxALIGN_CENTER);
    panel1sizer->AddSpacer(20);
    panel1sizer->Add(this->button1,1,wxALIGN_CENTER);
    panel1->SetSizer(panel1sizer);
    panel2sizer->Add(stext2);
    panel2sizer->AddSpacer(20);
    panel2sizer->Add(this->button2,1,wxALIGN_CENTER);
    panel2->SetSizer(panel2sizer);

    boxsizer->AddSpacer(15);
    boxsizer->Add(panel1,0,wxALIGN_CENTER);
    boxsizer->AddSpacer(20);
    boxsizer->Add(panel2,0,wxALIGN_CENTER);
    boxsizer->AddSpacer(20);
    this->ctrl=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(size.GetWidth()*0.5,size.GetHeight()*0.34),wxTE_MULTILINE);
    boxsizer->Add(this->ctrl,0,wxALIGN_CENTER);
    this->SetSizer(boxsizer);
    this->Centre();
}


void window::add(wxCommandEvent &event)
{
    // std::cout<<"Event add command enabled"<<std::endl;
    std::string previous_value=std::string(this->ctrl->GetValue());
    this->ctrl->SetValue(previous_value+"\nEvent add command enabled");
}

void window::delete_id(wxCommandEvent &event)
{
   std::string previous_value=std::string(this->ctrl->GetValue());
   this->ctrl->SetValue(previous_value+"\nEvent delete command enabled");
}

bool App::OnInit()
{
    window *w=new window("ΠΑΡΑΔΕΙΓΜΑ ΣΤΟΙΒΑΣ");
    w->Show();
    return true;
}
