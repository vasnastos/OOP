#include <wx/wx.h>
#include <iostream>
#include <string>

using namespace std;

class Window:public wxFrame
{
    public:
        Window(const string &title);
};
