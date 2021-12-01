#include "window.hpp"
#define WINDOW_ID 20000


window::window():wxFrame(nullptr,WINDOW_ID,"Scroll Window Example",wxDefaultPosition,wxSize(500,500))
{
    auto size=this->GetSize();
    this->sizer=new wxBoxSizer(wxVERTICAL);
    wxStaticText *popupstatic=new wxStaticText(this,wxID_ANY,wxT("POPUP EXAMPLE"),wxDefaultPosition,wxSize(200,30));
    this->button=new wxButton(this,wxID_ANY,"SCROLL_WINDOW",wxDefaultPosition,wxSize(140,20));
    this->button->Bind(wxEVT_BUTTON,&window::SPop,this);
    this->sizer->AddSpacer(30);
    this->sizer->Add(popupstatic,0,wxALIGN_CENTER);
    this->sizer->AddSpacer(30);
    this->sizer->Add(this->button,0,wxALIGN_CENTER);
    this->sizer->AddSpacer(30);
    this->popup=nullptr;
    this->SetSizer(this->sizer);
}

void window::SPop(wxCommandEvent &event)
{
    delete this->popup;
    this->popup=new popupWidget(this);
    wxWindow *btnclicked=(wxWindow*)event.GetEventObject();
    wxPoint pt=btnclicked->ClientToScreen(wxPoint(0,0));
    wxSize sz=btnclicked->GetSize();
    this->popup->Position(pt,sz);
    this->popup->Popup();
}

bool App::OnInit()
{
    window *w=new window();
    w->Show();
    return true;
}
