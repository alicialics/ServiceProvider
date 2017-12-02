//  Service.hpp
#ifndef Service_hpp
#define Service_hpp

#include "Savedata.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

class Service : public Savedata
{
  public:
    //getters
    string getName();
    string getDesc();
    string getLoc();
    double getDur();
    double getPrice();
    int getStatus();
    bool getAvail();
    string getBuyer();
    map<string, string> toSave() const;//base map to be call in the sub class toSave(called by pointer to base class)
    static map<string, string> toCreate();
    virtual string serviceType() = 0;
  
    //Constructor
    Service();
    Service(const string&, const string&, const string&, const double&, const double&,const int&, const bool&);
    virtual ~Service(){}
  
    //setters
    void setName(const string&);
    void setDesc(const string&);
    void setLoc(const string&);
    void setDur(double);
    void setPrice(double);
    void setStatus(int);
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
    int status; //-1,0,1  not started, in progress, complete
    bool availability; //yes,no
    string buyer;//if buyer set, unavailable, else available
    virtual void printSpecialService() const= 0;
};




#endif
