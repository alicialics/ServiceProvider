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
void Service::setDesc(string x)
{
  description = x;
}//setDesc
void Service::setLoc(string x)
{
  location = x;
}//setLoc
void Service::setDur(double x)
{
  duration = x;
}//setDur
void Service::setPrice(double x)
{
  price = x;
}//setPrice
void Service::setStatus(int x)
{
  status = x;
}//setStatus
void Service::setAvail(bool x)
{
  availability = x;
}//setAvail

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

void Service::addService()
{
  string w;
  double x;
  cout << "Please enter the name of your service: ";
  getline(cin, w);
  setName(w);
  
  cout << "Describe your service: ";
  getline(cin, w);
  setDesc(w);
  
  cout << "Location of service: ";
  getline(cin, w); cin.ignore(1000, 10);
  setLoc(w);
  
  cout << "How long this service takes to complete: ";
  cin >> x;
  setDur(x);
  
  cout << "Price: ";
  cin >> x;
  setPrice(x);
  
  cout << "Please hit enter to make this service available, or type 'cancel', followed by the enter key to keep hidden from the marketplace." << endl;
  getline(cin, w);
  if (w == "cancel") availability = false;
  else availability = true;
}//addService

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
