//
//  Dummydata.h
//  project
//
//  Created by alicia li on 11/28/17.
//  Copyright © 2017 alicia li. All rights reserved.
//

#include "Data.h"

#ifndef Demodata_h
#define Demodata_h
class Demodata : public Data{
public:
    vector<Savedata*> loadData();
    void saveData(Savedata*){}
    void saveAll(){}
};

#endif /* Dummydata_h */
