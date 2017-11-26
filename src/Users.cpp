#include <sqlite3.h>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;


#include "Users.h"



Users::Users(string _first, string _last, string _email)
:id(0),first(_first),last(_last),email(_email)
{
    
}
map<string, string> Users::toSave() const{
    map<string, string> userData;
    userData["FirstName"] = first;
    userData["LastName"] = last;
    userData["Email"] = email;
    
    return  userData;
}

map<string, string> Users::toCreate(){
    map<string,string> create;
    create["FirstName"] = "string";
    create["LastName"] = "string";
    create["Email"] = "string";
    return create;
}
