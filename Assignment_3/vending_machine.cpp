#include "vending_machine.hpp"
#ifdef _WIN32
#include <windows.h>
#endif
#include <cassert>

// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d   %X", &tstruct);

    return buf;
}


VendingMachine::VendingMachine(vector <double> &available_coin_types):paying_amount(0.0)
{
    this->products.push_back(Product("Coffee",1.5,10));
    this->products.push_back(Product("Chocolate",2.1,10));
    this->products.push_back(Product("Milk",0.3,20));  
    for(int i=0,t=available_coin_types.size();i<t;i++)
    {
        this->coins.insert(make_pair(i+1,available_coin_types.at(i)));
        this->coin_buffer[available_coin_types.at(i)]=0;
    }
}

void VendingMachine::reset_coin_buffer()
{
    for(auto &cb:this->coin_buffer)
    {
        cb.second=0;
    }
}


void VendingMachine::reset_payout()
{
    this->paying_amount=0.0;
}

void VendingMachine::payout(string product,bool has_milk)
{
    this->reset_coin_buffer();
    this->reset_payout();
    vector <Product>::iterator pr_itr=find_if(this->products.begin(),this->products.end(),[&](const Product &p) {return p.get_title()==product;});;
    vector <Product>::iterator milk=this->products.end();
    if(has_milk)
    {
        milk=find_if(this->products.begin(),this->products.end(),[&](const Product &p) {return p.get_title()=="Milk";});
    }
    bool cancel_order=false;

    if(pr_itr->get_quantity()==0)
    {
        cerr<<"Το προιόν:"<<pr_itr->get_title()<<" δεν είναι διαθέσιμο"<<endl;
        cancel_order=true;
    }
    if(has_milk)
    {
        if(milk->get_quantity()==0)
        {
            cerr<<"Το προιόν:"<<milk->get_title()<<" δεν είναι διαθέσιμο"<<endl;
            cancel_order=true;
        }
    }
    if(cancel_order)
    {
        cerr<<"Παρακαλώ επιλέξτε ένα διαφορετικό προιόν η ανεφοδιάστε την μηχανή"<<endl;
        system("pause");
        return;
    }

    this->paying_amount=pr_itr->get_price();
    if(has_milk)
    {
        this->paying_amount+=milk->get_price();
    }
    double pay_view=0.0;
    while(pay_view<this->paying_amount)
    {
        system("cls");
        #ifdef _WIN32
        SetConsoleOutputCP(65001);
        #endif
        int money_choice;
        cout<<"1. 10 λεπτά"<<endl;
        cout<<"2. 20 λεπτά"<<endl;
        cout<<"3. 50 λεπτά"<<endl;
        cout<<"4. 1 ευρώ"<<endl;
        cout<<"5. 2 ευρώ"<<endl;
        cout<<"6. 5 ευρώ"<<endl;
        cout<<"7. 10 ευρώ"<<endl;
        cout<<"-1 Ακύρωση Παραγγελίας"<<endl;
        cout<<"Διάλεξε ποσό:";
        cin>>money_choice;
        if(money_choice==-1)
        {
            cancel_order=true;
            break;
        }
        pay_view+=this->coins[money_choice];
        this->coin_buffer[this->coins[money_choice]]++;
        cout<<endl<<"Υπολειπόμενο ποσό:"<<(this->paying_amount-pay_view>0?this->paying_amount-pay_view:0)<<endl;
        system("pause");
    }
    if(cancel_order)
    {
        cout<<endl;
        cout<<"Ακύρωση παραγγελίας"<<endl;
        cout<<"Προιόν:"<<pr_itr->getname()<<(has_milk?" με Γάλα":"")<<endl;
        cout<<"Επιστροφή στον Χρήστη"<<endl;
        cout<<"============"<<endl;
        for(auto &cb:this->coin_buffer)
        {
            if(cb.second!=0)
            cout<<"Νόμισμα:"<<cb.first<<"  Ποσότητα:"<<cb.second<<endl;
        }
        system("pause");
    }
    else{
        pr_itr->reduce_quantity();
        if(has_milk)
        {
            milk->reduce_quantity();
        }
        this->machine_memory.push_back("ΠΑΡΡΑΓΕΛΙΑ:"+currentDateTime()+"\nΠΡΟΙΟΝ:"+pr_itr->getname()+(has_milk?"με Γάλα":"")+"\n"+"ΚΟΣΤΟΣ:"+to_string(this->paying_amount)+"\nΠΟΣΟ ΠΛΗΡΩΜΗΣ:"+to_string(pay_view)+"\nΡΕΣΤΑ:"+to_string(pay_view-this->paying_amount));
        system("cls");
        cout<<endl<<"=== ΑΠΟΔΕΙΞΗ ==="<<endl;
        cout<<pr_itr->description()<<endl;
        if(has_milk)
        cout<<milk->description()<<endl;
        cout<<"================"<<endl;
        cout<<"ΣΥΟΝΟΛΙΚΟ ΠΟΣΟ:"<<this->paying_amount<<endl;
        cout<<"ΠΟΣΟ ΠΟΥ ΔΙΑΤΕΘΗΚΕ:"<<pay_view<<endl;
        cout<<"ΡΕΣΤΑ:"<<pay_view-this->paying_amount<<endl;
        system("pause");
    }
}

void VendingMachine::refill()
{
    this->quantity["coffee"]=10;
    this->quantity["chocolate"]=10;
    this->quantity["milk"]=20;
}

void VendingMachine::change(double pay_amount)
{
}

std::ostream &operator<<(ostream &os,const VendingMachine &vm)
{
    return os;
}