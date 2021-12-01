#include <wx/wx.h>
#include <wx/popupwin.h>
#include <wx/strconv.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "employee.hpp"


class popupWidget:public wxPopupTransientWindow
{
    private:
        wxTextCtrl *name,*id,*salary;
        wxScrolledWindow *spanel;
        
    public: 
        static std::vector <employee> employees;
        popupWidget(wxWindow *parent);
        virtual ~popupWidget();
        virtual void Popup(wxWindow *focus=NULL);
        virtual void OnDismiss();
        virtual bool Show(bool show=true);
        void insert(wxCommandEvent &event);
        void clearfields(wxCommandEvent &event);
};
