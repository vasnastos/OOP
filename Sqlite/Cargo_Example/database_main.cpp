#include "database.hpp"

int main()
{
    const std::string db_name="cargo_database.db";
    database db(db_name);
    
    std::vector <Cargo> cargos{
        Cargo{1,"ATHENS","IPHONE CAREFULLY STACKED",4,true},
        Cargo{2,"PARIS","MULTIPLE CLOTHES AND HOUSE OBJECTS",10,false},
        Cargo{3,"MANCHESTER","LAGGAGES",60,false}
    };

    for(auto &cargo:cargos)
    {
        // db.insert_cargo)
    }
}