#include "border.hpp"

Border::Border():wxFrame(nullptr,wxID_ANY,"Border Layout",wxDefaultPosition,wxSize(300,300))
{
    auto size=this->GetSize();
    cout<<"Image Created {"<<size.GetWidth()<<","<<size.GetHeight()<<"}"<<endl;
    this->boxsizer=new wxBoxSizer(wxVERTICAL);
    this->panel1=new wxPanel(this,wxID_ANY);
    this->panel2=new wxPanel(this,wxID_ANY);
    wxColor col1,col2;
    col1.Set("#5e1418");
    col2.Set("#1d44c4");
    this->panel1->SetBackgroundColour(col1);
    this->panel2->SetBackgroundColour(col2);
    this->ctrl1=new wxTextCtrl(this->panel1,wxID_ANY,"This is text controller for panel1",wxDefaultPosition,wxSize(size.GetWidth()*0.5,size.GetHeight()*0.04));
    this->ctrl2=new wxTextCtrl(this->panel2,wxID_ANY,"This is text controller for panel2",wxDefaultPosition,wxSize(size.GetWidth()*0.5,size.GetHeight()*0.04));
    this->boxsizer->Add(this->panel1,1,wxALIGN_CENTER);
    this->boxsizer->AddSpacer(20);
    this->boxsizer->Add(this->panel2,1,wxALIGN_CENTER);
    wxBoxSizer *panel1sizer=new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *panel2sizer=new wxBoxSizer(wxVERTICAL);
    this->panel1->SetSizer(panel1sizer);
    this->panel2->SetSizer(panel2sizer);
    panel1sizer->Add(this->ctrl1,1,wxALIGN_CENTER);
    panel2sizer->Add(this->ctrl2,1,wxALIGN_CENTER);
    this->SetSizer(this->boxsizer);
    this->Centre();
}

bool App::OnInit()
{
    Border *border=new Border;
    border->Show(true);
    return true;
}