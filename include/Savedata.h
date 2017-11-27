//
//  Savedata.h
//  project
//
//  Created by alicia li on 11/26/17.
//  Copyright © 2017 alicia li. All rights reserved.
//

#ifndef Savedata_h
#define Savedata_h
class Savedata{
private:
    int id;
public:
    virtual string dataTitle() const= 0;
    virtual map<string, string> toSave() const = 0;
    int getId() const{return id;}
    void setId(int _id){id = _id;}
    
};

#endif /* Savedata_h */
