//  PersonalService.cpp
#include <iostream>
using namespace std;

#include "PersonalService.hpp"

//constructor
PersonalService::PersonalService(string n, string des, string l, double dur, double p, int s, bool a, bool c, string b): Service(n, des, l, dur, p, s, a)
{
  hasLicense = c;
  language = b; 
}

//print
void PersonalService::printPersonalService()
{
  Service::printService();
  cout << "Licensed: " << (hasLicense == true ? "Yes" : "No") << endl;
  cout << "Language(s): " << language << endl << endl;
}
