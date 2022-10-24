#include "popup.hpp"
#ifdef __WIN32__
    #define SYS "WINDOWS"
#elif __linux__
    #define SYS "LINUX"
#elif __APPLE__
    #define SYS "MACOS"
#endif
popupWidget::popupWidget(wxWindow *parent):wxPopupTransientWindow(parent,wxBORDER_NONE|wxPU_CONTAINS_CONTROLS)
{
    wxFont panelFont(11,wxFONTFAMILY_ROMAN,wxNORMAL,wxBOLD);
    this->spanel=new wxScrolledWindow(this,wxID_ANY);
    wxPanel *panel=new wxPanel(this->spanel,wxID_ANY);
    wxPanel *panel1=new wxPanel(this->spanel,wxID_ANY);
    wxPanel *panel2=new wxPanel(this->spanel,wxID_ANY);
    wxPanel *panel3=new wxPanel(this->spanel,wxID_ANY);
    wxPanel *panel4=new wxPanel(this->spanel,wxID_ANY);
    wxBoxSizer *centralboxsizer=new wxBoxSizer(wxVERTICAL);
    
    // Initial Panel
    wxStaticText *intro=new wxStaticText(panel,wxID_ANY,wxT("EMPLOYEES ENTRY FORM"),wxDefaultPosition,wxSize(250,30),wxALIGN_BOTTOM);
    // panel->SetSize(100,100);
    intro->SetForegroundColour(wxColor("#4f0649"));
    intro->SetFont(panelFont);
    wxBoxSizer *psizer=new wxBoxSizer(wxHORIZONTAL);
    psizer->Add(intro,0,wxALIGN_CENTER);
    panel->SetSizer(psizer);
    
    // Panel1
    wxStaticText *st1=new wxStaticText(panel1,wxID_ANY,wxT("EMPLOYEE's ID:"),wxDefaultPosition,wxSize(150,25));
    this->id=new wxTextCtrl(panel1,wxID_ANY,"",wxDefaultPosition,wxSize(130,30));
    wxBoxSizer *bx1=new wxBoxSizer(wxHORIZONTAL);
    st1->SetFont(panelFont);
    bx1->Add(st1,0,wxALIGN_CENTER);
    bx1->AddSpacer(30);
    bx1->Add(this->id,0,wxALIGN_CENTER);
    panel1->SetSizer(bx1);

    // Panel 2
    wxStaticText *st2=new wxStaticText(panel2,wxID_ANY,wxT("EMPLOYEE's NAME:"),wxDefaultPosition,wxSize(150,30));
    this->name=new wxTextCtrl(panel2,wxID_ANY,wxT(""),wxDefaultPosition,wxSize(130,30));
    wxBoxSizer *bx2=new wxBoxSizer(wxHORIZONTAL);
    st2->SetFont(panelFont);
    bx2->Add(st2,0,wxALIGN_CENTER);
    bx2->AddSpacer(30);
    bx2->Add(this->name,0,wxALIGN_CENTER);
    panel2->SetSizer(bx2);

    // Panel3
    wxStaticText *st3=new wxStaticText(panel3,wxID_ANY,wxT("EMPLOYEE's SALARY:"),wxDefaultPosition,wxSize(150,30));
    this->salary=new wxTextCtrl(panel3,wxID_ANY,wxT(""),wxDefaultPosition,wxSize(130,30));
    wxBoxSizer *bx3=new wxBoxSizer(wxHORIZONTAL);
    st3->SetFont(panelFont);
    bx3->Add(st3,0,wxALIGN_CENTER);
    bx3->AddSpacer(30);
    bx3->Add(this->salary,0,wxALIGN_CENTER);
    panel3->SetSizer(bx3);

    // Panel 4
    wxButton *b1=new wxButton(panel4,wxID_ANY,wxT("INSERT"),wxDefaultPosition,wxSize(80,20));
    wxButton *b2=new wxButton(panel4,wxID_ANY,wxT("CLEAR"),wxDefaultPosition,wxSize(80,20));
    b1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&popupWidget::insert,this);
    b2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&popupWidget::clearfields,this);
    wxBoxSizer *bx4=new wxBoxSizer(wxHORIZONTAL);
    bx4->Add(b1,0,wxALIGN_CENTER);
    bx4->AddSpacer(40);
    bx4->Add(b2,0,wxALIGN_CENTER);
    panel4->SetSizer(bx4);

    // // Adding panel to ScrolledWindow
    centralboxsizer->AddSpacer(18);
    centralboxsizer->Add(panel,0,wxALIGN_CENTER);
    centralboxsizer->AddSpacer(36);
    centralboxsizer->Add(panel1,0,wxALIGN_CENTER);
    centralboxsizer->AddSpacer(36);
    centralboxsizer->Add(panel2,0,wxALIGN_CENTER);
    centralboxsizer->AddSpacer(36);
    centralboxsizer->Add(panel3,0,wxALIGN_CENTER);
    centralboxsizer->AddSpacer(36);
    centralboxsizer->Add(panel4,0,wxALIGN_CENTER);
    centralboxsizer->AddSpacer(18);
    this->spanel->SetSizer(centralboxsizer);


    // Set Scrolled Window Size
    this->spanel->SetSize(400,400);
    this->spanel->SetScrollRate(10,10);
    SetClientSize(this->spanel->GetSize());
    // No Scrolling 
    // centralboxsizer->Fit(this->spanel)
}

popupWidget::~popupWidget() {}


void popupWidget::Popup(wxWindow* WXUNUSED(focus))
{
    wxPopupTransientWindow::Popup();
}

void popupWidget::OnDismiss()
{
    wxPopupTransientWindow::OnDismiss();
}

void popupWidget::insert(wxCommandEvent &event)
{
    std::string eid;
    std::string ename;
    double esalary;
    eid=std::string(this->id->GetValue());
    ename=std::string(this->name->GetValue());
    esalary=std::stod(std::string(this->salary->GetValue()));
    popupWidget::employees.emplace_back(employee(eid,ename,esalary));
}

void popupWidget::clearfields(wxCommandEvent &event)
{
    this->id->Clear();
    this->name->Clear();
    this->salary->Clear();
}

bool popupWidget::Show(bool show)
{
    wxPopupTransientWindow::Show(show);
    return show;
}

std::vector <employee>popupWidget::employees=std::vector <employee>();