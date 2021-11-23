#include <wx/wx.h>
#include <wx/menu.h>
#include <iostream>


class window:public wxFrame
{
    private:
        wxButton *button1;
        wxButton *button2;
        wxTextCtrl *ctrl;
    public:
        window(std::string title);
        void add(wxCommandEvent &event);
        void delete_id(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};