#include "sqlite3.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

struct lesson
{
    int lid;
    std::string name;
    
    lesson(int i,std::string n):lid(i),name(n) {}
    
    operator std::string()const{
        std::stringstream ss;
        ss<<lid<<"."<<name;
        return ss.str();
    }

};

class database
{
    private:
        sqlite3 *db;
        std::string name;
    public:
        database(std::string db_name):name(db_name)
        {
            int res=sqlite3_open(db_name.c_str(),&this->db);
            if(res==SQLITE_ERROR)
            {
                throw "SQLITE DATABASE DOES NOT CONFIGURE WELL";
            }
            sqlite3_close(this->db);
        }

        ~database() {}  

        void create_table()
        {
            sqlite3_open(this->name.c_str(),&this->db);
            char **errmsg;
            int res=sqlite3_open(this->name.c_str(),&this->db);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_close(this->db);
                throw "SQLITE TABLE DOES NOT CREATED PROPERLY";
            }
            std::string query="create table if not exists Lesson(id varchar(10),name text)";
            res=sqlite3_exec(this->db,query.c_str(),nullptr,nullptr,errmsg);
            if(res==SQLITE_ERROR)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_free(errmsg);
            }
            sqlite3_close(this->db);
        }

        void insert_lesson(int lid,std::string lessonname)
        {
            int res=sqlite3_open(this->name.c_str(),&this->db);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_close(this->db);
                throw "DATABASE DOES NOT OPEN";
                throw "INSERTION FAILED--("+std::to_string(lid)+","+lessonname+")";
            }
            std::string sql="INSERT INTO Lesson(id,name) VALUES(?,?);";
            sqlite3_stmt *qr=nullptr;
            res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&qr,nullptr);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db);
                sqlite3_close(this->db);
                sqlite3_errmsg(this->db);
                return;
            }
            sqlite3_bind_text(qr,1,std::to_string(lid).c_str(),-1,SQLITE_STATIC);
            sqlite3_bind_text(qr,2,lessonname.c_str(),-1,SQLITE_STATIC);
            int done_step=sqlite3_step(qr);
            if(done_step!=SQLITE_DONE)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
            }
            else
            std::cout<<"Inserted:"<<lid<<"-"<<lessonname<<std::endl;
            sqlite3_close(this->db);
            
        }

        std::vector <lesson> get_records()
        {
            std::string sql="SELECT * FROM Lesson";
            sqlite3_stmt *q=nullptr;
            int res=sqlite3_open(this->name.c_str(),&this->db);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_close(this->db);
                return std::vector <lesson>();
            }
            res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,NULL);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_free(this->db);
                sqlite3_close(this->db);
                return std::vector <lesson>();
            }
            std::vector <lesson> lessons;
            while(sqlite3_step(q)==SQLITE_ROW)
            {
                std::string id=((const char *)sqlite3_column_text(q,0));
                std::string lname=((const char *)sqlite3_column_text(q,1));
                int lid=std::stoi(id);
                lessons.emplace_back(lesson(lid,lname));             
            }
            sqlite3_close(this->db);
            return lessons;    
        }

        // Delete by id
        void delete_record(int id)
        {
            sqlite3_stmt *q=nullptr;
            std::string sql="DELETE FROM LESSON WHERE id=?";
            int res=sqlite3_open(this->name.c_str(),&this->db);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_close(this->db);
                throw "DATABASE DID NOT OPEN";
            }
            res=sqlite3_prepare_v2(this->db,sql.c_str(),-1,&q,nullptr);
            if(res!=SQLITE_OK)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
                sqlite3_close(this->db);
                return;
            }
            std::string lid=std::to_string(id);
            sqlite3_bind_text(q,1,lid.c_str(),-1,nullptr);
            res=sqlite3_step(q);
            if(res==SQLITE_DONE)
            {
                std::cout<<"Lesson with id:"<<id<<" erased from the database"<<std::endl;
            }
            else if(res==SQLITE_ERROR)
            {
                std::cout<<sqlite3_errmsg(this->db)<<std::endl;
            }
            sqlite3_close(this->db);
        }

        // Update by id
        void update_record(int id,std::string new_name)
        {
            sqlite3_stmt *q;
            std::string sql="UPDATE Lesson SET name=? WHERE id=?;";
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
            std::string lid=std::to_string(id);
            sqlite3_bind_text(q,1,new_name.c_str(),-1,SQLITE_STATIC);
            sqlite3_bind_text(q,2,lid.c_str(),-1,SQLITE_STATIC);
            res=sqlite3_step(q);
            if(res==SQLITE_ROW)
            {
                std::cout<<"Update Record with id:"<<id<<std::endl;
            }
            sqlite3_close(this->db);
        }
};

int main()
{
    std::map <int,std::string> records{
        {1,"LESSON_1"},
        {2,"LESSON_2"},
        {3,"LESSON_3"},
        {4,"LESSON_4"},
        {5,"LESSON_5"},
        {6,"LESSON_6"},
        {7,"LESSON_7"},
        {8,"LESSON_8"},
        {9,"LESSON_9"},
        {10,"LESSON_10"},
        {11,"Lesson_11"},
        {12,"Lesson_12"}
    };
    database *a_db;
    std::string db_name="lesson_database.db";
    a_db=new database(db_name);
    
    // Create table
    a_db->create_table();
    
    // Insert Data
    for(auto &record:records)
    {
        a_db->insert_lesson(record.first,record.second);
    }

    // Export data
    std::vector <lesson> lessons=a_db->get_records();
    for(auto &record:lessons)
    {
        std::cout<<std::string(record)<<std::endl;
    }

    // Update data
    int id;
    std::cout<<"Give id:";
    std::cin>>id;
    std::string name;
    std::cout<<"Give new name:";
    std::cin>>name;

    std::cout<<"Update id with name:"<<name<<std::endl;
    a_db->update_record(id,name);

    std::cout<<"Give id of lesson you want to delete:";
    std::cin>>id;
    std::cout<<"Lesson with id:"<<id<<" deleted"<<std::endl;
    a_db->delete_record(id);

    lessons=a_db->get_records();
    for(auto &lesson:lessons)
    {
        std::cout<<std::string(lesson)<<std::endl;
    }

    delete a_db;
    return EXIT_SUCCESS;
}