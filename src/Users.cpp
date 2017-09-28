#include <string>
using namespace std;


#include "Users.h"



Users::Users(string ff, string ll, int aa)
:first(ff),last(ll),age(aa)
{
    
}

string Users::getFirst() const{
    return first;
}
string Users::getLast() const{
    return last;
}
int Users::getAge() const{
    return age;
}
