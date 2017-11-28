#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "AutomotiveService.hpp"
#include "BusinessService.hpp"
#include "Data.h"
#include "Manager.h"
#include "PersonalService.hpp"
#include "Service.hpp"


Manager::Manager(Data* _data){
    currentUser = nullptr;
    data = _data;
}

void Manager::execute(Step* step){
    while(true){
        cout << "Hello";
        if(currentUser){
            cout <<" " + currentUser->getFirst();
        }
        cout << "!\n";
        map<string, string> convert;
        for(int i = 0; i < step->getInstructions().size(); i++){
            cout << i + 1 << "." << step->getInstructions()[i] << "\n"; //get instructions
            convert[to_string(i+1)] = step->getInstructions()[i];
        }
        
        string action;
        cin >> action;
        
        if (action == "exit") {
            data->saveAll();
            cout << "Bye!" << endl;
            break;
        }
        
        if(convert.find(action) != convert.end()){ //if user enter number instruction
            action = convert[action];  //convert number to alphabet intruction
        }
        
        if(step->nextStep(action) != nullptr){   //if input is correct
            if(executeAction(action)){
                step = step->nextStep(action);    //goes to next step
            }else{
                cout << "Try again." << endl;
            }
            
        }else{
            cout << "wrong input" << endl;
        }
    
    }
}


bool Manager::executeAction(string action){
    cout << "I'm executing " << action << endl;
    
    if(action == "signIn"){
        return signIn();
    }else if(action == "createAccount") {
        return createAccount();
    }else if(action == "signOut"){
        return signOut();
    }
    return false;
}

bool Manager::createData(){
    auto dataPrev = data->loadData();
    for(int i = 0; i < dataPrev.size(); i++){
        if(dataPrev[i]->dataTitle() == "Users"){
            allUsers.push_back(static_cast<Users*>(dataPrev[i]));
        }
    }
   
    return true;
}


bool Manager::createAccount(){
    cout << "Enter your firstName:";
    string first, last, email;
    cin >> first;
    cout << "Enter your lastName:";
    cin >> last;
    cout << "Enter your email:";
    cin >> email;
    for(Users* user : allUsers){
        if(user->getEmail() == email){
            return false;
        }
    }
    
    Users* newUser = new Users(first, last, email); //create newuser 
    allUsers.push_back(newUser);
    currentUser = allUsers.back();
    
    data->saveData(currentUser);
    
    return true;
}


bool Manager::signIn(){
    cout << "Enter your email:\n";
    string email;
    cin >> email;
    for(Users* user : allUsers){  //reference not copy of each user
        if(user->getEmail() == email){
            currentUser = user;
            return true;
        }
    }
    return false;
}



bool Manager::buyMenu(){
    return true;
}

bool Manager::sellMenu()
{
    //output menu
    cout << "What type of service are you offering? [or enter 99 to go back]" << endl << endl;
    cout << "1. Business/Office Services (subject to fee)" << endl;
    cout << "2. Automotive Services" << endl;
    cout << "3. Personal Services" << endl;
    cout << "4. Home Services" << endl << endl;
  
    //user selects choice
    int choice = 98;
    while (true)
    {
      cin >> choice;
      if (choice == 99) break; //sentinel value
      if (addService(choice) != true) return false;
      else break;
    }//while
  
    return true;
}

bool Manager::viewMyService(){
    return true;
}

bool Manager::withdrawMoney(){
    return true;
}

bool Manager::signOut(){
    currentUser = nullptr;
    return true;
}

bool Manager::displayAvailableService(){
    return true;
}

bool Manager::addMoney(){
    return true;
}

bool Manager::buyService(){
    return true;
}

bool Manager::checkout(){
    return true;
}

bool Manager::goBack(){
    return true;
}


bool Manager::displayServiceOption(int choice)
{
  return true;
}

bool Manager::addService(int choice)
{
  switch (choice)
  {
    case 1:
      //create a business object
      
      //fill in the attributes
      //[NEWOBJECTNAME].addBusService();
      return true;
    case 2:
      //create an automotive object
      
      //[NEWOBJECTNAME].addAutoService();
      return true;
    case 3:
      //create a personal object
      
      //[NEWOBJECTNAME].addPerService();
      return true;
    case 4:
      //create a home object
      
      //[NEWOBJECTNAME].addHomeObject();
      return true;
    default:
      return false;
  }//switch
}//addService
