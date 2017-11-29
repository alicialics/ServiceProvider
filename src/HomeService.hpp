//  HomeService.hpp
#ifndef HomeService_hpp
#define HomeService_hpp

#include "Service.hpp"

class HomeService: public Service
{
  public:
    HomeService(string, string, string, double, double, int, bool, string = "", bool = false, bool = false); //constructor

    //setters
    void setResType(string);
    void setIntExt(bool);
    void setPermit(bool);
    void addHomeService();
    
    //getters
    string getResType();
    bool getIntExt();
    bool getPermit();
  
    //print
    void printHomeService();

  private:
    string residenceType;
    bool intExt;  //true for interior, false for exterior
    bool permit; //true if service requires a permit
};

#endif
