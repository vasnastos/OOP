#include "table.hpp"

employee::employee(int e_id,std::string e_name,double e_salary):id(e_id),name(e_name),salary(e_salary) {}

employee::~employee() {}

employee::operator std::string()const
{
    std::stringstream ss;
    ss<<"Name:"<<this->name<<" Salary:"<<this->salary<<std::endl;
    return ss.str();
}

bool operator<(const employee &e1,const employee &e2) {
    return e1.salary<e2.salary;
}

void window::panel1()
{
    auto panel1sizer=new wxBoxSizer(wxHORIZONTAL);
    auto panel=new wxPanel(this,wxID_ANY);
    auto stext=new wxStaticText(panel,wxID_ANY,wxT("Employees Id"),wxDefaultPosition,wxSize(150,20));
    wxColor c("#0d0945");
    stext->SetForegroundColour(c);
    this->ctrl1=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    panel1sizer->Add(stext,0,wxALIGN_CENTER);
    panel1sizer->AddSpacer(20);
    panel1sizer->Add(this->ctrl1,1,wxALIGN_CENTER);
    panel->SetSizer(panel1sizer);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel2()
{
    auto psizer=new wxBoxSizer(wxHORIZONTAL);
    auto panel=new wxPanel(this,wxID_ANY);
    auto stext=new wxStaticText(panel,wxID_ANY,wxT("Employees Name"),wxDefaultPosition,wxSize(150,20));
    wxColor col("#0d0945");
    stext->SetForegroundColour(col);
    this->ctrl2=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    psizer->Add(stext,0,wxALIGN_CENTER);
    psizer->AddSpacer(20);
    psizer->Add(this->ctrl2,1,wxALIGN_CENTER);
    panel->SetSizer(psizer);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel3()
{
    auto psizer=new wxBoxSizer(wxHORIZONTAL);
    auto panel=new wxPanel(this,wxID_ANY);
    auto stext=new wxStaticText(panel,wxID_ANY,wxT("Employees Salary"),wxDefaultPosition,wxSize(150,20));
    stext->SetForegroundColour(wxColor("#0d0945"));
    this->ctrl3=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
    psizer->Add(stext,0,wxALIGN_CENTER);
    psizer->AddSpacer(20);
    psizer->Add(this->ctrl3,1,wxALIGN_CENTER);
    panel->SetSizer(psizer);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::panel4()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    auto psizer=new wxBoxSizer(wxHORIZONTAL);
    this->add_button=new wxButton(panel,wxID_ANY,wxT("ADD"),wxDefaultPosition,wxSize(80,20));
    this->sort_button=new wxButton(panel,wxID_ANY,wxT("SORT"),wxDefaultPosition,wxSize(80,20));
    this->clear_button=new wxButton(panel,wxID_ANY,wxT("CLEAR"),wxDefaultPosition,wxSize(80,20));
    this->add_button->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::add_record,this);
    this->sort_button->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::Sort,this);
    this->clear_button->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&window::clear,this);
    psizer->Add(this->add_button,0,wxALIGN_CENTER);
    psizer->AddSpacer(20);
    psizer->Add(this->sort_button,1,wxALIGN_CENTER);
    psizer->AddSpacer(20);
    psizer->Add(this->clear_button,1,wxALIGN_CENTER);
    panel->SetSizer(psizer);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void window::Table()
{
    auto size=this->GetSize();
    const auto table_size=this->employees.size();
    this->table->CreateGrid(table_size,3);
    this->table->SetColSize(0,size.GetWidth()*0.22);
    this->table->SetColSize(1,size.GetWidth()*0.3);
    this->table->SetColSize(2,size.GetWidth()*0.25);
    this->table->SetColLabelValue(0,wxT("EMPLOYEE ID"));
    this->table->SetColLabelValue(1,wxT("EMPLOYEE NAME"));
    this->table->SetColLabelValue(2,wxT("EMPLOYEE \nSALARY"));
    this->table->SetLabelTextColour(wxColor("#071487"));
}

void window::AppendRecord()
{
    this->table->AppendRows(1);
    for(int i=0,table_size=this->employees.size();i<table_size;i++)
    {
        this->table->SetCellValue(i,0,std::to_string(this->employees[i].id));
        this->table->SetCellValue(i,1,this->employees[i].name);
        this->table->SetCellValue(i,2,std::to_string(this->employees[i].salary));
    }
}


window::window(std::string title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(500,500))
{
    auto size=this->GetSize();
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->sizer->AddSpacer(20);
    this->panel1();
    this->sizer->AddSpacer(20);
    this->panel2();
    this->sizer->AddSpacer(20);   
    this->panel3();
    this->sizer->AddSpacer(20);
    this->panel4();
    this->sizer->AddSpacer(20);
    this->table=new wxGrid(this,wxID_ANY,wxDefaultPosition,wxSize(size.GetWidth()*0.97,size.GetHeight()*0.5));
    
    this->Table();
    this->sizer->Add(this->table,0,wxALIGN_CENTER);
    this->SetSizer(this->sizer);
    this->Centre();
}



void window::add_record(wxCommandEvent &event)
{
    const std::string id=std::string(this->ctrl1->GetValue());
    const std::string name=std::string(this->ctrl2->GetValue());
    const std::string salary=std::string(this->ctrl3->GetValue());
    if(std::find_if(this->employees.begin(),this->employees.end(),[&](const employee &e) {return e.id==std::stoi(id);})!=this->employees.end()) return;
    this->employees.emplace_back(employee(std::stoi(id),name,std::stod(salary)));
    std::cout<<"New record:"<<id<<"-"<<name<<"-"<<salary<<std::endl;
    this->AppendRecord();
}

void window::clear(wxCommandEvent &event)
{
    this->ctrl1->SetValue("");
    this->ctrl2->SetValue("");
    this->ctrl3->SetValue("");
}

void window::Sort(wxCommandEvent &event)
{
    std::sort(this->employees.begin(),this->employees.end());
    for(int i=0,t=this->employees.size();i<t;i++)
    {
        this->table->SetCellValue(i,0,std::to_string(this->employees[i].id));
        this->table->SetCellValue(i,1,this->employees[i].name);
        this->table->SetCellValue(i,2,std::to_string(this->employees[i].salary));
    }
}

bool App::OnInit()
{
    window *w=new window("Employees App");
    w->Show();
    return true;
}