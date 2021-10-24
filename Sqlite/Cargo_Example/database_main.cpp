#include "database.hpp"
#include  "tabulate/table.hpp"


using namespace tabulate;
// Tabulate obtained from:https://github.com/p-ranav/tabulate

namespace cli{
    void print_record(std::vector <Cargo> &cargos)
    {
        Table tcargos;
        tcargos.add_row({"ID","DESTINATION","DESCRIPTION","WEIGHT","FRAGILE"});
        for(auto &cargo:cargos)
        {
           tcargos.add_row({std::to_string(cargo.get_id()),cargo.get_destination(),cargo.get_description(),std::to_string(cargo.get_weight()),bool2String(cargo.get_fragile())});
        }

    }

    int menu()
    {
        int op;
        std::cout<<"1.Insert a record"<<std::endl;
        std::cout<<"2.Delete a record"<<std::endl;
        std::cout<<"3.Update a record"<<std::endl;
        std::cout<<"4.Show database records"<<std::endl;
        std::cout<<"5.Export database to a file"<<std::endl;
        std::cout<<"6.Import csv records to the database"<<std::endl;
        std::cout<<"7.Exit"<<std::endl;
        std::cout<<"Select an option:"<<std::endl;
        std::cin>>op;
        return op;
    }
}
int main()
{
    const std::string db_name="cargo_database.db";
    database db(db_name);
    int option;
    int id;
    std::string destination,description;
    double weight;
    int is_fragile;
    while(true)
    {
        option=cli::menu();
        switch(option)
        {
            case 1:
                std::cout<<"Give produvt id:";
                std::cin>>id;
                std::cout<<std::endl<<std::endl<<"Give product destination:";
                std::cin>>destination;
                std::cout<<std::endl<<std::endl<<"Give product description:";
                std::cin>>description;
                std::cout<<std::endl<<std::endl<<"Give product weight:";
                std::cin>>weight;
                std::cout<<std::endl<<std::endl<<"Give product fragilation(0(yes)/1(no)):";
                std::cin>>is_fragile;
                db.insert_cargo(id,destination,description,weight,bool(is_fragile));
                std::cout<<"Record inserted!!!"<<std::endl;
            case 2:
                std::cout<<std::endl<<"Give record id:";
                std::cin>>id;
                db.delete_cargo(id);
        }
    }
}