#include "vending_machine.hpp"

const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d   %X", &tstruct);

    return buf;
}

map <string,string> Vending_Machine::products_in_greek{
    {"coffee","Καφές"},
    {"chocolate","σοκολάτα"},
    {"milk","γάλα"}
};

Vending_Machine::Vending_Machine():total_check(0.0),temporary_amount(0.0)
{
    this->products={
        {"coffee",1.5},
        {"chocolate",2.1},
        {"milk",0.3}
    };
    this->quantity={
        {"coffee",10},
        {"chocolate",10},
        {"milk",20}
    };

    this->coin_buffer={
        {0.1,0},
        {0.2,0},
        {0.5,0},
        {1.0,0},
        {2.0,0},
        {5.0,0},
        {10.0,0}
    };
}

Vending_Machine::~Vending_Machine() {}


void Vending_Machine::payout(string product,bool has_milk)
{
    cout<<endl;
    this->temporary_amount=0;
    if(this->quantity[product]==0)
    {
        cout<<"Η ποσότητα του προιόντος:"<<Vending_Machine::products_in_greek[product]<<" δεν επαρκεί για την παρασκευή του"<<endl;
        system("pause");
        return;
    }
    if(has_milk)
    {
        if(this->quantity["milk"]==0)
        {
            cout<<"Η ποσότητα του προιόντος:"<<Vending_Machine::products_in_greek["milk"]<<" δεν επαρκεί για την παρασκευή του"<<endl;
            system("pause");
            return;
        }
    }
    this->total_check=this->products[product];
    if(has_milk)
    {
        this->total_check+=this->products["milk"];
    }
    bool cancel;
    while(this->temporary_amount<this->total_check)
    {
        cancel=this->coin_insert();
        if(cancel)
        {
            return;
        }
    }
    this->reduce_quantity(product);
    if(has_milk)
    {
        this->reduce_quantity("milk");
    }
    cout<<endl<<"=== ΑΠΟΔΕΙΞΗ ==="<<endl;
    cout<<"Ημερομηνία:"<<currentDateTime()<<endl;
    cout<<"Προιόν:"<<Vending_Machine::products_in_greek[product]<<(has_milk?" με γάλα":"")<<endl;
    cout<<"Συνολικό ποσό πληρωμής:"<<this->total_check<<" ευρώ"<<endl;
    cout<<"Ποσό πληρωμής:"<<this->temporary_amount<<" ευρώ"<<endl;
    cout<<"Ρέστα:"<<this->temporary_amount-this->total_check<<" ευρώ"<<endl;
    system("pause");
}


bool Vending_Machine::coin_insert()
{
    map <int,double> coin_selected;
    int count=0;
    unsigned int coin_selection;
    cout<<endl<<"=== Εισαγωγή νομίσματος ==="<<endl;
    for(auto &coin:this->coin_buffer)
    {
        cout<<" "<<count<<". "<<coin.first<<endl;
        coin_selected[count]=coin.first;
        count++;
    }
    cout<<"-1. Ακύρωση παραγγελίας"<<endl;
    cout<<"Επιλέξτε νόμισμα:";
    cin>>coin_selection;
    while(coin_selection!=-1 && (coin_selection<0 || coin_selection>this->coin_buffer.size()-1))
    {
        cout<<coin_selection<<endl;
        cout<<endl<<"Η επιλογή δεν ήταν έγκυρη παρακαλώ επιλέξτε μία από τις διαθέσιμες επιλογές[-1-"<<this->coin_buffer.size()-1<<"]:";
        cin>>coin_selection;   
    }
    if(coin_selection==-1)
    {
        cout<<endl<<currentDateTime()<<"-Ακύρωση παραγγελίας"<<endl;
        cout<<"Νομίσματα"<<endl;
        cout<<"----"<<endl;
        for(auto &coin:this->coin_buffer)
        {
            cout.precision(3);
            if(coin.second>0)
            cout<<"Νόμισμα:"<<coin.first<<" ευρώ\tΠοσότητα:"<<coin.second<<endl;
        }
        cout<<"Επιστροφή στον Χρήστη:"<<this->temporary_amount<<endl;
        system("pause");
        return true;
    }
    this->coin_buffer[coin_selected[coin_selection]]++;
    this->temporary_amount+=coin_selected[coin_selection];
    cout<<"\n==>Περιγραφή εισαγωγής"<<endl;
    cout<<" Πραγματοποιήθηκε εισαγωγή νομίσματος::Νόμισμα:"<<coin_selected[coin_selection]<<" ευρώ"<<endl;
    cout<<" Υπόλοιπο για συμπλήρωση πληρωμής:"<<(this->total_check-this->temporary_amount>0?this->total_check-this->temporary_amount:0)<<endl;
    system("pause");
    return false;
}

void Vending_Machine::reduce_quantity(const string product)
{
    this->quantity[product]--;
}