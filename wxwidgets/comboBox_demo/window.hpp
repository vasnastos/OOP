#include <wx/wx.h>
#include <wx/combobox.h>


class window:public wxFrame
{
    private:
        wxComboBox *combo;
        wxBoxSizer *sizer;
        wxButton *button;
        wxTextCtrl *ctrl;
    public:
        window();
        ~window();
        void show_combo(wxCommandEvent &event);
        void display_text_ctrl(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};