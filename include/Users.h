#include <string>
#include <map>
using namespace std;

#include "Savedata.h"

#ifndef Users_h
#define Users_h

class Users : public Savedata{
private:
    long long id;
    string first;
    string last;
    string email;
public:
    Users();
    Users(string, string, string);
    string getFirst() const {return first;}
    string getLast() const{return last;}
    string getEmail() const{return email;}
    void setFirst(string);
    void setLast(string);
    void setEmail(string);
    string dataTitle() const {return "Users";}
    map<string, string> toSave() const;
    static map<string, string> toCreate(); //call static function without object
};



#endif /* Users_h */
