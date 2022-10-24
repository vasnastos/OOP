#include "window.hpp"

class App:public wxApp{
    public:
        bool OnInit()
        {
            string title="First Gui Window";
            Window *w=new Window(title);
            w->Show(true);
            return true;
        }
};

wxIMPLEMENT_APP(App);