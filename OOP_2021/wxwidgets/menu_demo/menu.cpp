#include "menu.hpp"


window::window(const string &title):wxFrame(nullptr,wxID_ANY,title,wxDefaultPosition,wxSize(300,300))
{
  this->menubar=new wxMenuBar;
  this->menu=new wxMenu;
  this->menu->Append(wxID_EXIT,"QUIT");
  this->menubar->Append(this->menu,"MENU");
  SetMenuBar(this->menubar);
  Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(window::OnQuit));
  Centre();//Τοποθέτηση στοιχείων στο κέντρο του παραθύρου
  //wxEVT_COMMAND_MENU_SELECTED->Ενέργεια που προκάλεσε την κλήση της συνάρτησης ακροατή [component που ενεργοποιήθηκε]
}

void window::OnQuit(wxCommandEvent &event)
{
    cout<<"App is closing"<<endl;
    this->Close(true);
}

bool App::OnInit()
{
    string title="Menubar Application";
    window *w=new window(title);
    w->Show();
    return true;
}