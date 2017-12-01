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
  
/*   DO WE NEED THESE TO ALLOW USER TO BROWSE BY CATEGORY? OR IS THERE A GOOD WAY TO SEARCH THE allService VECTOR?
vector<AutomotiveService*> autoService; //stores all the automotive services
vector<BusinessService*> busService; //stores all the business services
vector<HomeService*> homeService; //stores all the home services
vector<PersonalService*> perService; ///stores all the personal services
*/

    Users* currentUser; //pointer to const Users
    Data* data;
    
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
    bool addService(int);
    bool addService();
};

#endif /* Manager_h */
