//
//  Data.cpp
//  project
//
//  Created by alicia li on 11/25/17.
//  Copyright © 2017 alicia li. All rights reserved.
//

#include <sstream>
#include <iostream>
using namespace std;
#include "Data.h"
#include "Users.h"

void Data::createData(string dataTitle, const map<string, string>& toCreate){
    stringstream ss;
    
    ss << "CREATE TABLE IF NOT EXISTS ";
    ss << dataTitle << " (Id INTEGER PRIMARY KEY";
    for(auto i = toCreate.begin(); i != toCreate.end(); i++){
        ss << ", " << i->first << " " << i->second;
    }
    ss << ")" ;
    cout << ss.str() << endl;
}

void Data::saveData(const Users* user){
    
    stringstream ss;
    ss << "INSERT INTO ";
    ss << user->dataTitle() << " (";
    map<string, string> userData = user->toSave();
    for(auto i = userData.begin(); i != userData.end(); i++){
        if(i != userData.begin()){
            ss << ",";
        }
        ss << i->first;
    }
    ss << ") VALUES(";
    for(auto i = userData.begin(); i != userData.end(); i++){
        if(i != userData.begin()){
            ss << ",";
        }
        ss << "'";
        ss << i->second << "'";
    }
    ss << ");";
    cout << ss.str() << endl;
}
