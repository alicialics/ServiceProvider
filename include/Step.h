#include <map>
#include <vector>
#include <string>
using namespace std;

#ifndef Step_h
#define Step_h
class Step{
private:
    map<string, Step*> instructions;
   
public:
    Step();
    void setAction(string, Step*);
    Step* nextStep(string);
    vector<string> getActions() const;
    bool checkInput(string);
    void printActions();
};


#endif /* Step_h */
