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

void Data::createData(const Users* user){
    stringstream ss;
    
    ss << "CREATE TABLE IF NOT EXISTS ";
    ss << user->dataTitle() << " (Id INTEGER PRIMARY KEY";
    map<string, string> create = user->toCreate();
    for(auto i = create.begin(); i != create.end(); i++){
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
