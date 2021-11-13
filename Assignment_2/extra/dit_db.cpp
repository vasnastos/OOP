#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../course.hpp"
#include <sqlite3.h>


using namespace std;

namespace dit_database {
    string database_name="ditc.db";

    void create_db()
    {
        sqlite3 *db;
        int res=sqlite3_open(database_name.c_str(),&db);
        if(res!=SQLITE_OK)
        {
            cerr<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);
            return;
        }
        else
        cout<<"Database "<<database_name<<" created"<<endl;
        sqlite3_close(db);
    }

    void create_table()
    {
        sqlite3 *db=nullptr;
        char *errmsg;
        string sql="CREATE TABLE IF NOT EXISTS COURSE(id TEXT PRIMARY KEY,semester INTEGER,title TEXT,credits INTEGER)";
        int res=sqlite3_open(database_name.c_str(),&db);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);
            return;
        }
        res=sqlite3_exec(db,sql.c_str(),nullptr,nullptr,&errmsg);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
        }
        else
        {
            cout<<"Table Course(id,semester,title,credits)"<<endl;
        }
        sqlite3_free(errmsg);
        sqlite3_close(db);
    }

    void init_database()
    {
        create_db();
        create_table();
    }

    void insert_course(string code,int semester,string title,int credits)
    {
        sqlite3 *db;
        sqlite3_stmt *q;
        string sql="INSERT INTO COURSE(id,semester,title,credits) VALUES(?,?,?,?)";
        int res=sqlite3_open(database_name.c_str(),&db);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);
            return;
        }
        res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);
            return;
        }
        sqlite3_bind_text(q,1,code.c_str(),-1,SQLITE_STATIC);
        sqlite3_bind_int(q,2,semester);
        sqlite3_bind_text(q,3,title.c_str(),-1,SQLITE_STATIC);
        sqlite3_bind_int(q,4,credits);
        if(sqlite3_step(q)==SQLITE_ROW)
        {
            cout<<">>>1 Row effected("<<code<<","<<semester<<","<<title<<","<<credits<<")"<<endl;
        }
        sqlite3_close(db);
    }

    vector <Course> get_courses()
    {
        sqlite3 *db;
        sqlite3_stmt *q;
        string sql="SELECT * FROM COURSE";
        int res=sqlite3_open(database_name.c_str(),&db);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);
            return vector <Course>();
        }
        res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
        if(res!=SQLITE_OK)
        {
            cout<<sqlite3_errmsg(db)<<endl;
            sqlite3_close(db);          
            return vector<Course>();
        }
        vector <Course> courses;
        while(sqlite3_step(q)==SQLITE_ROW)
        {
            string id=(const char *)sqlite3_column_text(q,0);
            int semester=sqlite3_column_int(q,1);
            string title=(const char *)sqlite3_column_text(q,2);
            int credits=sqlite3_column_int(q,3);
            courses.emplace_back(Course(id,semester,title,credits));
        }
        sqlite3_close(db);
        return courses;
    }
    void import_file_to_database(string filename)
    {
        dit_database::init_database();
        setlocale(LC_CTYPE,".OPC");
        fstream fs(filename,ios::in);
        locale a_loc("");
        fs.imbue(a_loc);
        if(!fs.is_open())
        {
            cerr<<"Error on file opening"<<endl;
            return;
        }
        string line,word;
        vector <string> data;
        bool header_line=true;
        while(getline(fs,line))
        {
            if(line.length()==0) continue;
            if(header_line)
            {
                header_line=false;
                continue;
            }
            stringstream ss(line);
            data.clear();
            while(getline(ss,word,','))
            {
                data.emplace_back(word);
            }
            if(data.size()!=4) continue;
            dit_database::insert_course(data[0],stoi(data[1]),data[2],stoi(data[3]));
        }
    }
}

int main()
{
    string filename="../dit_uoi_course.txt";
    dit_database::import_file_to_database(filename);
    vector <Course> courses=dit_database::get_courses();
    for(auto &course:courses)
    {
        cout<<course<<endl;
    }
    return EXIT_SUCCESS;
}