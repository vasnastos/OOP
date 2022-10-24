#include "window.hpp"
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>


std::string get_date_time()
{
    auto t=std::time(nullptr);
    auto tm=*std::localtime(&t);
    std::ostringstream oss;
    oss<<std::put_time(&tm,"%d-%m-%Y %H-%M-%S");
    return oss.str();
}

window::window():wxFrame(nullptr,wxID_ANY,"ComboBox Example",wxDefaultPosition,wxSize(600,600))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->sizer->AddSpacer(40);
    wxFont combofont(12,wxFONTFAMILY_ROMAN,wxNORMAL,wxBOLD);
    wxPanel *panel=new wxPanel(this,wxID_ANY);
     this->combo=new wxComboBox(panel,wxID_ANY,"",wxDefaultPosition,wxSize(120,20));
    this->combo->SetFont(combofont);
    std::vector <std::string> days={"Monday","Tuesday","Wednesday","Thursday","Friday"};
    for(auto &x:days)
    {
        this->combo->Append(x);
    }
    this->button=new wxButton(panel,wxID_ANY,wxT("DISPLAY"),wxDefaultPosition,wxSize(100,20));
    this->ctrl=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(500,500),wxTE_MULTILINE|wxTE_READONLY);
    
    this->button->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::show_combo,this);
    this->combo->Bind(wxEVT_COMBOBOX,&window::display_text_ctrl,this);

    // Panel
    wxBoxSizer *psizer=new wxBoxSizer(wxHORIZONTAL);
    psizer->AddSpacer(20);
    psizer->Add(this->combo,0,wxALIGN_CENTER);
    psizer->AddSpacer(40);
    psizer->Add(this->button,0,wxALIGN_CENTER);
    psizer->AddSpacer(20);
    panel->SetSizer(psizer);
    this->sizer->Add(panel,0,wxALIGN_CENTER);

    this->sizer->AddSpacer(40);
    this->sizer->Add(this->ctrl,0,wxALIGN_CENTER);
    this->SetSizer(this->sizer);
    this->Centre();
}

window::~window() {}

void window::show_combo(wxCommandEvent &event)
{
    auto value=this->combo->GetStringSelection();
    wxMessageBox("Value Selected:"+value,"ComboBox Value",wxICON_INFORMATION);
}

void window::display_text_ctrl(wxCommandEvent &event)
{
    auto previous_val=std::string(this->ctrl->GetValue());
    std::string new_addition=previous_val+"\n"+get_date_time()+"->"+std::string(this->combo->GetStringSelection());
    this->ctrl->SetValue(new_addition);
}

bool App::OnInit()
{
    window *w=new window;
    w->Show(true);
    return true;
};