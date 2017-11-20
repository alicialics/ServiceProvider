#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

#include "Users.h"
#include "Manager.h"


bool update(string choose, Manager& manager){
    cout << "I'm executing " << choose << endl;
    
    if(choose == "signIn"){
        return manager.signIn();
    }else if(choose == "createAccount") {
        return manager.createAccount();
    }else if(choose == "signOut"){
        return manager.signOut();
    }
    return false;
}

int main(){
   
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
    
    int step = 0;
    map<string, int> next[4];
  
    next[0]["signIn"] = 1;
    next[0]["createAccount"] = 1;
    next[1]["buyMenu"] = 2;
    next[1]["sellMenu"] = 3;
    next[1]["viewMyService"] = 1;
    next[1]["withdrawMoney"] = 1;
    next[1]["signOut"] = 0;
    next[2]["displayAvailableService"] = 2;
    next[2]["buyService"] = 2;
    next[2]["addMoney"] = 2;
    next[2]["checkout"] = 1;
    next[2]["goBack"] = 1;
    next[3]["displayServiceOption"] = 3;
    next[3]["addService"] = 1;
    next[3]["goBack"] = 1;
    
    Manager manager;
    while(true){
        cout << "Hello";
        if(manager.getCurrentUser()){
            cout <<" " + manager.getCurrentUser()->getFirst();
        }
        cout << "!\n";
        int index = 1;
        map<string, string> convert;
        for(auto i = next[step].begin(); i != next[step].end(); i++,index++){
            cout << index << "." << i->first << "\n";
            convert[to_string(index)] = i->first;
        }
        string choose;
        cin >> choose;
        if(convert.find(choose) != convert.end()){
            choose = convert[choose];
        }
        if(next[step].find(choose) != next[step].end()){
            if(update(choose, manager)){
                step = next[step][choose];
            }else{
                cout << "Try again." << endl;
            }
            
        }else{
            cout << "wrong input" << endl;
        }
        
    }
    
    return 0;
    
}
