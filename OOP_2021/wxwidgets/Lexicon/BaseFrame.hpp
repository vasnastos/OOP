#include <wx/wx.h>


class frame:public wxFrame
{
    private:
        wxTextCtrl *results;
        void menu();
        wwxButton *b1,*b2,*b3,*b4,*b5;
        wxStaticText *desc;
        wxGrid *table;
        wxBoxSizer *sizer;
        void panel1();
        void panel2();
    public:
        frame();
        ~frame();
        void lengthevent(wxCommandEvent &ev);
        void startswithevent(wxCommandEvent &ev);
        void endswithevent(wxCommandEvent &ev);
        void containsevent(wxCommandEvent &ev);
        void patternevent(wxCommandEvent &ev);
};