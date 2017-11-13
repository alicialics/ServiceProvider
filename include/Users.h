#include <string>

#ifndef Users_h
#define Users_h

class Users{
private:
    long long id;
    string first;
    string last;
    int age;
public:
    Users(string, string, int);
    long long getId() const {return id;}
    string getFirst() const;
    string getLast() const;
    int getAge() const;
    void userTable(sqlite3*);
    void addUser(sqlite3*);
};



#endif /* Users_h */
