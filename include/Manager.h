#include <vector>
using namespace std;

#include "Users.h"
#include "Step.h"
#include "Sqlitedata.h"

#ifndef Manager_h
#define Manager_h

class Manager{
private:
    Step allSteps[4]; //save all steps, fixed size
    Step* currentStep; //pointer to current step
    vector<Users*> allUsers; //save all users
    Users* currentUser; //pointer to current user
    Data* data; //save current way of storing data
    
    
public:
    Manager(Data*);
    ~Manager();
    bool createData();
    bool setSteps();
    void execute();
    bool executeAction(string);
    const Users* getCurrentUser() const{return currentUser;}
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
    bool displayServiceOption();
    bool addService();
};

#endif /* Manager_h */
