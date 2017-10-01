#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

#include "Users.h"



int main(){
    sqlite3 *db;
    int rc;
    string fileName = "mydata.db";
    
    rc = sqlite3_open(fileName.c_str(),&db);
    if(rc){
        cerr << "Can't open database!\n";
    }else{
        cout << "Open database successfully.\n";
    }
    
    
    
    Users user1("zhuo", "li", 60);
    Users user2("andrew", "fearing", 100);
    
    user1.userTable(db);
    
    user1.addUser("zhuo", "li", 60, db);
    user2.addUser("andrew", "fearing", 100, db);

    
    
    return 0;
    
}
