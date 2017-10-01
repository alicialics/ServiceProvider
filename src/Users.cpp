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
    ID      INTEGER PRIMARY KEY AUTOINCREMENT,\
    FIRST   TEXT,\
    LAST    TEXT,\
    AGE     INT)" ;
    
    sqlite3_exec(db, create.c_str(), 0, 0, 0);
}

void Users::addUser(string first, string last, int age, sqlite3* db){
    stringstream ss;
    ss << "INSERT INTO USERS (FIRST, LAST, AGE) VALUES('" <<  first << "','" << last << "'," << age << ");";
    cout << ss.str();
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
    
}
