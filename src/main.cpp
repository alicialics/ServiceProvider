#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "Manager.h"
#include "Sqlitedata.h"
#include "Demodata.h"


int main(){
    Sqlitedata sqliteData; //create a sqliteDate
    Data* database = &sqliteData; //base class pointer to derived class object
    Manager manager(database); //create a manager object by passing database
    manager.setSteps(); //create user interface graph in manager class
    manager.createData(); //load all saved disk data to manager class for current running use
    manager.execute(); //execute user interface and update data in the manager class
    return 0;
}//main



