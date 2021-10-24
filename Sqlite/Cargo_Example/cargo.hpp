#include <iostream>
#include <vector>

// ---------- Cargo  --------------| 
//     -id:int                     |
//     -destination:String         |
//     -description:String         |
//     -weight:double              |
//     -fragile:bool               |
// ..............................  |
//     + set_weight(w:double):void |
//     + get_weight():double       |
//     + make_safe():bool          |
//     + show():void               |
//---------------------------------|

class Cargo
{
    public:
        Cargo(int cid,std::string c_destination,std::string c_description,double c_weight,bool c_fragile);
        Cargo();
        ~Cargo() {}
        void set_weight(double w);
        void set_destination(std::string c_destination);
        void set_description(std::string c_description);
        int get_id()const;
        std::string get_destination()const;
        std::string get_description()const;
        double get_weight()const;
        bool get_fragile()const;
        double get_weight()const;
        bool make_safe();
        void show();
        std::vector <std::string> to_table_view();
        friend std::ostream &operator<<(std::ostream &os,const Cargo &c);

    private:
        int id;
        std::string destination;
        std::string description;
        double weight;
        bool fragile;

};

std::string bool2String(bool val);