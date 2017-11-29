#include <iostream>
#include <sstream>
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

Manager::~Manager(){
    for(Users* oneUser : allUsers){
        delete oneUser;
    }
}

bool Manager::createData(){
    auto dataPrev = data->loadData();
    for(int i = 0; i < dataPrev.size(); i++){
        if(dataPrev[i]->dataTitle() == "Users"){
            allUsers.push_back(static_cast<Users*>(dataPrev[i])); //cast from base to derived object: Savedata to Users
        }
    }

    return true;
}

bool Manager::setSteps(){
    string parse_action = R"(
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
    stringstream ss(parse_action);
    int index, next_index;
    string action;
    while(ss >> index >> action >> next_index){
        allSteps[index].setAction(action, &allSteps[next_index]);
    }

    currentStep = &allSteps[0];
    return true;
}


void Manager::execute(){
    while(true){
        cout << "Hello";
        if(currentUser){
            cout <<" " + currentUser->getFirst();
        }
        cout << "!\n";
        map<string, string> convert;
        for(int i = 0; i < currentStep->getActions().size(); i++){  //for loop to get all actions of current step
            cout << i + 1 << "." << currentStep->getActions()[i] << "\n";
            convert[to_string(i+1)] = currentStep->getActions()[i]; //a convert map from number action to alphabet one
        }
        
        string action;
        cin >> action;
        
        if (action == "exit") {
            data->saveAll();
            cout << "Bye!" << endl;
            break;
        }
        
        if(convert.find(action) != convert.end()){ //if user enter number action
            action = convert[action];  //convert number to alphabet action
        }
        
        if(currentStep->nextStep(action) != nullptr){   //if input is correct
            if(executeAction(action)){
                currentStep = currentStep->nextStep(action);    //goes to next step
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



bool Manager::createAccount(){
    cout << "Enter your firstName:";
    string first, last, email;
    cin >> first;
    cout << "Enter your lastName:";
    cin >> last;
    cout <<  "Enter your email:";
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



bool Manager::buyMenu()
{
  //ask the user what type of service they're interested in, display menu
  
  //output list of appropriate category of services
  
  //prompt user for sort method or select an index of a service on the list
  
  //output a detailed description of service of interest
  
  //buyer either purchases or returns to browsing
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

bool Manager::displayAvailableService()
{
  cout << "#    Service               Location                 Price" << endl;
  cout << "-    -------               --------                 -----" << endl;
  for(int i = 0; ; i++)
  {
    //object[i].printServiceTable(i);
  }//for
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
      
      //[NEWOBJECTNAME].addHomeService();
      return true;
    default:
      return false;
  }//switch
}//addService



