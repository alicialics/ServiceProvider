//
//  Database.h
//  project
//
//  Created by alicia li on 11/25/17.
//  Copyright © 2017 alicia li. All rights reserved.
//

#include <vector>
using namespace std;

#include "Users.h"
#include "Savedata.h"

#ifndef Data_h
#define Data_h

class Data{
private:
    
public:
    virtual vector<Savedata*> loadData(){ return vector<Savedata*>();}
    virtual void saveData(Savedata*){}
    virtual void saveAll(){}
};



#endif /* Data_h */
