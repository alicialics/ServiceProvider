#include <string>
#include <map>
using namespace std;

#ifndef Users_h
#define Users_h

class Users{
private:
    long long id;
    string first;
    string last;
    string email;
public:
    Users(string, string, string);
    string getFirst() const {return first;}
    string getLast() const{return last;}
    string getEmail() const{return email;}
    string dataTitle() const{return "Users";}
    map<string, string> toSave() const;
    map<string, string> toCreate() const;
};



#endif /* Users_h */
