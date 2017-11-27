

#include <sstream>
#include <iostream>
using namespace std;
#include "Sqlitedata.h"
#include "Savedata.h"
#include "Users.h"


vector<Savedata*> Sqlitedata::loadData(){
    createData(Users::name(), Users::toCreate());
    vector<Savedata*> userPrev;
    Users* user = new Users("zhuo", "li", "gmail");
    userPrev.push_back(user);
    return userPrev;
}
void Sqlitedata::createData(string dataTitle, const map<string, string>& toCreate){
    stringstream ss;
    
    ss << "CREATE TABLE IF NOT EXISTS ";
    ss << dataTitle << " (Id INTEGER PRIMARY KEY";
    for(auto i = toCreate.begin(); i != toCreate.end(); i++){
        ss << ", " << i->first << " " << i->second;
    }
    ss << ")" ;
    cout << ss.str() << endl;
}

void Sqlitedata::saveData(Savedata* data){ //pass the object to save
    
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
    cout << ss.str() << endl;
    data->setId(55);
    cout << data->getId() << endl;
}

void Sqlitedata::deleteData(Savedata* data){
    stringstream ss;
    ss << "DELETE FROM ";
    ss << data->dataTitle();
    ss << " WHERE Id=";
    ss << data->getId();
    cout << ss.str() << endl;
}

