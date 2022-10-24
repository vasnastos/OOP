#include <wx/wx.h>

class Frame:public wxFrame
{
    private:
        wxTextCtrl *intext;
        wxButton *button;
        wxTextCtrl *res;
    public:
        Frame():wxFrame(nullptr,wxID_ANY,wxT("TEST ENCODING"),wxDefaultPosition,wxSize(400,300))
        {
            this->intext=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(80,20));
            this->button=new wxButton(this,wxID_ANY,"ADD",wxDefaultPosition,wxSize(80,20));
            this->button->Bind(wxEVT_COMMAND_BUTTON_CLICKED,&Frame::add,this);
            this->res=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(200,100),wxTE_READONLY|wxTE_MULTILINE);
            wxBoxSizer *bx=new wxBoxSizer(wxVERTICAL);
            bx->AddSpacer(6);
            bx->Add(this->intext,0,wxALIGN_CENTER);
            bx->AddSpacer(6);
            bx->Add(this->button,0,wxALIGN_CENTER);
            bx->AddSpacer(5);
            bx->Add(this->res,0,wxALIGN_CENTER);
            this->SetSizer(bx);
            this->Centre();
        }

        void add(wxCommandEvent &ev)
        {
            std::cout<<this->intext->GetValue()<<std::endl;
            wxString sh=_(this->intext->GetValue());
            this->res->SetValue(sh);
        }

};

class App:public wxApp
{
    bool  OnInit()
    {
        Frame *f=new Frame;
        f->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(App);