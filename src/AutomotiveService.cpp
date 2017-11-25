//  AutomotiveService.cpp
#include <iostream>
using namespace std;

#include "AutomotiveService.hpp"

//constructor
AutomotiveService::AutomotiveService(string n, string des, string l, double dur, double p, int s, bool a, string vT, double pP): Service(n, des, l, dur, p, s, a)
{
  vehicleType = vT;
  if (pP >= 0.0) priceForParts = pP;
    else cout << "Error- Price for Parts Cannot Be Negative." << endl;
}

//print this
void AutomotiveService::printAutoService()
{
  Service::printService();
  cout << "Available for vehicle types: " << vehicleType << endl << endl;
}//printAutoService
