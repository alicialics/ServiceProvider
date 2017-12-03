

#include <sstream>
#include <iostream>
using namespace std;

#include "BusinessService.hpp"
#include "Demodata.h"
#include "Savedata.h"
#include "Users.h"
#include "AutomotiveService.hpp"
#include "PersonalService.hpp"

vector<Savedata*> Demodata::loadData()
{
    //create a vector of pointers to Savedata objects
    vector<Savedata*> dataPrev;
  
    //create some sample user objects
    Users* user = new Users("Zhuo", "Li", "alicia@gmail.com");
    Users* user2 = new Users("Jenn", "Finaldi", "jfinaldi32@yahoo.com");
    Users* user3 = new Users("Andrew", "Fearing", "asrf2015@gmail.com");
  
    //push sample users into vector
    dataPrev.push_back(user);
    dataPrev.push_back(user2);
    dataPrev.push_back(user3);
  
    //create some sample service objects
    AutomotiveService* auto1 = new AutomotiveService("Car Wash", "High quality interior/exterior wash", "DVC Parking lot", 20, 10.00, true, "All modern cars and motorcycles");
    PersonalService* pers1 = new PersonalService("Massage", "Full body deep tissue", "123 Concord Ave, Concord", 30, 50.00, true, true, "English, Spanish, Korean");
    BusinessService* bus1 = new BusinessService("Wedding Videography", "HD editing in 4k, burned to Blu Ray", "Your Wedding", 0, 550.00,  true, "Media Services");

    //push the service objects into vector
    dataPrev.push_back(auto1);
    dataPrev.push_back(pers1);
    dataPrev.push_back(bus1);
    return dataPrev;
}

