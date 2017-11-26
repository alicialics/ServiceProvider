//  Service.cpp
#include <iomanip>
#include <iostream>
using namespace std;

#include "Service.hpp"

//constructor
Service::Service(string n, string des, string l, double dur, double p, int s, bool a)
    :name(n), description(des), location(l), duration(dur), price(p), status(s), availability(a)
{
}//constructor

//setters
void Service::setName(string x)
{
  name = x;
}//setName

//getters
string Service::getName()
{
  return name;
}//getName
string Service::getDesc()
{
  return description;
}//getDesc
string Service::getLoc()
{
  return location;
}//getLoc
double Service::getDur()
{
  return duration;
}//getDur
double Service::getPrice()
{
  return price;
}//getPrice
int Service::getStatus()
{
  return status;
}//getStatus
bool Service::getAvail()
{
  return availability;
}//getAvail

//print service info (detailed)
void Service::printService() const
{
  //format this into a better table with columns for each member variable
  cout << "Service: " << name << endl;
  cout << "Description: " << description << endl;
  cout << "Location: " << location << endl;
  cout << "Duration(minutes): " << duration << endl;
  cout.setf(ios::fixed|ios::showpoint); cout << setprecision(2);
  cout << "Price: $" << price << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
  cout << "Availability: " << (availability == true ? "Yes" : "No" ) << endl;
}//printService

//print basic service details for browsing
void Service::printServiceTable(int a) const
{
  cout.width(5); cout.setf(ios::left); cout << a;
  cout.width(22); cout << name;
  cout.width(25); cout << location;
  cout.width(1); cout << "$";
  cout.setf(ios::fixed|ios::showpoint); cout << setprecision(2);
  cout.width(6); cout << price << endl;
  cout.unsetf(ios::fixed|ios::showpoint);
}//printServiceTable
