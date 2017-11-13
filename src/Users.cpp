#include <sqlite3.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


#include "Users.h"



Users::Users(string ff, string ll, int aa)
:first(ff),last(ll),age(aa)
{
    
}

string Users::getFirst() const{
    return first;
}
string Users::getLast() const{
    return last;
}
int Users::getAge() const{
    return age;
}

void Users::userTable(sqlite3* db){
    string create = "CREATE TABLE IF NOT EXISTS USERS(\
    ID      INTEGER PRIMARY KEY,\
    FIRST   TEXT,\
    LAST    TEXT,\
    AGE     INT)" ;
    
    sqlite3_exec(db, create.c_str(), 0, 0, 0);
}

void Users::addUser(sqlite3* db){
    stringstream ss;
    ss << "INSERT INTO USERS (First, Last, Age) VALUES('" << first << "','" << last << "'," << age << ");";
    cout << ss.str() << endl;
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
    id = sqlite3_last_insert_rowid(db);
    
}
