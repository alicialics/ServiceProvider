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
    string getFirst() const {return first;}

    string getLast() const{return last;}
    int getAge() const{return age;}
    void setAge(int _age){age = _age;}
    void createTable(sqlite3*);
    void save(sqlite3*);
    void remove(sqlite3*);
};



#endif /* Users_h */
