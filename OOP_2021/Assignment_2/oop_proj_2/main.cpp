#include <wx/wx.h>
#include "management.hpp"
#pragma set_execution_character("utf-8")

class Frame :public wxFrame {
public:
    Frame() :wxFrame(nullptr, wxID_ANY, wxT("Hello world app"), wxDefaultPosition, wxSize(500, 500))
    {
        wxStaticText* text = new wxStaticText(this, wxID_ANY, wxT("Hello world"), wxDefaultPosition, wxSize(200, 40));
        wxBoxSizer* bx = new wxBoxSizer(wxVERTICAL);
        bx->AddSpacer(20);
        bx->Add(text, 0, wxALIGN_CENTER);
        this->SetSizer(bx);
    }
};

class App :public wxApp {
public:
    bool OnInit()
    {
        Frame* f = new Frame;
        f->Show();
        return true;
    }
};

wxIMPLEMENT_APP_NO_MAIN(App);

void menu()
{
    SetConsoleOutputCP(65001);
    cout << "1. Εισαγωγή νέου φοιτητή" << endl;
    cout << "2. Ενημέρωση στοιχείων φοιτητή" << endl;
    cout << "3. Διαγραφή φοιτητή" << endl;
    cout << "4. Δήλωση μαθήματος" << endl;
    cout << "5. Εμφάνιση δηλώσεων ανά φοιτητή(GUI)" << endl;
    cout << "0. Έξοδος" << endl;
    cout << "Δώστε επιλογή :"<<endl;
}

int main(int argc,char **argv)
{   
    SetConsoleOutputCP(65001);
    Management msystem;
    int choice;
    while (true)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            msystem.insert_student();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            cerr << "Μη διαθέσιμη επιλογή!Παρακαλώ επιλέξτε μία από τις διαθέσιμες επιλογές[0-5]" << endl;
            break;
        }
    }
    return 0;
}
/*
int main()
{
    vector <Course> courses;
    vector <Student> students;

    string filename = "dit_uoi_course.txt";
    fstream fs;
    fs.open(filename, ios::in);
    if (!fs.is_open())
    {
        cerr << "File " << filename << " does not exist" << endl;
        return;
    }
    string line,word;
    bool first_line = true;
    vector <string> data;
    while (getline(fs, line))
    {
        if (first_line)
        {
            first_line = false;
            continue;
        }
        data.clear();
        stringstream ss(line);
        while (getline(ss, word, ','))
        {
            data.push_back(word);
        }
        courses.push_back(Course(data[0],stoi(data[1]),data[2],stoi(data[3])));
    }
    fs.close();

    int choice;
    while (true)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            string id,name;
	        int semester, credits;
	        cout << "Δώσε AM φοιτητή:";
	        cin >> id;
	        cout << "Δώσε Όνομα φοιτητή:";
	        cin.ignore();
	        getline(cin,name);
	        cout << "Δώσε Εξάμηνο φοιτητή:";
	        cin >> semester;
	        cout << "Δώσε Δ. Μονάδες φοιτητή:";
	        cin >> credits;
	        students.push_back(Student(id, name, semester, credits));
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            cerr << "Μη διαθέσιμη επιλογή!Παρακαλώ επιλέξτε μία από τις διαθέσιμες επιλογές[0-5]" << endl;
            break;
        }
    }
    return 0;
}
*/