#include <wx/wx.h>
#include <wx/menu.h>
#include <iostream>
#include <string>

enum 
{
    WIN7=10001,
    WIN10=10002
};

using namespace std;

class window:public wxFrame
{
    private:
        wxBoxSizer *sizer;
        wxStaticBitmap *image;
        wxMenuBar *bar;
        void menu();
    public:
        window(const string &title);
        void win7(wxCommandEvent &ev);
        void win10(wxCommandEvent &ev);
};

class App:public wxApp
{
    public:
        bool OnInit();
};