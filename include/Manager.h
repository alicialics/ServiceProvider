#include <vector>
using namespace std;

#include "Users.h"
#include "Step.h"
#include "Sqlitedata.h"
#include "Service.hpp"

#ifndef Manager_h
#define Manager_h

class Manager{
private:
    vector<Users*> allUsers; //save all users
    vector<Service*> allService; //stores all currently offered services
  
    Users* currentUser; //pointer to const Users
    Data* data;
    
    
public:
    Manager(Data*);
    void execute(Step*);
    bool executeAction(string);
    const Users* getCurrentUser() const{return currentUser;}
    bool createData();
    bool createAccount();
    bool signIn();
    bool buyMenu();
    bool sellMenu();
    bool viewMyService();
    bool withdrawMoney();
    bool signOut();
    bool displayAvailableService();
    bool addMoney();
    bool buyService();
    bool checkout();
    bool goBack();
    bool displayServiceOption(int);
    bool addService(int);
};

#endif /* Manager_h */
