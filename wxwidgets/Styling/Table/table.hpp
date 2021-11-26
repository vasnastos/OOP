#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/textdlg.h>
#include <vector>
#include <random>
#include <chrono>
#pragma GCC diagnostic pop

using namespace std;
using namespace std::chrono;


class window:public wxFrame
{
    private:
        wxGrid *table;
        wxBoxSizer *sizer;
        wxButton *button;
        vector <int> numbers;
    public:
        window();
        void randomize(wxCommandEvent &event);
        void hover(wxMouseEvent &ev);
        void hout(wxMouseEvent &ev);
};

class App:public wxApp
{
    public:
        bool OnInit();
};