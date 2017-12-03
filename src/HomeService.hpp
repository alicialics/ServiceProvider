//  HomeService.hpp
#ifndef HomeService_hpp
#define HomeService_hpp

#include "Service.hpp"

class HomeService: public Service
{
  public:
    HomeService();
    HomeService(string, string, string, double, double, bool, string = "", bool = false, bool = false); //constructor

    //setters
    void setResType(string);
    void setIntExt(bool);
    void setPermit(bool);
    void addHomeService();
    
    //getters
    string dataTitle() const{return "HomeService";}
    map<string, string> toSave() const;
    static map<string, string> toCreate();//for sqlitedata

    string getResType();
    bool getIntExt();
    bool getPermit();
  
    //print
    void printSpecialService() const;
    string serviceType(){return "HomeService";}

  private:
    string residenceType;
    bool intExt;  //true for interior, false for exterior
    bool permit; //true if service requires a permit
};

#endif
