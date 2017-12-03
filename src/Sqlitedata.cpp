

#include <sstream>
#include <iostream>
using namespace std;
//#include <cstring>
#include "Sqlitedata.h"
#include "Savedata.h"
#include "Users.h"

#include <stdio.h>
#include <sqlite3.h>

Sqlitedata::Sqlitedata(){
    int rc;
    
    string fileName = "mydata.db";
    rc = sqlite3_open(fileName.c_str(),&db);//pass db by reference db points to "mydata.db" now
    if(rc){
        cerr << "Can't open database!\n";
    }else{
        cout << "Open database successfully.\n";
    }
    
}

void Sqlitedata::createTable(string dataTitle, const map<string, string>& toCreate){
    
    /* Create SQL statement */
    stringstream ss;
    ss << "CREATE TABLE IF NOT EXISTS ";
    ss << dataTitle << " (Id INTEGER PRIMARY KEY";
    for(auto i = toCreate.begin(); i != toCreate.end(); i++){
        ss << ", " << i->first << " " << i->second;
    }
    ss << ")" ;
    /* Execute SQL statement */
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0); //create a table for data to store in private database
    //cout << ss.str() << endl;
}

vector<Savedata*> Sqlitedata::loadData(){
    //callback provides a way to obtain results from SELECT statements
    //sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
    vector<Savedata*> dataPrev;
    
    char* sql = "SELECT * from Users";
    sqlite3_exec(db, sql, userCallback, (void*)&dataPrev, 0);
    
    sql = "SELECT * from AutomotiveService";
    sqlite3_exec(db, sql, userCallback, (void*)&dataPrev, 0);
    
    
    createTable(Users::getType(), Users::toCreate());
    
    //Users* user = new Users("zhuo", "li", "gmail");//random load one, later will load from database
    //userPrev.push_back(user);
    return dataPrev;
}

void Sqlitedata::saveData(Savedata* data){ //pass the object to save
    
    /* Create SQL statement */
    stringstream ss;
    ss << "REPLACE INTO ";
    ss << data->dataTitle() << " (";
    map<string, string> dataCopy = data->toSave();
    if(data->getId()){
        dataCopy["Id"] = to_string(data->getId());
    }
    
    for(auto i = dataCopy.begin(); i != dataCopy.end(); i++){
        if(i != dataCopy.begin()){
            ss << ",";
        }
        ss << i->first;
    }
    ss << ") VALUES(";
    for(auto i = dataCopy.begin(); i != dataCopy.end(); i++){
        if(i != dataCopy.begin()){
            ss << ",";
        }
        ss << "'";
        ss << i->second << "'";
    }
    ss << ");";
    
    /* Execute SQL statement */
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
    //cout << ss.str() << endl;
    long long id = sqlite3_last_insert_rowid(db);
    data->setId(id);
}

void Sqlitedata::deleteData(Savedata* data){
    /* Create SQL statement */
    stringstream ss;
    ss << "DELETE FROM ";
    ss << data->dataTitle();
    ss << " WHERE Id=";
    ss << data->getId();
    /* Execute SQL statement */
    sqlite3_exec(db, ss.str().c_str(), 0, 0, 0);
    
    //cout << ss.str() << endl;
}

int Sqlitedata::userCallback(void *dataPrev, int colNum, char **value, char **colName){
    int i;
    cout << "callback running" << endl;
    
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)dataPrev;
    Users* user = new Users();
    for(i = 0; i<colNum; i++){
        if(strcmp(colName[i], "FirstName")== 0) user->setFirst(value[i]);
        else if(strcmp(colName[i], "LastName")== 0) user->setLast(value[i]);
        else if(strcmp(colName[i], "Email")== 0) user->setEmail(value[i]);
    }
    copyPrev->push_back(user);
    return 0;
}

/*int Sqlitedata::userCallback(void *userPrev, int colNum, char **value, char **colName){
    int i;
    cout << "callback running" << endl;
    
    (vector<Savedata*> *)userPrev;
    for(i = 0; i<colNum; i++){
        printf("%s = %s\n", colName[i], value[i] ? value[i] : "NULL");
    }
    
    printf("\n");
    return 0;
}*/
