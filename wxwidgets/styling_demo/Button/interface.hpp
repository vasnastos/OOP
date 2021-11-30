#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/font.h>

class window:public wxFrame
{
    private:
        wxMenuBar *bar;
        wxButton *b1,*b2;  
    public:
        window();
        ~window();
        void onhover(wxMouseEvent &event);
        void onhover2(wxMouseEvent &event);
        void onhoverout(wxMouseEvent &ev);
        void onhoverout2(wxMouseEvent &ev);
        void button1event(wxCommandEvent &event);
        void button2event(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit()override;
};