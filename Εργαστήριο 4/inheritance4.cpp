#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Computer
{
    protected:
        string name;
        int ram;
        int storage;
        bool has_keyboard;
        double price;
    public:
        Computer() {}
        Computer(string _name,int _ram,int _storage,bool _keyboard,double _price):name(_name),ram(_ram),storage(_storage),has_keyboard(_keyboard),price(_price) {}
        ~Computer() {}

        void increaseRAM(int n)
        {
            this->ram+=n;
        }

        void increaseStorage(int x)
        {
            this->storage+=x;
        }

        int get_ram()
        {
            return this->ram;
        }

        int get_storage()
        {
            return this->storage;
        }

        bool has_Keyboard()
        {
            return this->has_keyboard;
        }

        double get_price()
        {
            return this->price;
        }

        string to_string()
        {
            return std::to_string(this->ram)+","+std::to_string(this->storage)+","+(this->has_keyboard?"KEYBOARD":"NO KEYBOARD")+","+std::to_string(this->price);
        }

};

class Laptop:public Computer
{
    string processor;
    string gpu;
    string screen;
    string os;


    public:
        Laptop(string processor,string gpu,string screen,string os,string _name,int _ram,int _storage,bool _has_keyboard,double _price):processor(processor),gpu(gpu),screen(screen),os(os),Computer(_name,_ram,_storage,_has_keyboard,_price) {}
        ~Laptop() {}

        string get_processor()const
        {
            return this->processor;
        }

        string get_gpu()const 
        {
            return this->gpu;
        }

        string to_string()
        {
            return Computer::to_string()+","+this->processor+","+this->gpu+","+this->screen+","+this->os;
        }
};

class Phone:public Computer
{
    string camera;
    string sim;
    double weight;
    
    public:
        Phone(string _camera,string _sim,double _weight,string _name,int _ram, int _storage, bool _has_keyboard,double _price):camera(_camera),sim(_sim),weight(_weight),Computer(_name,_ram,_storage,_has_keyboard,_price) {}
        ~Phone() {}

        double get_price()const {return this->price;}
        string get_camera()const {return this->camera;}
        double get_weight()const {return this->weight;}

        string to_string()
        {
            return Computer::to_string()+","+this->camera+","+this->sim+","+std::to_string(this->weight);
        }
};

int main()
{
    const int size=5;
    Computer **computers=new Computer*[size];
    computers[0]=new Laptop("AMD ATHLON 315U0U ZEN","AMD RADEON GRAPHICS","15,6\" FULL HD NO IPS","windows","HP 255 G8",4,128,true,291.80);
    computers[1]=new Laptop("Apple M1 JASPER LAKE","APPLE M1","13,3\" IPS RETINA DISPLAY 60HZ","macOS","Apple MacBook Air",256,8,true,1149.99);
    computers[2]=new Phone("HDR 48MP","Dual",200.5,"OnePlus 10 Pro",12,256,false,875.45);
    computers[3]=new Laptop("Intel core i5 Ice lake(10th)","Intel UHD Graphics","14\" FULL HD 2K 60HZ","no os","Lenovo V14-IIL",8,256,true,446.38);
    computers[4]=new Phone("12MP","Dual",174,"Apple iphone 13",128,4,false,869.00);

    for(int i=0;i<size;i++)
    {
        cout<<computers[i]->to_string()<<endl;
    }
    // Sort table
    cout<<endl<<"Sorted Products(By price)"<<endl;
    sort(computers,computers+size,[](Computer *coumputer1,Computer *computer2) {return coumputer1->get_price()<computer2->get_price();});
    for(int i=0;i<size;i++)
    {
        cout<<computers[i]->to_string()<<endl;
    }

    for(int i=0;i<size;i++)
    {
        delete computers[i];
    }
    delete[] computers;
    return 0;
}