#include "window.hpp"

void window::panel1()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    this->real1=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    this->imag1=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"i",wxDefaultPosition,wxSize(30,20),wxALIGN_LEFT);
    wxFont f(10,wxFONTFAMILY_SWISS,wxNORMAL,wxBOLD);
    st->SetFont(f);
    st->SetForegroundColour(wxColor("#1d1485"));
    wxBoxSizer *sz=new wxBoxSizer(wxHORIZONTAL);
    sz->AddSpacer(20);
    sz->Add(real1,0,wxALIGN_CENTER);
    sz->AddSpacer(30);
    sz->Add(imag1,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    sz->Add(st,0,wxALIGN_CENTER);
    panel->SetSizer(sz);
    this->sizer->AddSpacer(25);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel2()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    this->real2=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    this->imag2=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    wxStaticText *st=new wxStaticText(panel,wxID_ANY,"i",wxDefaultPosition,wxSize(30,20),wxALIGN_LEFT);
    wxFont f(10,wxFONTFAMILY_SWISS,wxNORMAL,wxBOLD);
    st->SetFont(f);
    wxBoxSizer *sz=new wxBoxSizer(wxHORIZONTAL);
    sz->AddSpacer(30);
    sz->Add(this->real2,0,wxALIGN_CENTER);
    sz->AddSpacer(30);
    sz->Add(this->imag2,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    sz->Add(st,0,wxALIGN_LEFT);
    panel->SetSizer(sz);
    this->sizer->AddSpacer(25);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel3()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxButton *b1=new wxButton(panel,wxID_ANY,wxT("ADD"),wxDefaultPosition,wxSize(80,20));
    wxButton *b2=new wxButton(panel,wxID_ANY,wxT("SUB"),wxDefaultPosition,wxSize(80,20));
    wxButton *b3=new wxButton(panel,wxID_ANY,wxT("MUL"),wxDefaultPosition,wxSize(80,20));
    wxButton *b4=new wxButton(panel,wxID_ANY,wxT("DIV"),wxDefaultPosition,wxSize(80,20));
    b1->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::add,this);
    b2->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::sub,this);
    b3->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::mul,this);
    b4->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::div,this);
    wxBoxSizer *bx=new wxBoxSizer(wxHORIZONTAL);
    bx->Add(b1,0,wxALIGN_CENTER);
    bx->AddSpacer(15);
    bx->Add(b2,0,wxALIGN_CENTER);
    bx->AddSpacer(15);
    bx->Add(b3,0,wxALIGN_CENTER);
    bx->AddSpacer(15);
    bx->Add(b4,0,wxALIGN_CENTER);
    panel->SetSizer(bx);
    this->sizer->AddSpacer(25);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

window::window():wxFrame(nullptr,wxID_ANY,"Complex Calculator",wxDefaultPosition,wxSize(400,400))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    auto size=this->GetSize();
    wxStaticText *statictext=new wxStaticText(this,wxID_ANY,wxT("Complex Number Calculator"),wxDefaultPosition,wxSize(size.GetWidth()*0.9,40),wxALIGN_CENTER);
    wxFont stfont(13,wxFONTFAMILY_SWISS,wxNORMAL,wxBOLD);
    statictext->SetFont(stfont);
    statictext->SetForegroundColour(wxColor("#4c154f"));
    this->sizer->Add(statictext,0,wxALIGN_CENTER);
    this->panel1();
    this->panel2();
    this->panel3();
    this->res=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(300,50),wxTE_READONLY);
    this->sizer->AddSpacer(30);
    this->sizer->Add(this->res,0,wxALIGN_CENTER);
    this->SetSizer(this->sizer);      
}

void window::add(wxCommandEvent &ev)
{
    int real_value=std::stoi(std::string(this->real1->GetValue()));
    int imag_value=std::stoi(std::string(this->imag1->GetValue()));
    int real_value2=std::stoi(std::string(this->real2->GetValue()));
    int imag_value2=std::stoi(std::string(this->imag2->GetValue()));
    std::complex <double> c(real_value,imag_value);
    std::complex <double> c1(real_value2,imag_value2);
    auto c2=c+c1;
    double r=c2.real();
    double i=c2.imag();
    std::string to_stream=std::to_string(r)+std::to_string(i)+"i";
    this->res->SetValue(to_stream);
}

void window::sub(wxCommandEvent &event)
{
    int real_value=std::stoi(std::string(this->real1->GetValue()));
    int imag_value=std::stoi(std::string(this->imag1->GetValue()));
    int real_value2=std::stoi(std::string(this->real2->GetValue()));
    int imag_value2=std::stoi(std::string(this->imag2->GetValue()));
    std::complex <double> c(real_value,imag_value);
    std::complex <double> c1(real_value2,imag_value2);
    auto c2=c-c1;
    double r=c2.real();
    double i=c2.imag();
    std::string to_stream=std::to_string(r)+std::to_string(i)+"i";
    this->res->SetValue(to_stream);
}

void window::mul(wxCommandEvent &event)
{
    int real_value=std::stoi(std::string(this->real1->GetValue()));
    int imag_value=std::stoi(std::string(this->imag1->GetValue()));
    int real_value2=std::stoi(std::string(this->real2->GetValue()));
    int imag_value2=std::stoi(std::string(this->imag2->GetValue()));
    std::complex <double> c(real_value,imag_value);
    std::complex <double> c1(real_value2,imag_value2);
    auto c2=c*c1;
    double r=c2.real();
    double i=c2.imag();
    std::string to_stream=std::to_string(r)+std::to_string(i)+"i";
    this->res->SetValue(to_stream);
}

void window::div(wxCommandEvent &event)
{
    int real_value=std::stoi(std::string(this->real1->GetValue()));
    int imag_value=std::stoi(std::string(this->imag1->GetValue()));
    int real_value2=std::stoi(std::string(this->real2->GetValue()));
    int imag_value2=std::stoi(std::string(this->imag2->GetValue()));
    std::complex <double> c(real_value,imag_value);
    std::complex <double> c1(real_value2,imag_value2);
    double r=c2.real();
    double i=c2.imag();
    auto c2=c/c1;
    std::string to_stream=std::to_string(r)+std::to_string(i)+"i";
    this->res->SetValue(to_stream);
}

bool App::OnInit()
{
    window *w=new window;
    w->Show();
    return true;
}
