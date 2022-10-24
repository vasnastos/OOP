#include <wx\wx.h>

class Frame:public wxFrame
{
    private:
        wxStaticText *text;
    public: 
        Frame():wxFrame(nullptr,wxID_ANY,wxT("Test"),wxDefaultPosition,wxSize(400,400))
        {
            wxBoxSizer *bx=new wxBoxSizer(wxVERTICAL);
            this->text=new wxStaticText(this,wxID_ANY,wxT("Hello world"),wxDefaultPosition,wxSize(100,100));
            bx->Add(this->text,0,wxALIGN_CENTER);
            this->SetSizer(bx);
        }
};

class App:public wxApp{
    public:
        bool OnInit()
        {
            Frame *f=new Frame;
            f->Show(true);
            return true;
        }
};

wxIMPLEMENT_APP(App);