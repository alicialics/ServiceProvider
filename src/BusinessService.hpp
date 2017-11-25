/*  BusinessService.hpp
class for business type services such as media, tech, general office, logistics etc.
All business sellers pay a transaction fee of 8% */

#ifndef BusinessService_hpp
#define BusinessService_hpp

#include "Service.hpp"

class BusinessService: public Service
{
  public:
    //constructor
    BusinessService(string, string, string, double, double, int, bool, string = "");
  
    //print
    void printBusiness();
    
  private:
    string businessType;
    int feePercentage = 8;
};

#endif
