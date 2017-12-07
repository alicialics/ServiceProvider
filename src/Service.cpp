//  Service.cpp
#include "Service.hpp"

//constructor
Service::Service() {
	availability = false;
}//an empty default base constructor so that subclass empty object can be created with base class pointer
Service::Service(const string& n, const string& des, const string& l, double dur, double p, bool a)
	:name(n), description(des), location(l), duration(dur), price(p), availability(a)
{
	buyer = string();
}//constructor

//setters
void Service::setName(const string& x)
{
	name = x;
}//setName
void Service::setDesc(const string& x)
{
	description = x;
}//setDesc
void Service::setLoc(const string& x)
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
void Service::setAvail(bool x)
{
	availability = x;
}//setAvail

void Service::setBuyer(const string& x)
{
	buyer = x;
}//setBuyer

//getters
map<string, string> Service::toSave() const {
	map<string, string> serviceData;
	serviceData["Name"] = name;
	serviceData["Description"] = description;
	serviceData["Location"] = location;
	serviceData["Duration"] = to_string(duration);
	serviceData["Price"] = to_string(price);
	serviceData["Availability"] = to_string(availability);
	serviceData["Buyer"] = buyer;
	return  serviceData;
}//toSave
map<string, string> Service::toCreate()
{
	map<string, string> serviceTable;
	serviceTable["Name"] = "string";
	serviceTable["Description"] = "string";
	serviceTable["Location"] = "string";
	serviceTable["Duration"] = "double";
	serviceTable["Price"] = "double";
	serviceTable["Availability"] = "bool";
	serviceTable["Buyer"] = "string";

	return  serviceTable;
}//toCreate
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
bool Service::getAvail()
{
	return availability;
}//getAvail

string Service::getBuyer() {
	return buyer;
}

void Service::addService()
{
	string w;
	double x = 0.0;

	cout << "Please enter the name of your service: ";
	getline(cin, w);
	setName(w);

	cout << "Describe your service: ";
	getline(cin, w);
	setDesc(w);

	cout << "Location of service: ";
	getline(cin, w);
	setLoc(w);

	cout << "How long this service takes to complete, in minutes [enter 0 for n/a]: ";
	getline(cin, w);
	stringstream(w) >> x;
	setDur(x);

	cout << "Price: ";
	getline(cin, w);
	stringstream(w) >> x;
	setPrice(x);

}//addService

//print service info (detailed)
void Service::printService() const
{
	//format this into a better table with columns for each member variable
	cout << "Service: " << name << endl;
	cout << "Description: " << description << endl;
	cout << "Location: " << location << endl;
	cout << "Duration(minutes): " << duration << endl;
	cout.setf(ios::fixed | ios::showpoint); cout << setprecision(2);
	cout << "Price: $" << price << endl;
	cout.unsetf(ios::fixed | ios::showpoint);
	cout << "Availability: " << (availability == true ? "Yes" : "No") << endl;
	this->printSpecialService();
}//printService

//print basic service details for browsing
void Service::printServiceTable(int a) const
{
	cout.width(5); cout.setf(ios::left); cout << a;
	cout.width(22); cout << name;
	cout.width(25); cout << location;
	cout.width(1); cout << "$";
	cout.setf(ios::fixed | ios::showpoint); cout << setprecision(2);
	cout.width(14); cout << price;
	cout.width(7); cout.unsetf(ios::fixed | ios::showpoint);
	cout << (availability == true ? "Yes" : "No") << endl;
}//printServiceTable
