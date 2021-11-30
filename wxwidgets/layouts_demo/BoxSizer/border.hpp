#include <wx/wx.h>
#include <wx/menu.h>
#include <string>
#include <iostream>

using namespace std;

class Border:public wxFrame
{
    private:
        wxPanel *panel1;
        wxPanel *panel2;
        wxBoxSizer *boxsizer;
        wxTextCtrl *ctrl1,*ctrl2;
    public:
        Border();
};

class App:public wxApp
{
    public:
        bool OnInit();
};