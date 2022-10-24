#include <wx/wx.h>
#include "popup.hpp"

class window:public wxFrame
{
    private:
        void panel1();
        void panel2();
        wxBoxSizer *sizer;
        wxButton *insertbutton;
        wxButton *showbutton;
        wxTextCtrl *results;
        popupWidget *wpop;

    public:
        static std::vector <employee> employees;
        window();
        ~window();
        void popinsert(wxCommandEvent &event);
        void showemps(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit()wxOVERRIDE;
};