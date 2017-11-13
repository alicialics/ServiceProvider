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
    
    user1.createTable(db);
    
    user1.save(db);
    user2.save(db);
    cout << user1.getId() << " " << user1.getFirst() << " " << user1.getLast() << user1.getAge() << endl;
    
    user1.setAge(20);
    user1.save(db);
    cout << user1.getId() << " " << user1.getFirst() << " " << user1.getLast() << user1.getAge() << endl;
    user1.remove(db);
    cout << user1.getId() << endl;
    
    
    return 0;
    
}
