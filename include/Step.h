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
    void setInstruction(string, Step*);
    Step* nextStep(string);
    vector<string> getInstructions() const;
    bool checkInput(string);
    void printInstructions();
};


#endif /* Step_h */
