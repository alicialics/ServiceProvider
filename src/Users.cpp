#include "Users.h"

Users::Users(){}
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

void Users::setFirst(string _first){
    first = _first;
}

void Users::setLast(string _last){
    last = _last;
}

void Users::setEmail(string _email){
    email = _email;
}


