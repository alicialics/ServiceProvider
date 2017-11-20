#include <sqlite3.h>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


#include "Users.h"



Users::Users(string _first, string _last, string _email)
:id(0),first(_first),last(_last),email(_email)
{
    
}


