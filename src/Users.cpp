#include <sqlite3.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


#include "Users.h"



Users::Users(string _first, string _last, int _age)
:id(0),first(_first),last(_last),age(_age)
{
    
}

void Users::userTable(sqlite3* db){
    string create = "CREATE TABLE IF NOT EXISTS Users(\
    Id      INTEGER PRIMARY KEY,\
    First   TEXT,\
    Last    TEXT,\
    Age     INT)" ;
    
    sqlite3_exec(db, create.c_str(), 0, 0, 0);
}

void Users::save(sqlite3* db){
    stringstream ss;
    if(id == 0){
        ss << "INSERT INTO Users (First, Last, Age) VALUES('" << first << "','" << last << "'," << age << ");";
        sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
        id = sqlite3_last_insert_rowid(db);
    }else{
        ss << "UPDATE Users SET First = ' " << first << " ' ," << "Last = ' " << last << " ' , Age = " << age << " WHERE Id = " << id << ";" ;
    }
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
    
    
}
