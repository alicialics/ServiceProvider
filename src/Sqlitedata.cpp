#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//#include <cstring>
#include "Sqlitedata.h"
#include "Savedata.h"
#include "Users.h"
#include "Service.hpp"
#include "AutomotiveService.hpp"
#include "BusinessService.hpp"
#include "HomeService.hpp"
#include "PersonalService.hpp"

#include <stdio.h>
#include <sqlite3.h>

Sqlitedata::Sqlitedata(){
    int rc;
    
    string fileName = "mydata.db";
    rc = sqlite3_open(fileName.c_str(),&db);//pass db by reference db points to "mydata.db" now
    if(rc){
        throw "Can't open database!\n";
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
    char * err = 0;
    sqlite3_exec(db, ss.str().c_str(), 0, 0, &err); //create a table for data to store in private database
    if(err){
        throw err;
    }
}

vector<Savedata*> Sqlitedata::loadData(){
    //callback provides a way to obtain results from SELECT statements
    vector<Savedata*> dataPrev;
    
    createTable("Users", Users::toCreate());
    createTable("AutomotiveService", AutomotiveService::toCreate());
    createTable("BusinessService", BusinessService::toCreate());
    createTable("HomeService", HomeService::toCreate());
    createTable("PersonalService", PersonalService::toCreate());
    
    char * err = 0;
    sqlite3_exec(db, "SELECT * from Users", userCallback, (void*)&dataPrev, &err);
    if(err){
        throw err;
    }
    sqlite3_exec(db, "SELECT * from AutomotiveService", autoCallback, (void*)&dataPrev, &err);
    if(err){
        throw err;
    }
    sqlite3_exec(db, "SELECT * from BusinessService", businessCallback, (void*)&dataPrev, &err);
    if(err){
        throw err;
    }
    sqlite3_exec(db, "SELECT * from HomeService", homeCallback, (void*)&dataPrev, &err);
    if(err){
        throw err;
    }
    sqlite3_exec(db, "SELECT * from PersonalService", personalCallback, (void*)&dataPrev, &err);
    if(err){
        throw err;
    }
    
    return dataPrev;
}

void Sqlitedata::saveData(Savedata* data){ //pass the object to save
    
    /* Replace SQL statement */
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
        string value = i->second;
        replace(value.begin(), value.end(), '\'', ' ');
        ss << value << "'";
    }
    ss << ");";
    
    /* Execute SQL statement */
    char * err = 0;
    sqlite3_exec(db, ss.str().c_str(), 0, 0, &err);
    if(err){
        throw err;
    }
    
    long long id = sqlite3_last_insert_rowid(db);
    data->setId(id);
}

void Sqlitedata::deleteData(Savedata* data){
    /* Delete SQL statement */
    stringstream ss;
    ss << "DELETE FROM ";
    ss << data->dataTitle();
    ss << " WHERE Id=";
    ss << data->getId();
    char * err = 0;
    /* Execute SQL statement */
    sqlite3_exec(db, ss.str().c_str(), 0, 0, &err);
    if(err){
        throw err;
    }
}

int Sqlitedata::userCallback(void *dataPrev, int colNum, char **value, char **colName){
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)dataPrev; //cast void pointer
    Users* user = new Users();
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "Id")== 0) user->setId(atoll(value[i]));
        else if(strcmp(colName[i], "FirstName")== 0) user->setFirst(value[i]);
        else if(strcmp(colName[i], "LastName")== 0) user->setLast(value[i]);
        else if(strcmp(colName[i], "Email")== 0) user->setEmail(value[i]);
    }
    copyPrev->push_back(user);
    return 0;
}

void Sqlitedata::loadService(Service* service, int colNum, char **value, char **colName){
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "Id")== 0) service->setId(atoll(value[i]));
        else if(strcmp(colName[i], "Name")== 0) service->setName(value[i]);
        else if(strcmp(colName[i], "Description")== 0) service->setDesc(value[i]);
        else if(strcmp(colName[i], "Location")== 0) service->setLoc(value[i]);
        else if(strcmp(colName[i], "Duration")== 0) service->setDur(atof(value[i]));
        else if(strcmp(colName[i], "Price")== 0) service->setPrice(atof(value[i]));
        else if(strcmp(colName[i], "Availability")== 0) service->setAvail(atoi(value[i]));
        else if(strcmp(colName[i], "Buyer")== 0) service->setBuyer(value[i]);
    }
}

int Sqlitedata::autoCallback(void *autoPrev, int colNum, char **value, char **colName){
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)autoPrev;
    AutomotiveService* automotive = new AutomotiveService();
    loadService(automotive, colNum, value, colName);
    
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "VehicleType")== 0) automotive->setVclType(value[i]);
        else if(strcmp(colName[i], "PriceForParts")== 0) automotive->setPriceForParts(atof(value[i]));
    }
    copyPrev->push_back(automotive);
    return 0;
}

int Sqlitedata::businessCallback(void *businessPrev, int colNum, char **value, char **colName){
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)businessPrev;
    BusinessService* business = new BusinessService();
    loadService(business, colNum, value, colName);
    
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "BusinessType")== 0) business->setBusinessType(value[i]);
    }
    copyPrev->push_back(business);
    return 0;
}

int Sqlitedata::homeCallback(void *homePrev, int colNum, char **value, char **colName){
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)homePrev;
    HomeService* home = new HomeService();
    loadService(home, colNum, value, colName);
    
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "ResidenceType")== 0) home->setResType(value[i]);
        else if(strcmp(colName[i], "IntExt")== 0) home->setIntExt(atoi(value[i]));
        else if(strcmp(colName[i], "Permit")== 0) home->setPermit(atoi(value[i]));
    }
    copyPrev->push_back(home);
    return 0;
}

int Sqlitedata::personalCallback(void *personalPrev, int colNum, char **value, char **colName){
    vector<Savedata*>* copyPrev = (vector<Savedata*>*)personalPrev;
    PersonalService* perosonal = new PersonalService();
    loadService(perosonal, colNum, value, colName);
    
    for(int i = 0; i<colNum; i++){
        if(strcmp(colName[i], "HasLicense")== 0) perosonal->setLicense(atoi(value[i]));
        else if(strcmp(colName[i], "Language")== 0) perosonal->setLanguage(value[i]);
    }
    copyPrev->push_back(perosonal);
    return 0;
}
