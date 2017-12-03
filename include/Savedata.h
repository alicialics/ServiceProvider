#include <iostream>
#include <map>
using namespace std;

#ifndef Savedata_h
#define Savedata_h

class Savedata
{
  private:
    long long id;
  
  public:
    virtual string dataTitle() const= 0;
    virtual map<string, string> toSave() const = 0;
    long long getId() const{return id;}
    void setId(long long _id){id = _id;}
    
};

#endif /* Savedata_h */
