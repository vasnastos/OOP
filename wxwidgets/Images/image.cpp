#include "image.hpp"

void window::menu()
{
    wxMenu* m=new wxMenu;
    this->bar=new wxMenuBar;
    wxFont *f=new wxFont(13,wxFONTFAMILY_SWISS,wxNORMAL,wxBOLD);
    wxMenuItem *item1=new wxMenuItem(m,WIN7," ");
    wxMenuItem *item2=new wxMenuItem(m,WIN10," ");
    wxBitmap icon1(wxT("./sources/win7.png"),wxBITMAP_TYPE_PNG);
    wxBitmap icon2(wxT("./sources/win10.png"),wxBITMAP_TYPE_PNG);
    item1->SetBitmap(icon1);
    item2->SetBitmap(icon2);
    m->Append(item1);
    m->Append(item2);
    this->bar->Append(m,"SETTINGS");
    this->SetMenuBar(this->bar);
}

window::window(const string &title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(500,500))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->menu();
    this->SetSizer(this->sizer);
}

bool App::OnInit()
{
    window *w=new window("ICONS USED");
    w->Show();
    return true;
}