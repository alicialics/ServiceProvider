#include <vector>
using namespace std;

#include "Users.h"
#include "Step.h"
#include "Data.h"

#ifndef Manager_h
#define Manager_h

class Manager{
private:
    vector<Users> allUsers; //save all users
    const Users* currentUser; //pointer to const Users
    Data userData;
public:
    Manager();
    void execute(Step*);
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
