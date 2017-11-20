#include <iostream>
using namespace std;

#include "Manager.h"

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
    return true;
}
bool Manager::signIn(){
    cout << "Enter your email:\n";
    string email;
    cin >> email;
    for(Users& user : allUsers){
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
