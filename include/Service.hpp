//  Service.hpp
#ifndef Service_hpp
#define Service_hpp

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

#include "Savedata.h"

class Service : public Savedata
{
public:
    //getters
    string getName();
    string getDesc();
    string getLoc();
    double getDur();
    double getPrice();
    bool getAvail();
    string getBuyer();
    map<string, string> toSave() const;//base map to be call in the sub class toSave(called by pointer to base class)
    static map<string, string> toCreate();
    
    
    //Constructor
    Service();
    Service(const string&, const string&, const string&, double, double, bool);
    virtual ~Service(){}
    
    //setters
    void setName(const string&);
    void setDesc(const string&);
    void setLoc(const string&);
    void setDur(double);
    void setPrice(double);
    void setAvail(bool);
    void setBuyer(const string&);
    void addService();
    
    //print Service Info
    void printService() const;
    void printServiceTable(int) const;
    
    
private:
    string name;
    string description;
    string location;
    double duration; //minutes
    double price; //dollars
    bool availability; //yes,no
    string buyer;//if buyer set, unavailable, else available
    virtual void printSpecialService() const= 0;
};

#endif
