#include "database.hpp"
#include  "tabulate/table.hpp"
#include <fstream>


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

    std::string open_file_dialog()
    {
        std::string fname;
        char filename[1024];
        FILE *f=popen("zenity --file-selection","r");
        fgets(filename,1024,f);
        fname=std::string(filename);
        return fname;
    }

    int menu()
    {
        int op;
        std::cout<<"1.Insert a record"<<std::endl;
        std::cout<<"2.Delete a record"<<std::endl;
        std::cout<<"3.Show database records"<<std::endl;
        std::cout<<"4.Export database to a file"<<std::endl;
        std::cout<<"5.Import csv records to the database"<<std::endl;
        std::cout<<"6.Exit"<<std::endl;
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
    bool exit_flag;
    std::string filename;
    std::fstream fs;
    std::string line,word;
    std::vector <std::string> data;
    std::vector <Cargo> cargos;
    while(true)
    {
        option=cli::menu();
        exit_flag=false;
        switch(option)
        {
            case 1:
                std::cout<<"Give product id:";
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
                break;
            case 2:
                std::cout<<std::endl<<"Give record id:";
                std::cin>>id;
                db.delete_cargo(id);
                std::cout<<"record with id:"<<id<<" deleted"<<std::endl;
                break;
            case 3:
                cargos=db.get_cargos();
                cli::print_record(cargos);
                std::cout<<std::endl;
                break;
            case 4:
                fs=std::fstream(db.get_database_name(),std::ios::out);
                cargos=db.get_cargos();
                // fs.open(db.get_database_name(),std::ios::out);
                for(auto &cargo:cargos)
                {
                    fs<<std::string(cargo)<<std::endl;
                }
                fs.close();
                break;
            case 5:
                filename=cli::open_file_dialog();
                fs=std::fstream(filename,std::ios::in);
                while(std::getline(fs,line))
                {
                    std::stringstream ss(line);
                    data.clear();
                    while(std::getline(ss,word,','))
                    {
                        data.emplace_back(word);
                    }   
                    if(data.size()!=5) continue;
                    db.insert_cargo(std::stoi(data[0]),data[1],data[2],std::stod(data[3]),bool(std::stoi(data[4])));
                }
                fs.close();
                break;
            case 6:
             exit_flag=true;
        }
        if(exit_flag) break;
    }
    return EXIT_SUCCESS;
}