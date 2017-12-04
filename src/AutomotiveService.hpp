//  AutomotiveService.hpp

#ifndef AutomotiveService_hpp
#define AutomotiveService_hpp

#include "Service.hpp"

class AutomotiveService: public Service
{
public:
    //constructor
    AutomotiveService();
    AutomotiveService(string, string, string, double, double, bool, string = " ", double = 0.0);
    
    //getters
    map<string, string> toSave() const;//for sqlitedata
    static map<string, string> toCreate();//for sqlitedata
    string dataTitle() const{return "AutomotiveService";}
    
    
    //setters
    void setVclType(string);
    void setPriceForParts();  //when the seller knows the price for parts, they can update the total price for service
    void setPriceForParts(double);
    void addAutoService(); //user manually enters attributes
    
    //print
    void printSpecialService() const;
    string serviceType(){return "AutomotiveService";}
    
private:
    string vehicleType;
    double priceForParts;
};
#endif
