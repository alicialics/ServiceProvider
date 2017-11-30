

#include <sstream>
#include <iostream>
using namespace std;

#include "Demodata.h"
#include "Savedata.h"
#include "Users.h"
#include "AutomotiveService.hpp"
#include "PersonalService.hpp"

vector<Savedata*> Demodata::loadData(){
    vector<Savedata*> dataPrev;
    Users* user = new Users("Zhuo", "Li", "alicia@gmail.com");
    Users* user2 = new Users("Jenn", "Finaldi", "jfinaldi32@yahoo.com");
    Users* user3 = new Users("Andrew", "Fearing", "asrf2015@gmail.com");
    dataPrev.push_back(user);
    dataPrev.push_back(user2);
    dataPrev.push_back(user3);
    AutomotiveService* auto1 = new AutomotiveService("Car Wash", "High quality interior/exterior wash", "DVC Parking lot", 20, 10.00, -1, true, "All modern cars and motorcycles");
    PersonalService* pers1 = new PersonalService("Massage", "Full body deep tissue", "123 Concord Ave, Concord", 30, 50.00, -1, true, true, "English, Spanish, Korean");
    dataPrev.push_back(auto1);
    dataPrev.push_back(pers1);
    return dataPrev;
}

