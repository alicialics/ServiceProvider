#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "AutomotiveService.hpp"
#include "BusinessService.hpp"
#include "HomeService.hpp"
#include "Users.h"
#include "Manager.h"
#include "PersonalService.hpp"
#include "Service.hpp"
#include "Step.h"
#include "Sqlitedata.h"
#include "Demodata.h"


int main(){
    Demodata dummyData; //creates a Demodata object
    Sqlitedata sqliteData;
    Data* dataway = &sqliteData; //creates a pointer to the reference of Demodata object
    
    Manager manager(dataway); //create a manager object with all the demodata information in it
    manager.setSteps();
    manager.createData();
    
    manager.execute();
    
    return 0;
    
}//main



