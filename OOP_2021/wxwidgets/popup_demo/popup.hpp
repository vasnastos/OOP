#include <wx/wx.h>
#include <wx/popupwin.h>
#include <iostream>

using namespace std;

class popupWidget:public wxPopupTransientWindow
{
    public:
        popupWidget(wxWindow *parent);
        virtual ~popupWidget();
        virtual void Popup(wxWindow *focus = NULL)wxOVERRIDE;
        virtual void OnDismiss()wxOVERRIDE;
        virtual bool Show(bool show=true)wxOVERRIDE;
        void ButtonClicked(wxCommandEvent &event);
        
    private:
        wxScrolledWindow *w_panel;
        wxButton *w_button;
        wxStaticText *w_static_text;
};