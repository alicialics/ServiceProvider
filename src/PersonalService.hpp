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
    bool getLicense();
    string getLanguage();
    
    //setters
    void setLicense(bool);
    void setLanguage(string);
    void addPerService();
  
    //print
    void printPersonalService();
  
  private:
    bool hasLicense;
    string language;
};

#endif
