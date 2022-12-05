// Γράψτε πρόγραμμα που να ορίζει μια κλάση date (ημερομηνία) με ιδιωτικά μέλη δεδομένων day (αριθμός ημέρας μήνα), month (αριθμός μήνα) και year (έτος). 
// Συμπληρώστε 3 κατασκευαστές με κανένα, δύο και τρεις παραμέτρους αντίστοιχα. Ο κατασκευαστής χωρίς παραμέτρους να θέτει την ημερομηνία 1/1/2021. 
// O κατασκευαστής με δύο παραμέτρους να τις χρησιμοποιεί για να θέσει αριθμό ημέρας και μήνα και να ορίζει ως έτος το 2022. 
// Ο κατασκευαστής με τρεις παραμέτρους να να τις χρησιμοποιεί για να θέσει αριθμό ημέρας, αριθμό μήνα και έτος. Συμπληρώστε getters και για τα 3 πεδία. 
// Συμπληρώστε μια ιδεατή συνάρτηση string desc() που να επιστρέφει την ημερομηνία με το συνηθισμένο τρόπο αναγραφής της (π.χ. 20/11/2021). 
// Ορίστε μια κλάση holiday (αργία) που να κληρονομεί από την date και να ορίζει ένα επιπλέον ιδιωτικό πεδίο name (όνομα) που θα περιέχει το όνομα της αργίας. 
// Παρακάμψτε τη συνάρτηση desc της date έτσι ώστε να εμφανίζει και το όνομα της αργίας. Πειραματιστείτε με τη χρήση αντικειμένων, αναφορών και δεικτών date ως παραμέτρων συναρτήσεων που καλούνται με αντικείμενα holiday. 

#include <iostream>
#include <string>

using namespace std;

class date
{
private:
    int day, month, year;

public:
    date() : day(1), month(1), year(2022){};
    date(int d, int m) : day(d), month(m), year(2022){};     
    date(int d, int m, int y) : day(d), month(m), year(y){};
    int get_day() const { return day; }
    int get_month() const { return month; }
    int get_year() const { return year; }
    virtual string desc() const { return to_string(day) + '/' + to_string(month) + '/' + to_string(year); }
};

class holiday : public date
{
private:
    string name;

public:
    holiday(string n) : date(), name(n) {} // constructor που καλεί τον constructor της βασικής κλάσης
    holiday(string n, int d, int m) : date(d, m), name(n) {} // constructor που καλεί τον constructor της βασικής κλάσης
    string get_name() const { return name; }
    virtual string desc() const
    {
        return name + " " + date::desc();
    }
};

// static binding, κλήση με τιμή
void fun1(date d)
{
    cout << "It's " << d.desc() << endl;
}

// dynamic binding, κλήση με αναφορά
void fun2(date &d)
{
    cout << "It's " << d.desc() << endl;
}

// dynamic binding
void fun3(date *d)
{
    cout << "It's " << d->desc() << endl;
}

int main()
{
    holiday h("Christmas", 25, 12);
    cout << h.desc() << endl; // Christmas 25/12/2022

    date d = h;               // slicing
    cout << d.desc() << endl; // 25/12/2022

    // static vs dynamic binding
    fun1(h);  // It's 25/12/2022
    fun2(h);  // It's Christmas 25/12/2022
    fun3(&h); // It's Christmas 25/12/2022
}

/* έξοδος
Christmas 25/12/2021
25/12/2021
It's 25/12/2021
It's Christmas 25/12/2021
It's Christmas 25/12/2021
*/