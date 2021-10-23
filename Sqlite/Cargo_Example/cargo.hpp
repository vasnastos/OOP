#include <iostream>

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
        double get_weight()const;
        bool make_safe();
        void show();

    private:
        int id;
        std::string destination;
        std::string description;
        double weight;
        bool fragile;

};