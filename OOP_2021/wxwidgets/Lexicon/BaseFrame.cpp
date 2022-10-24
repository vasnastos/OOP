#include "BaseFrame.hpp"
#define OPEN 901


void frame::menu()
{
    wxMenu *menu=new wxMenu;
    wxMenuBar *bar=new wxMenuBar;
    wxMenuItem *item1=new wxMenuItem(menu,OPEN,wxT("IMPORT"));
    wxMenuItem *item2=new wxMenuItem(menu,wxID_EXIT,wxT("CLOSE"));
    menu->Append(item1,this);
    menu->Append(itm2,this);
    bar->Append(menu,"App");
    this->SetMenuBar(bar);
}

void frame::panel1()
{
    auto size=this->GetSize();
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxBoxSizer *sz=new wxBoxSizer(wxVERTICAL);
    std::string message="** Lexicon App **\n1.Find words with equal length\n2.Find words start with a predefined pattern\n3.Find words which ends with predefinied routine.\n4.Find word which repeat a specific pattern,in a specific amount of times\n5.Find words which follow a specific pattern";
    this->desc=new wxStaticText(panel,wxID_ANY,message,wxDefaultPosition,wxSize(size.GetWidth()*0.7,70),wxTE_MULTILINE|wxTE_READONLY);
    panel->SetSizer(sz);
    
    // A panel into another panel
    wxPanel *subpanel=new wxPanel(panel,wxID_ANY);
    wxBoxSizer *psizer=new wxBoxSizer(wxVERTICAL);
    wxStaticText *statict=new wxStaticText(panel,wxID_ANY,wxT("OPTIONS"),wxDeafultPostion,wxSize(70,20));
    this->b1=new wxButton(subpanel,wxID_ANY,wxT("1.LENGTH"),wxDefaultPosition,wxSize(100,20));
    this->b2=new wxButton(subpanel,wxID_ANY,wxT("2.STARTS_WITH"),wxDefaultPosition,wxSize(100,20));
    this->b3=new wxButton(subpanel,wxID_ANY,wxT("3.ENDS_WITH"),wxDefaultPosition,wxSize(100,20));
    this->b4=new wxButton(subpanel,wxID_ANY,wxT("4.REPEAT_PATTERN"),wxDefaultPosition,wxSize(100,20));
    this->b5=new wxButton(subpanel,wxID_ANY,wxT("5.SPECIFIC_PATTERN"),wxDefaultPosition,wxSize(100,20),wxALIGN_CENTER);
    wxFont f(10,wxFONTFAMILY_ROMAN,wxNORMAL,wxBOLD);
    f.MakeUnderlined();
    statict->SetFont(f);
    psizer->AddSpacer(10);
    psizer->Add(statict,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    psizer->Add(this->b1,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    psizer->Add(this->b2,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    psizer->Add(this->b3,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    psizer->Add(this->b4,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    psizer->Add(this->b5,0,wxALIGN_CENTER);
    psizer->AddSpacer(5);
    subpanel->SetSizer(psizer);
}

frame::frame():wxFrame(nullptr,wxID_ANY,wxT("Lexicon App"),wxDefaultPosition,wxSize(500,500))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->SetSizer(this->sizer);
    this->menu();
    this->Centre();   
}

