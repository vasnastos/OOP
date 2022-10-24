#include "sqlite3.h"
#include <iostream>

int main(int argc,char *argv[])
{
    sqlite3 *db;
    int res=sqlite3_open("test_db.db",&db);
    if(res==SQLITE_OK)
    {
        std::cout<<"Database test_db.db created at memory position"<<db<<std::endl;
    }
    else
    {
        std::cout<<"Failed at create of database test_db.db"<<std::endl;
    }
    sqlite3_close(db);
    return EXIT_SUCCESS;
}

// Linux
// g++ sqlite_connectivity.cpp -l sqlite3 -o connectivity
// ./connectivity

// Windows