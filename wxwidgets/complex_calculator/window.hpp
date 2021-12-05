#include <wx/wx.h>
#include <complex>
#include <sstream>
#include <string>

class window:public wxFrame
{
    private:
        wxBoxSizer *sizer;
        wxTextCtrl *real1;
        wxTextCtrl *imag1;
        wxTextCtrl *real2;
        wxTextCtrl *imag2; 
        wxTextCtrl *res;
    public:
        window();
        void panel1();
        void panel2();
        void panel3();
        void add(wxCommandEvent &event);
        void sub(wxCommandEvent &event);
        void mul(wxCommandEvent &event);
        void div(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit()wxOVERRIDE;
};