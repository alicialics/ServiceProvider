#include <iostream>
#include <map>
using namespace std;

#include "Step.h"

Step::Step(){
}

void Step::setInstruction(string instruction, Step* nextStep){
    instructions[instruction] = nextStep;
}

Step* Step::nextStep(string instruction){
    if(instructions.find(instruction) != instructions.end()){
        return instructions[instruction];
    }else{
        return nullptr;
    }
    
}

vector<string> Step::getInstructions() const{
    vector<string>keys;
    for(auto i = instructions.begin(); i != instructions.end(); i++){
        keys.push_back(i->first);
    }
    return keys;
}

bool Step::checkInput(string action){
    return instructions.find(action) != instructions.end();
}

