//  BusinessService.cpp
#include <iomanip>
#include <iostream>
using namespace std;

#include "BusinessService.hpp"
#include "Service.hpp"

//constructor
BusinessService::BusinessService(){}
BusinessService::BusinessService(string n, string des, string l, double dur, double p, bool a, string c): Service(n, des, l, dur, p, a)
{
    businessType = c;
}//constructor

void BusinessService::setBusinessType(string a)
{
    businessType = a;
}//setBusinessType

void BusinessService::addBusService()
{
    Service::addService();
    string w;
    cout << "What type of business service is being offered? (Examples: Secretary, Accounting, Media, Legal): ";
    getline(cin, w);
    setBusinessType(w);
    cout << "Please hit enter to make this service available, or type 'cancel', followed by the enter key to set your service to unavailable." << endl;    getline(cin, w); cout << endl;
    if (w == "cancel") Service::setAvail(false);
    else Service::setAvail(true);
    cout << "MAIN MENU" << endl;
}//addBusService


map<string, string> BusinessService::toSave() const{
    map<string, string> BusinessData = Service::toSave(); //get base class data
    BusinessData["BusinessType"] = businessType;
    return BusinessData;
}

map<string, string> BusinessService::toCreate(){
    map<string, string> BusinessTable = Service::toCreate(); //get base class data
    BusinessTable["BusinessType"] = "string";
    return BusinessTable;
}

string BusinessService::getBusinessType()
{
    return businessType;
}//getBusinessType

double BusinessService::getFeePercentage()
{
    return feePercentage;
}//getFeePercentage

double BusinessService::calculateFee()
{
    return Service::getPrice() * (getFeePercentage() / 100);
}//calculateFee

//print
void BusinessService::printSpecialService() const
{
    //Service::printService();
    cout << "Business type: " << businessType << endl << endl;
}//printBusiness
