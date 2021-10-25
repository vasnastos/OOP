#include "sqlite3.h"
#include "cargo.hpp"
#include <iostream>
#include <vector>

class database
{
    private:
        sqlite3 *db;
        std::string name;
    public:
        database(std::string n);
        ~database() {}
        std::string get_database_name()const;
        void insert_cargo(int i,std::string destination,std::string description,double w,bool f);
        std::vector <Cargo> get_cargos();
        void delete_cargo(int id);
        bool cargo_exists(int id);
        Cargo search_by_id(int id);
};