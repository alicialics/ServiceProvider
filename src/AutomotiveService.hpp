//  AutomotiveService.hpp

#ifndef AutomotiveService_hpp
#define AutomotiveService_hpp

#include "Service.hpp"

class AutomotiveService: public Service
{
  public:
    //constructor
    AutomotiveService(string, string, string, double, double, int, bool, string = " ", double = 0.0);
  
    //setters
    void setVclType(string);
    void setPriceForParts();  //when the seller knows the price for parts, they can update the total price for service
    void addAutoService(); //user manually enters attributes
  
    //print
    void printSpecialService() const;
    string serviceType(){return "AutomotiveService";}

  private:
    string vehicleType;
    double priceForParts;
};
#endif 
