#include "interface.hpp"


window::window():wxFrame(nullptr,wxID_ANY,"Styling at window",wxDefaultPosition,wxSize(400,400))
{
    wxBoxSizer *sizer=new wxBoxSizer(wxVERTICAL);
    this->b1=new wxButton(this,wxID_ANY,"Button_1",wxDefaultPosition,wxSize(100,25));
    this->b2=new wxButton(this,wxID_ANY,"Button_2",wxDefaultPosition,wxSize(100,25));
    this->b1->SetForegroundColour(wxColor("#0d065e"));
    this->b2->SetForegroundColour(wxColor("#0d065e"));
    this->b1->SetBackgroundColour(wxColor("#cc4bae"));
    this->b2->SetBackgroundColour(wxColor("#cc4bae"));
    wxFont f=wxFont(14,wxDEFAULT,wxNORMAL,wxBOLD,false);
    this->b1->SetFont(f);
    this->b1->Bind(wxEVT_ENTER_WINDOW,&window::onhover,this);
    this->b1->Bind(wxEVT_LEAVE_WINDOW,&window::onhoverout,this);
    this->b1->Bind(wxEVT_BUTTON,&window::button1event,this);
    this->b2->SetFont(f);
    this->b2->Bind(wxEVT_ENTER_WINDOW,&window::onhover2,this);
    this->b2->Bind(wxEVT_LEAVE_WINDOW,&window::onhoverout2,this);
    this->b2->Bind(wxEVT_BUTTON,&window::button2event,this);
    sizer->AddSpacer(20);
    sizer->Add(this->b1,0,wxALIGN_CENTER);
    sizer->AddSpacer(20);
    sizer->Add(this->b2,0,wxALIGN_CENTER);
    this->SetSizer(sizer);
    this->Centre();
}

window::~window() {}

void window::onhover(wxMouseEvent &event)
{
    this->b1->SetBackgroundColour(wxColor("#b0c8d1"));
    this->b1->SetForegroundColour(wxColour("#41015c"));
    this->SetCursor(wxCursor(wxCURSOR_HAND));
}

void window::onhover2(wxMouseEvent &event)
{
    this->b2->SetBackgroundColour(wxColor("#b0c8d1"));
    this->b2->SetForegroundColour(wxColour("#41015c"));
    this->SetCursor(wxCursor(wxCURSOR_HAND));
}

void window::onhoverout(wxMouseEvent &ev)
{
    this->b1->SetBackgroundColour(wxColor("#cc4bae"));
    this->b1->SetForegroundColour(wxColour("#0d065e"));
    this->SetCursor(wxCursor(wxCURSOR_ARROW));
}

void window::onhoverout2(wxMouseEvent &ev)
{
    this->b2->SetBackgroundColour(wxColor("#cc4bae"));
    this->b2->SetForegroundColour(wxColour("#0d065e"));
    this->SetCursor(wxCursor(wxCURSOR_ARROW));
}

void window::button1event(wxCommandEvent &event)
{
    wxMessageBox("Button 1 Triggered","Button Event",wxICON_INFORMATION);
}

void window::button2event(wxCommandEvent &event)
{
    wxMessageBox("Button 2 Triggered","Button Event",wxICON_INFORMATION);
}

bool App::OnInit() 
{
    auto w=new window();
    w->Show();
    return true;
}
