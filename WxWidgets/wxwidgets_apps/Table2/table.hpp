#include <wx/wx.h>
#include <wx/menu.h>
#include <wx/grid.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

struct employee
{
    int id;
    std::string name;
    double salary;
    employee(int e_id,std::string e_name,double e_salary);
    ~employee();
    operator std::string()const;
    std::string convcsv()const;
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
        wxMenuBar *bar;
        std::vector <employee> employees;
    public:
        window(std::string title);
        void menu();
        void panel1();
        void panel2();
        void panel3();
        void panel4();
        void Table();
        void AppendRecord();
        void add_record(wxCommandEvent &event);
        void Sort(wxCommandEvent &event);
        void clear(wxCommandEvent &event);
        void load(wxCommandEvent &event);
        void save(wxCommandEvent &event);
        void quit(wxCommandEvent &event);
};

class App:public wxApp
{
    public:
        bool OnInit();
};