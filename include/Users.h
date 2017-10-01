#include <string>

#ifndef Users_h
#define Users_h

class Users{
private:
    string first;
    string last;
    int age;
public:
    Users(string, string, int);
    string getFirst() const;
    string getLast() const;
    int getAge() const;
    void userTable(sqlite3*);
    void addUser(string, string, int, sqlite3*);
};



#endif /* Users_h */
