#include "image.hpp"

enum
{
    WXWIN7=12001,
    WXWIN10=12002
};

void window::menu()
{
    wxMenu* m=new wxMenu;
    this->bar=new wxMenuBar;
    wxFont *f=new wxFont(13,wxFONTFAMILY_SWISS,wxNORMAL,wxBOLD);
    wxMenuItem *item1=new wxMenuItem(m,WXWIN7,"WINDOWS7");
    wxMenuItem *item2=new wxMenuItem(m,WXWIN10,"WINDOWS10");
    m->Append(item1);
    m->Append(item2);
    this->Connect(WXWIN7,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(window::w7));
    this->Connect(WXWIN10,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(window::w10));
    this->bar->Append(m,"SETTINGS");
    this->SetMenuBar(this->bar);
}

window::window(const string &title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(500,500))
{
    auto size=this->GetSize();
    this->SetIcon(wxIcon("./sources/demo.png"));
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->menu();
    wxPanel *panel=new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(size.GetWidth(),size.GetWidth()));
    wxSize psize(panel->GetSize().GetWidth()*0.8,panel->GetSize().GetHeight()*0.8);
    this->image=new wxStaticBitmap(panel,wxID_ANY,wxBitmap(),wxDefaultPosition,psize);
    this->SetSizer(this->sizer);
}

void window::w7(wxCommandEvent &event)
{
    string current_path=fs::current_path();
    fs::path pth(current_path);
    pth.append("sources");
    if(!fs::exists(pth))
    {
        wxMessageBox(wxT("File path "+string(pth.c_str())+" does not exist"),"FILE NOT FOUND",wxICON_ERROR);
        return;
    }
    pth.append("win7.png");
    if(!fs::exists(pth))
    {
        wxMessageBox(wxT("File path "+string(pth.c_str())+" does not exist"),"FILE NOT FOUND",wxICON_ERROR);
    }
    wxBitmap bicon(string(pth.c_str()),wxBITMAP_TYPE_PNG);
    this->image->SetBitmap(bicon);
}

void window::w10(wxCommandEvent &event)
{
     string current_path=fs::current_path();
    fs::path pth(current_path);
    pth.append("sources");
    if(!fs::exists(pth))
    {
        wxMessageBox(wxT("File path "+string(pth.c_str())+" does not exist"),"FILE NOT FOUND",wxICON_ERROR);
        return;
    }
    pth.append("win10.png");
    if(!fs::exists(pth))
    {
        wxMessageBox(wxT("File path "+string(pth.c_str())+" does not exist"),"FILE NOT FOUND",wxICON_ERROR);
        return;
    }
    wxBitmap bicon(string(pth.c_str()),wxBITMAP_TYPE_PNG);
    this->image->SetBitmap(bicon);
}

bool App::OnInit()
{
    window *w=new window("ICONS USED");
    w->Show();
    return true;
}