//  PersonalService.hpp
#ifndef PersonalService_hpp
#define PersonalService_hpp

#include "Service.hpp"

class PersonalService: public Service
{
  public:
    //constructor
    PersonalService(string, string, string, double, double, int, bool, bool = false, string = "English");
  
    //getters
    //setters
    //print
    void printPersonalService();
  
  private:
    bool hasLicense;
    string language;
};

#endif
