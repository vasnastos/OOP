#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/textdlg.h>

class Frame:public wxFrame
{
    private:
        wxBoxSizer *sizer;
        wxButton *b1,*b2,*b3,*b4;
        wxListCtrl *list;
        void panel1();
        void panel2();
        void Create_List();
    public:
        Frame();
        ~Frame();
        void add(wxCommandEvent &event);
        void del(wxCommandEvent &event);
        void open(wxCommandEvent &event);
        void save(wxCommandEvent &event);
};
