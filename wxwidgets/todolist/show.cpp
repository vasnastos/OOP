#include "BaseFrame.h"

class App:public wxApp
{
    bool OnInit()
    {
        Frame *f=new Frame;
        f->Show(true);
        return true;
    }
};


wxIMPLEMENT_APP(App);