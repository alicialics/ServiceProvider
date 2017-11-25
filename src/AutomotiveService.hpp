//  AutomotiveService.hpp

#ifndef AutomotiveService_hpp
#define AutomotiveService_hpp

#include "Service.hpp"

class AutomotiveService: public Service
{
  public:
    //constructor
    AutomotiveService(string, string, string, double, double, int, bool, string = " ", double = 0.0);
  
    //print
    void printAutoService();
  private:
    string vehicleType;
    double priceForParts;
};
#endif 
