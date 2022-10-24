#include <wx/wx.h>
#include <wx/menu.h>
#include <iostream>
#include <string>

using namespace std;

class window:public wxFrame
{
    private:
        wxMenuBar *menubar;
        wxMenu *menu;
    public:
        window(const string &title);
        void OnQuit(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};