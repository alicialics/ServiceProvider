//
//  Sqlitedata.h
//  project
//
//  Created by alicia li on 11/26/17.
//  Copyright © 2017 alicia li. All rights reserved.
//
#include "Data.h"
#include "Savedata.h"

#include <stdio.h>
#include <sqlite3.h>

#ifndef Sqlitedata_h
#define Sqlitedata_h
class Sqlitedata : public Data{
private:
    sqlite3 *db; //pointer to database
public:
    Sqlitedata();
    vector<Savedata*> loadData();
    void createTable(string, const map<string, string>&);
    void saveData(Savedata*);
    void deleteData(Savedata*);
    void saveAll(){}
};

#endif /* Sqlitedata_h */
