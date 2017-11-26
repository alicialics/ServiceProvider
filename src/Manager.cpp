#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "Manager.h"
#include "Data.h"

Manager::Manager(){
    currentUser = nullptr;
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
    userData.createData(Users::dataTitle(), Users::toCreate());
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
    for(Users& user : allUsers){
        if(user.getEmail() == email){
            return false;
        }
    }
    Users newUser(first, last, email);
    allUsers.push_back(newUser);
    currentUser = &allUsers.back();
    userData.saveData(currentUser);
    
    return true;
}


bool Manager::signIn(){
    cout << "Enter your email:\n";
    string email;
    cin >> email;
    for(Users& user : allUsers){  //reference not copy of each user
        if(user.getEmail() == email){
            currentUser = &user;
            return true;
        }
    }
    return false;
}



bool Manager::buyMenu(){
    return true;
}

bool Manager::sellMenu(){
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

bool Manager::displayServiceOption(){
    return true;
}

bool Manager::addService(){
    return true;
}
