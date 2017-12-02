//  AutomotiveService.cpp
#include <iostream>
using namespace std;

#include "AutomotiveService.hpp"
#include "Service.hpp"

//constructor
AutomotiveService::AutomotiveService(){}
AutomotiveService::AutomotiveService(string n, string des, string l, double dur, double p, int s, bool a, string vT, double pP): Service(n, des, l, dur, p, s, a)
{
  vehicleType = vT;
  if (pP >= 0.0) priceForParts = pP;
    else cout << "Error- Price for Parts Cannot Be Negative." << endl;

}
//getters for sqlitedata
map<string, string> AutomotiveService::toSave() const{
    map<string, string> autotiveData = Service::toSave(); //get base class data
    autotiveData["VehicleType"] = vehicleType;
    autotiveData["VehicleType"] = priceForParts;
    return autotiveData;
}

map<string, string> AutomotiveService::toCreate(){
    map<string,string> automotiveTable = Service::toCreate();
    automotiveTable["VehicleType"] = "string";
    automotiveTable["VehicleType"] = "double";
    return automotiveTable;
}
//setters
void AutomotiveService::setVclType(string w)
{
  vehicleType = w;
}//setVclType
void AutomotiveService::setPriceForParts()
{
  double x;
  cout << "What is the total price for parts for this service? ";
  cin >> x;
  priceForParts = x;
  Service::setPrice(x + Service::getPrice()); //adds the parts price to the total price for service
}//setPriceForParts
void AutomotiveService::addAutoService()
{
  string w;
  Service::addService();
  cout << "Please add all vehicle types for this service [cars, trucks, motorcycles, etc]: ";
  getline(cin, w); cin.ignore(1000, 10);
  setVclType(w);
  cout << "Please hit enter to make this service available, or type 'cancel', followed by the enter key to keep hidden from the marketplace." << endl;
  getline(cin, w);
  if (w == "cancel") Service::setAvail(false);
  else Service::setAvail(true);
}//addAutoService

//print
void AutomotiveService::printSpecialService() const
{
  //Service::printService();
  cout << "Available for vehicle types: " << vehicleType << endl << endl;
}//printAutoService
