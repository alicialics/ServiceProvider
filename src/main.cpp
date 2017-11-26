#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "Users.h"
#include "Manager.h"
#include "Service.hpp"
#include "Step.h"
//JENNS COMMENT FOR TESTING


int main(){

    Step next[4];
    
    string parse_instru = R"(
    0 signIn 1
    0 createAccount 1
    1 buyMenu 2
    1 sellMenu 3
    1 viewMyService 1
    1 withdrawMoney 1
    1 signOut 0
    2 displayAvailableService 2
    2 buyService 2
    2 addMoney 2
    2 checkout 1
    2 goBack 1
    3 displayServiceOption 3
    3 addService 1
    3 goBack 1
    )";
    
    stringstream ss(parse_instru);
    int index, next_index;
    string instruction;
    while(ss >> index >> instruction >> next_index){
        next[index].setInstruction(instruction, &next[next_index]);
    }
    
    
    /*
     step 0:
     createAccount : addUser firstName lastName email
     sign in : signIn(email)
     
     step 1:
     buyMenu -> step 2
     sellMenu -> step 3
     viewMyService
     withdrawMoney
     signOut -> step 0
     
     
     step 2:
     displayAvailableSerive
     buyService
     addMoney
     checkOut -> 1
     goBack -> 1

     step 3:
     displayServiceOption
     addService(serviceName, date, time, price, duration, location)

     
     5.clearAllData
     clear
    
     eg:
     createAccount Andrew Fearing andrew@gmail.com
     signIn andrew@gmail.com
     displayServiceOption
     addService carwash 11/12 2pm 2234 clinton street, new york, 30, 30
     displayBuyandSell
     
     
     createAccount zhuo li aliciali666@gmail.com
     signIn aliciali666@gmail.com
     displayAvailableSerive
     buyService 2
     buyService 4
     buyservice 5
     addMoney 20
     checkOut
     displayBuyandSell
     
     */
    
    Step* step = &next[0];
    
    
    
    Manager manager;
    manager.createData();
    manager.execute(step);
    
    
    //test change on the github.com
    
    //test change on my local
    
    return 0;
    
}
