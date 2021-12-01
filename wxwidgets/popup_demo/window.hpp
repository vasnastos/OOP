#include <wx/wx.h>
#include <wx/popupwin.h>
#include "popup.hpp"
#include <iostream>

using namespace std;

class window:public wxFrame
{
    private:
        wxBoxSizer *sizer;
        wxButton *button;
        popupWidget *popup;
    public:
        window();
        void SPop(wxCommandEvent &ev);  
};

class App:public wxApp
{
    public:
        bool OnInit();
};