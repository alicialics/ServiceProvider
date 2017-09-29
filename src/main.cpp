#include <sqlite3.h>
#include <string>
#include <iostream>
using namespace std;

#include "Users.h"



int main(){
    Users user1("zhuo", "li", 60);
    Users user2("jack", "zhao", 100);
    cout << user1.getFirst() << " " << user1.getLast() << endl;
    return 0;
    
}
