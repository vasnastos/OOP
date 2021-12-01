#include <wx/wx.h>
#include <complex>

class window:public wxFrame
{
    private:
        wxBoxsizer *sizer;
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
};