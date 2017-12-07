#ifndef STEP_H
#define STEP_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


class Step
{
private:
    map<string, Step*> actions;
    
public:
    Step();
    void setAction(string, Step*);
    Step* nextStep(string);
    vector<string> getActions() const;
    bool checkInput(string);
    void printActions();
};


#endif /* Step_h */
