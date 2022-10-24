#include "absolute.hpp"

Absolute::Absolute():wxFrame(nullptr,wxID_ANY,"This an Absolute Layout Example",wxDefaultPosition,wxSize(300,300))
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    this->bar=new wxMenu;
    this->bar1=new wxMenu;
    this->bar2=new wxMenu;
    this->menubar=new wxMenuBar;
    this->menubar->Append(this->bar,"FILE");
    this->menubar->Append(this->bar1,"EDIT");
    this->menubar->Append(this->bar2,"HELP");
    this->SetMenuBar(this->menubar);
    this->ctrl=new wxTextCtrl(panel,wxID_ANY,"This a TextCtrl Component",wxDefaultPosition,wxSize(60,80),wxTE_MULTILINE);
}

bool App::OnInit()
{
    Absolute *abs=new Absolute;
    abs->Show(true);
    return true;
}