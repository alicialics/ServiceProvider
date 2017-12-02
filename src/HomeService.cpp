//  HomeService.cpp
#include <iostream>
using namespace std;

#include "HomeService.hpp"
#include "Service.hpp"

//constructor
HomeService::HomeService(){}
HomeService::HomeService(string n, string des, string l, double dur, double p, int s, bool a, string x, bool y, bool z): Service(n, des, l, dur, p, s, a)
{
  residenceType = x;
  intExt = y;
  permit = z;
}//constructor

//getters
map<string, string> HomeService::toSave() const{
    map<string, string> HomeData = Service::toSave(); //get base class data
    HomeData["ResidenceType"] = residenceType;
    HomeData["IntExt"] = intExt;
    HomeData["Permit"] = permit;
    return HomeData;
}

map<string, string> HomeService::toCreate() {
    map<string, string> HomeTable = Service::toCreate(); //get base class data
    HomeTable["ResidenceType"] = "string";
    HomeTable["IntExt"] = "bool";
    HomeTable["Permit"] = "bool";
    return HomeTable;
}

string HomeService::getResType()
{
  return residenceType;
}//getResType
bool HomeService::getIntExt()
{
  return intExt;
}//getIntExt
bool HomeService::getPermit()
{
  return permit;
}//getPermit

//setters
void HomeService::setResType(string x)
{
  residenceType = x;
}//setResType
void HomeService::setIntExt(bool x)
{
  intExt = x;
}//setIntExt
void HomeService::setPermit(bool x)
{
  permit = x;
}//setPermit
void HomeService::addHomeService()
{
  Service::addService();
  string w;
  char x = 'o';
  cout << "What type of residences is this service for? (Examples: apartment, house, condo, etc): ";
  getline(cin, w); cin.ignore(1000, 10);
  setResType(w);
  while (true)
  {
    cout << "Please enter 'i' if this service is for interior, or 'e' for exterior: ";
    cin >> x;
    if (toupper(x) == 'I')
    {
      setIntExt(true);
      break;
    }//if
    if (toupper(x) == 'E')
    {
      setIntExt(false);
      break;
    }//if
    else cout << endl << "Invalid entry" << endl << endl;
  }//while

  while (true)
  {
    cout << "Is a permit required to perform this service? [Y/N]: ";
    cin >> x;
    if (toupper(x) == 'Y')
    {
      setIntExt(true);
      break;
    }//if
    if (toupper(x) == 'N')
    {
      setIntExt(false);
      break;
    }//if
    else cout << endl << "Invalid entry, please enter 'y' for yes or 'n' for no." << endl << endl;
  }//while

  cout << "Please hit enter to make this service available, or type 'cancel', followed by the enter key to keep hidden from the marketplace." << endl;
  getline(cin, w);
  if (w == "cancel") Service::setAvail(false);
  else Service::setAvail(true);
}//addHomeService


//print
void HomeService::printSpecialService() const
{
  //Service::printService();
  cout << "Type of Residences: " << residenceType << endl;
  cout << "Interior/Exterior: " << (intExt == true ? "Interior" : "Exterior") << endl;
  cout << "Permit Required: " << (permit == true ? "Yes" : "No") << endl;
}//printHomeService
