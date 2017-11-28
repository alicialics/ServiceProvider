//  AutomotiveService.cpp
#include <iostream>
using namespace std;

#include "AutomotiveService.hpp"
#include "Service.hpp"

//constructor
AutomotiveService::AutomotiveService(string n, string des, string l, double dur, double p, int s, bool a, string vT, double pP): Service(n, des, l, dur, p, s, a)
{
  vehicleType = vT;
  if (pP >= 0.0) priceForParts = pP;
    else cout << "Error- Price for Parts Cannot Be Negative." << endl;
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
}//addAutoService

//print
void AutomotiveService::printAutoService()
{
  Service::printService();
  cout << "Available for vehicle types: " << vehicleType << endl << endl;
}//printAutoService
