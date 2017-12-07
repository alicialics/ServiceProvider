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
#include "Service.hpp"
#include "Savedata.h"

#ifndef Data_h
#define Data_h

class Data{
    
public:
    virtual vector<Savedata*> loadData() = 0;
    virtual void saveData(Savedata*) =0;
};



#endif /* Data_h */
