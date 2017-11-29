#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "AutomotiveService.hpp"
#include "BusinessService.hpp"
#include "Users.h"
#include "Manager.h"
#include "PersonalService.hpp"
#include "Service.hpp"
#include "Step.h"
#include "Sqlitedata.h"


int main(){

    Sqlitedata dataway;
    
    Manager manager(&dataway);
    manager.setSteps();
    manager.createData();
    
    manager.execute();
   
    /*printTableHeader();
    //testingAutomotiveServiceClass
    AutomotiveService auto1("Car Wash", "High quality interior/exterior wash", "DVC Parking lot", 20, 10.00, -1, true, "All modern cars and motorcycles");
    auto1.printServiceTable(1); 
  
    //testingPersonalServiceClass
    PersonalService pers1("Massage", "Full body deep tissue", "123 Concord Ave, Concord", 30, 50.00, -1, true, true, "English, Spanish, Korean");
    pers1.printServiceTable(2);
  
    //testingBusinessServiceClass
    BusinessService bus1("Wedding Videography", "HD editing in 4k, burned to Blu Ray", "Your Wedding", 0, 550.00, -1, true, "Media Services");
    bus1.printServiceTable(3);*/
  
    
    return 0;
    
}//main



