#include <string>

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
    void createAccount(string, string, string);
    
    
};



#endif /* Users_h */
