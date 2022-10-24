#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/grid.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

struct employee
{
    int id;
    std::string name;
    double salary;
    employee(int e_id,std::string e_name,double e_salary);
    ~employee();
    operator std::string()const;
};

class window:public wxFrame
{
    private:    
        wxBoxSizer *sizer;
        wxTextCtrl *ctrl1;
        wxTextCtrl *ctrl2;
        wxTextCtrl *ctrl3;
        wxButton *add_button,*clear_button,*sort_button;
        wxGrid *table;
        std::vector <employee> employees;
    public:
        window(std::string title);
        void panel1();
        void panel2();
        void panel3();
        void panel4();
        void Table();
        void AppendRecord();
        void add_record(wxCommandEvent &event);
        void Sort(wxCommandEvent &event);
        void clear(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};