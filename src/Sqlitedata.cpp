

#include <sstream>
#include <iostream>
using namespace std;
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
    cout << ss.str() << endl;
}

vector<Savedata*> Sqlitedata::loadData(){
    
    createTable(Users::getType(), Users::toCreate());
    vector<Savedata*> userPrev;
    //Users* user = new Users("zhuo", "li", "gmail");//random load one, later will load from database
    //userPrev.push_back(user);
    return userPrev;
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
    
    
    //cout << ss.str() << endl;
}

