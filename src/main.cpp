#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "Manager.h"
#include "Sqlitedata.h"
#include "Demodata.h"


int main(){
    Sqlitedata sqliteData; //create a sqliteDate
    Data* dataway = &sqliteData; //creates a pointer to the reference of sqliteData object
    
    Manager manager(dataway); //create a manager object with all the sqlitedata information in it
    manager.setSteps(); //create user interface graph in manager class
    manager.createData(); //load all saved disk data to manager class for current running use
    manager.execute(); //execute user interface and update data in the manager class
    
    return 0;
    
}//main



