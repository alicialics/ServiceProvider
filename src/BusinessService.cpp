//  BusinessService.cpp
#include <iostream>
using namespace std;

#include "BusinessService.hpp"

//constructor
BusinessService::BusinessService(string n, string des, string l, double dur, double p, int s, bool a, string c): Service(n, des, l, dur, p, s, a)
{
  businessType = c;
}//constructor

//print
void BusinessService::printBusiness()
{
  Service::printService();
  cout << "Business type: " << businessType << endl << endl;
}//printBusiness
