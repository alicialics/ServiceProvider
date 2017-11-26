//  BusinessService.cpp
#include <iomanip>
#include <iostream>
using namespace std;

#include "BusinessService.hpp"

//constructor
BusinessService::BusinessService(string n, string des, string l, double dur, double p, int s, bool a, string c): Service(n, des, l, dur, p, s, a)
{
  businessType = c;
}//constructor

void BusinessService::setBusinessType(string a)
{
  businessType = a;
}//setBusinessType

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
void BusinessService::printBusiness()
{
  Service::printService();
  cout << "Business type: " << businessType << endl << endl;
}//printBusiness
