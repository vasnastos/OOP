#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/statbmp.h>
#include <wx/msgdlg.h>
#include <iostream>
#include <string>
#include <experimental/filesystem>
#pragma GCC diagnostic pop

namespace fs=std::experimental::filesystem;

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
        void toolbar();
    public:
        window(const string &title);
        void w7(wxCommandEvent &event);
        void w10(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};