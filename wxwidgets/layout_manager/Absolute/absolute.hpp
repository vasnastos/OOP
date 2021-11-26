#include <wx/wx.h>
#include <wx/menu.h>
#include <string>
#include <iostream>

class Absolute:public wxFrame
{
    private:
        wxMenu *bar;
        wxMenu *bar1;
        wxMenu *bar2;
        wxTextCtrl *ctrl;
        wxMenuBar *menubar;
    public: 
        Absolute();
};

class App:public wxApp
{
    public:
        bool OnInit();
};