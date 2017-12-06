#include <vector>
using namespace std;

#include "AutomotiveService.hpp"
#include "BusinessService.hpp"
#include "HomeService.hpp"
#include "PersonalService.hpp"
#include "Users.h"
#include "Step.h"
#include "Sqlitedata.h"
#include "Service.hpp"

#ifndef Manager_h
#define Manager_h

class Manager{
private:
    Step allSteps[4]; //save all steps, fixed size
    Step* currentStep; //pointer to current step
    vector<Users*> allUsers; //save all users
    vector<Service*> allService; //stores all currently offered services
    Users* currentUser; //pointer to const Users
    Data* data; //track the way to save data
public:
    Manager(Data*);
    ~Manager();
    //setter function to be called in main
    bool createData();
    bool setSteps();
    void execute();
    //getter funciton to get current step
    const Users* getCurrentUser() const{return currentUser;}
    //action fucntion to be executed in manager class
    bool executeAction(string);
    bool createAccount();
    bool signIn();
    bool buyMenu();
    bool buyService();
    bool sellMenu();
    bool addService();
    bool signOut();
    bool displayAvailableService();
    bool viewHistory();
    bool goBack();
};

#endif /* Manager_h */
