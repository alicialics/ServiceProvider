#include <sqlite3.h>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

#include "Users.h"

Users::Users(string _first, string _last, string _email)
:first(_first),last(_last),email(_email)
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
    map<string,string> table;
    table["FirstName"] = "string";
    table["LastName"] = "string";
    table["Email"] = "string";
    return table;
}
