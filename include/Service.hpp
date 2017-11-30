//  Service.hpp

#include "Savedata.h"

#ifndef Service_hpp
#define Service_hpp

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
    string dataTitle()const {return "Service";}
    map<string, string> toSave() const;
    static map<string, string> toCreate();
  
    //Constructor
    Service(string, string, string, double, double, int, bool);
  
    //setters
    void setName(string);
    void setDesc(string);
    void setLoc(string);
    void setDur(double);
    void setPrice(double);
    void setStatus(int);
    void setAvail(bool);
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
    int status = -1; //-1,0,1  not started, in progress, complete
    bool availability = false; //yes,no
  
};




#endif
