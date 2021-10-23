#include "database.hpp"

database::database(std::string n):name(n)
{
    char **errmsg;
    int res=sqlite3_open(this->name.c_str(),&this->db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(this->db)<<std::endl;
        sqlite3_free(errmsg);
        sqlite3_close(this->db);
    }
    std::string sql="CREATE TABLE IF NOT EXISTS CARGO(ID INTEGER,DESTINATION TEXT,DESCRIPTION TEXT,WEIGHT REAL,FRAGILE INTEGER)";
    res=sqlite3_exec(this->db,sql.c_str(),nullptr,nullptr,errmsg);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(this->db)<<std::endl;
        sqlite3_close(this->db);
        return;
    }
    sqlite3_close(this->db);
}

void database::insert_cargo(int i,std::string destination,std::string description,double w,bool f)
{
    std::string sql="INSERT INTO CARGO(ID,DESTINATION,DESCRIPTION,WEIGHT,FRAGILE) VALUES(?,?,?,?,?)";
    sqlite3_stmt *q;
    int res=sqlite3_open(this->name.c_str(),&this->db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(this->db)<<std::endl;
        sqlite3_close(this->db);
        return;
    }
    res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(this->db)<<std::endl;
        sqlite3_close(this->db);
        return;
    }
    sqlite3_bind_int(q,1,i);
    sqlite3_bind_text(q,2,destination.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,3,description.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_double(q,4,w);
    sqlite3_bind_int(q,5,int(f));
    res=sqlite3_step(q);
    if(res==SQLITE_ROW)
    {
        std::cout<<std::boolalpha;
        std::cout<<"Registry:"<<i<<" "<<destination<<" "<<description<<" "<<w<<" "<<f<<" inserted into the database"<<std::endl;
    }
    else
    {
        std::cout<<sqlite3_errmsg(this->db)<<std::endl;
    }
    sqlite3_close(this->db);
}

bool database::cargo_exists(int id)
{
    std::string sql="SELECT * FROM CARGO WHERE ID=?";
    sqlite3_stmt *q=nullptr;
    int res=sqlite3_open(this->name.c_str(),&this->db);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_close(this->db);
        throw message;
    }
    res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_close(this->db);
        throw message;
    }
    sqlite3_bind_int(q,1,id);
    res=sqlite3_step(q);
    bool result=false;
    if(res==SQLITE_ROW)
    {
        result=true;
    }
    sqlite3_close(this->db);
    return result;
}


std::vector <Cargo> database::get_cargos()
{
    std::vector <Cargo> cargos;
    std::string sql="SELECT * FROM CARGO";
    sqlite3_stmt *q=nullptr;
    int res=sqlite3_open(this->name.c_str(),&this->db);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_close(this->db);
        throw message;
    }
    res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_errmsg(this->db);
        throw message;
    }
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        int id=sqlite3_column_int(q,0);
        std::string destination=(const char *)sqlite3_column_text(q,1);
        std::string description=(const char *)sqlite3_column_text(q,2);
        double weight=sqlite3_column_double(q,3);
        bool fragile=bool(sqlite3_column_int(q,4));
        cargos.emplace_back(Cargo(id,destination,description,weight,fragile));
    }
    sqlite3_close(this->db);
    return cargos;
}

Cargo database::search_by_id(int id)
{
    std::string sql="SELECT * FROM CARGO WHERE ID=?";
    sqlite3_stmt *q;
    int res=sqlite3_open(this->name.c_str(),&this->db);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_close(this->db);
        throw message;
    }
    res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::string message=sqlite3_errmsg(this->db);
        sqlite3_errmsg(this->db);
        throw message;
    }
    sqlite3_bind_int(q,1,id);
    if(sqlite3_step(q)==SQLITE_ROW)
    {
        int id=sqlite3_column_int(q,0);
        std::string destanation=(const char *)sqlite3_column_text(q,1);
        std::string description=(const char *)sqlite3_column_text(q,2);
        double weight=sqlite3_column_double(q,3);
        bool fragile=bool(sqlite3_column_int(q,4));
        sqlite3_close(this->db);
        return Cargo(id,destanation,description,weight,fragile);
    }
    sqlite3_close(this->db);
    return Cargo();
}