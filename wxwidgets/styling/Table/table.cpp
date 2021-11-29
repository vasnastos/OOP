#include "table.hpp"

window::window():wxFrame(nullptr,wxID_ANY,"Random Table",wxDefaultPosition,wxSize(400,400))
{
    auto size=this->GetSize();
    this->sizer=new wxBoxSizer(wxVERTICAL);
    auto tablesize=wxSize(size.GetWidth()*0.97,size.GetHeight()*0.5);
    std::cout<<tablesize.GetWidth()<<std::endl;
    this->table=new wxGrid(this,wxID_ANY,wxDefaultPosition,tablesize,wxBORDER_SIMPLE);
    this->table->CreateGrid(0,1);
    this->table->SetColLabelValue(0,"Random Number");
    this->table->SetColSize(0,tablesize.GetWidth()*0.79);
    this->table->SetLabelTextColour(wxColor("#040738"));
    wxFont f(15,wxDEFAULT,wxNORMAL,wxBOLD);
    this->table->EnableGridLines(true);
    this->table->SetFont(f);
    this->button=new wxButton(this,wxID_ANY,"RANDOMIZE",wxDefaultPosition,wxSize(120,26));
    this->button->SetForegroundColour(wxColor("#040738"));
    this->button->SetBackgroundColour(wxColor("#c4a9c9"));
    this->button->Bind(wxEVT_ENTER_WINDOW,&window::hover,this);
    this->button->Bind(wxEVT_LEAVE_WINDOW,&window::hout,this);
    this->button->Bind(wxEVT_BUTTON,&window::randomize,this);
    this->sizer->AddSpacer(30);
    this->sizer->Add(this->table,0,wxALIGN_CENTER);
    this->sizer->AddSpacer(30);
    this->sizer->Add(this->button,0,wxALIGN_CENTER);
    this->SetSizer(this->sizer);
    this->Centre();
}

void window::hover(wxMouseEvent &ev)
{
    this->button->SetBackgroundColour(wxColor("#040738"));
    this->button->SetForegroundColour(wxColor("#c4a9c9"));
    this->SetCursor(wxCursor(wxCURSOR_HAND));
}

void window::hout(wxMouseEvent &ev)
{
    this->button->SetForegroundColour(wxColor("#040738"));
    this->button->SetBackgroundColour(wxColor("#c4a9c9"));
    this->SetCursor(wxCursor(wxCURSOR_ARROW));
}

void window::randomize(wxCommandEvent &ev)
{
    wxTextEntryDialog dialog(this,"Input Amount of Numbers you want to create","Input Amount");
    if(dialog.ShowModal()==wxID_CANCEL)
    {
        return;
    }
    std::string num="";
    #ifdef __WIN32__
        num=dialog.GetValue().ToStdString();
    #elif linux
        num=dialog.GetValue().ToStdString(wxMBConvUTF8());
    #endif
    int number_of_integers=std::stoi(num);
    mt19937 mt(steady_clock::now().time_since_epoch().count());
    auto rand_int=uniform_int_distribution<int>(1,1100);
    if(this->table->GetNumberRows()!=0) 
    this->table->DeleteRows(0,this->table->GetNumberRows());
    this->numbers.clear();
    for(int i=0;i<number_of_integers;i++)
    {
        this->numbers.emplace_back(rand_int(mt));
    }
    this->table->AppendRows(this->numbers.size());
    for(int i=0,t=this->numbers.size();i<t;i++)
    {
        this->table->SetCellValue(i,0,std::to_string(this->numbers.at(i)));
        this->table->SetCellAlignment(i,0,wxALIGN_CENTRE,wxALIGN_CENTRE);
        this->table->SetCellTextColour(i,0,wxColor("#214a2b"));
    }
}

bool App::OnInit()
{
    window *w=new window();
    w->Show();
    return true;
}