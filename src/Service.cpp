//  Service.cpp
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

//print service info
void Service::printService() const
{
  //format this into a better table with columns for each member variable
  cout << "Service: " << name << endl;
  cout << "Description: " << description << endl;
  cout << "Location: " << location << endl;
  cout << "Duration(minutes): " << duration << endl;
  cout << "Price: $" << price << endl;
  cout << "Availability: " << (availability == true ? "Yes" : "No" ) << endl;
}//printService
