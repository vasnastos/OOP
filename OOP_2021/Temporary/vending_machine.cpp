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


VendingMachine::VendingMachine()
{
    // Εισαγωγή τιμών προιόντων
    this->products["coffee"]=1.5;
    this->products["chocolate"]=2.1;
    this->products["milk"]=0.3;

    // Εισαγώγη ποσοτήτων
    this->quantity["coffee"]=10;
    this->quantity["chocolate"]=10;
    this->quantity["milk"]=20;

    // Νομίσματα αυτοματου πωλητή
    this->coin_buffer[0.1]=0;
    this->coin_buffer[0.2]=0;
    this->coin_buffer[0.5]=0;
    this->coin_buffer[1.0]=0;
    this->coin_buffer[2.0]=0;
    this->coin_buffer[5.0]=0;
    this->coin_buffer[10.0]=0;
}

VendingMachine::~VendingMachine() {}

void VendingMachine::payout(string product,bool has_milk)
{
    this->temporary_value=0;
    if(this->quantity[product]==0)
    {
        cout<<"Η ποσοτητα του προιόντος:"<<product<<" δεν επαρκεί για την παρασκευή του"<<endl;
        return;
    }
    if(has_milk)
    {
        if(this->quantity["milk"]==0)
        {
            cout<<"Η ποσοτητα του προιόντος:milk δεν επαρκεί για την παρασκευή του"<<endl;
            return;
        }
    }
    // product chocolate-->total_value=2.1+0.3
    this->total_value=this->products[product];
    if(has_milk)
    {
        this->total_value+=this->products["milk"];
    }
    bool cancel;
    while(this->temporary_value<this->total_value)
    {
        // Ακύρωση παραγγελίας
        cancel=this->coin_insert();
        if(cancel)
        {
            return;
        }
    }

    // Μείωση ποσότητας προιόντος
    this->quantity[product]--;
    if(has_milk)
    {
        this->quantity["milk"]--;
    }

    cout<<"\n=== Απόδειξη ==="<<endl;
    cout<<"Ημερομηνία:"<<currentDateTime()<<endl;
    cout<<"Προιόν:"<<product<<endl;
    cout<<"Συνολικό  κόστος:"<<this->total_value<<endl;
    cout<<"Χρήματα χρήστη:"<<this->temporary_value<<endl;
    cout<<"Ρέστα:"<<this->temporary_value-this->total_value<<endl;
    system("pause");
}

bool VendingMachine::coin_insert()
{
    int coin_choice;
    cout<<"\n=== Εισαγωγή νομίσματος ==="<<endl;
    int count=0;
    for(auto &coin:this->coin_buffer)
    {
        cout<<" "<<count<<". "<<coin.first<<endl;
        count++;
    }
    cout<<"-1. Ακύρωση παραγγελίας"<<endl;
    cout<<"Επιλογή νομίσματος:";
    cin>>coin_choice;
    switch(coin_choice)
    {
        case 0:
            this->temporary_value+=0.1;
            this->coin_buffer[0.1]++;
            cout<<"Νόμισμα:10 λεπτά"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 1:
            this->temporary_value+=0.2;
            this->coin_buffer[0.2]++;
            cout<<"Νόμισμα:20 λεπτά"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 2:
            this->temporary_value+=0.5;
            this->coin_buffer[0.5]++;
            cout<<"Νόμισμα:50 λεπτά"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 3:
            this->temporary_value+=1.0;
            this->coin_buffer[1.0]++;
            cout<<"Νόμισμα:1 ευρώ"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 4:
            this->temporary_value+=2.0;
            this->coin_buffer[2.0]++;
            cout<<"Νόμισμα:2 ευρώ"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 5:
            this->temporary_value+=5.0;
            this->coin_buffer[5.0]++;
            cout<<"Νόμισμα:5 ευρώ"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case 6:
            this->temporary_value+=10.0;
            this->coin_buffer[10.0]++;
            cout<<"Νόμισμα:10 ευρώ"<<endl;
            cout<<"Υπόλοιπο:"<<this->total_value-this->temporary_value<<endl<<endl;
            break;
        case -1:
            cout<<"\n"<<currentDateTime()<<"-Ακύρωση παραγγελίας"<<endl;
            cout<<"=== Χρήματα Χρήστη ==="<<endl;
            for(auto &coin:this->coin_buffer)
            {
                cout<<"Νόμισμα:"<<coin.first<<"\tΠλήθος Νομίσματος:"<<coin.second<<endl;
            }
            system("pause");
            return true;
            break;
        default:
            cout<<"Λάθος επιλογή"<<endl;
    }
    return false;
}