#include "BaseFrame.h"
#include <iostream>
#include <fstream>

void Frame::panel1()
{
    wxPanel *panel=new wxPanel(this,wxID_ANY);
    wxBoxSizer *sz=new wxBoxSizer(wxHORIZONTAL);
    this->b1=new wxButton(panel,wxID_ANY,wxT("ADD"),wxDefaultPosition,wxSize(70,20));
    this->b2=new wxButton(panel,wxID_ANY,wxT("DELETE"),wxDefaultPosition,wxSize(70,20));
    this->b3=new wxButton(panel,wxID_ANY,wxT("OPEN"),wxDefaultPosition,wxSize(70,20));
    this->b4=new wxButton(panel,wxID_ANY,wxT("SAVE"),wxDefaultPosition,wxSize(70,20));
    this->b1->SetForegroundColour(wxColor("#520831"));
    this->b2->SetForegroundColour(wxColor("#520831"));
    this->b3->SetForegroundColour(wxColor("#520831"));
    this->b4->SetForegroundColour(wxColor("#520831"));
    this->b1->SetBackgroundColour(wxColor("#b1b3cc"));
    this->b2->SetBackgroundColour(wxColor("#b1b3cc"));
    this->b3->SetBackgroundColour(wxColor("#b1b3cc"));
    this->b4->SetBackgroundColour(wxColor("#b1b3cc"));
    this->b1->Bind(wxEVT_BUTTON,&Frame::add,this);
    this->b2->Bind(wxEVT_BUTTON,&Frame::del,this);
    this->b3->Bind(wxEVT_BUTTON,&Frame::open,this);
    this->b4->Bind(wxEVT_BUTTON,&Frame::save,this);
    sz->AddSpacer(5);
    sz->Add(this->b1,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    sz->Add(this->b2,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    sz->Add(this->b3,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    sz->Add(this->b4,0,wxALIGN_CENTER);
    sz->AddSpacer(5);
    panel->SetSizer(sz);
    this->sizer->AddSpacer(5);
    this->sizer->Add(panel,0,wxALIGN_CENTER);
}

void Frame::panel2()
{
    auto size=this->GetSize();
    std::cout<<size.GetHeight()*0.6<<std::endl;
    this->list=new wxListCtrl(this,wxID_ANY,wxDefaultPosition,wxSize(size.GetWidth()*0.95,size.GetHeight()*0.56),wxLC_LIST|wxLC_REPORT);
    this->Create_List();
    this->sizer->AddSpacer(100);
    this->sizer->Add(this->list,0,wxALIGN_CENTER);
}

void Frame::Create_List()
{
    auto size=this->list->GetSize();
    // this->list->AppendColumn("TO DO HEAD",wxLIST_FORMAT_CENTER,size.GetWidth()*0.97);
    wxListItem *item=new wxListItem;
    item->SetAlign(wxLIST_FORMAT_CENTER);
    item->SetWidth(size.GetWidth()*0.97);
    item->SetText("TASKS");
    this->list->InsertColumn(0,*item);
    this->list->SetColumnWidth(0,size.GetWidth()*0.95);
}

Frame::Frame():wxFrame(nullptr,wxID_ANY,wxT("Todo List"),wxDefaultPosition,wxSize(400,400))
{
    this->sizer=new wxBoxSizer(wxVERTICAL);
    this->panel1();
    this->panel2();
    this->SetSizer(this->sizer);
}

Frame::~Frame() {}

void Frame::add(wxCommandEvent &event)
{
    int val=this->list->GetItemCount();
    std::cout<<val<<std::endl;
    wxTextEntryDialog dial(this,wxT("Add to do task to the list"),wxT("APPEND TASK"));
    if(dial.ShowModal()==wxID_CANCEL)
    {
        return;
    }
    wxString task=_(dial.GetValue());
    this->list->InsertItem(val,task);
}

void Frame::del(wxCommandEvent &event)
{
    int selecteditem=this->list->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
    if(selecteditem==-1)
    {
        wxMessageBox("You did not select a task Try Again",wxT("Error"),wxICON_ERROR);
        return;
    }
    this->list->DeleteItem(selecteditem);    
}

void Frame::open(wxCommandEvent &event)
{
    wxFileDialog fd(this,"OPEN TASKS FILE","","","txt files (*.txt)|*.txt",wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(fd.ShowModal()==wxID_CANCEL)
    {
        return;
    }
    std::string filename=fd.GetCurrentlySelectedFilename().ToStdString(wxMBConvUTF8());
    std::fstream fs;
    fs.open(filename,std::ios::in);
    if(!fs.is_open())
    {
        wxMessageBox(wxT("File did not open properly!!!"),wxT("Error on file opening"),wxICON_ERROR);
        return;
    }
    int count_list_objects=this->list->GetItemCount();
    std::string line;
    while(std::getline(fs,line))
    {
        wxString append_string(wxString::FromUTF8(line));
        this->list->InsertItem(count_list_objects,_(append_string));
        count_list_objects++;
    }
    fs.close();
}

void Frame::save(wxCommandEvent &event)
{
   wxFileDialog fd(this,"Save Tasks","","","TXT FILES (*.txt)|*.txt",wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if(fd.ShowModal()==wxID_CANCEL)
   {
       return;
   }
   std::string filename=fd.GetPath().ToStdString(wxMBConvUTF8());
   std::fstream fs(filename,std::ios::out);
   if(!fs.is_open())
   {
       return;
   }
   int countlistobjects=this->list->GetItemCount();
   for(int i=0;i<countlistobjects;i++)
   {
       fs<<this->list->GetItemText(i)<<std::endl;
   }
   fs.close();
}