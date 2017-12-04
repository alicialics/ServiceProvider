#include <iostream>
#include <map>
using namespace std;

#include "Step.h"

Step::Step(){
}

void Step::setAction(string action, Step* nextStep){
    actions[action] = nextStep;
}

Step* Step::nextStep(string action){
    if(actions.find(action) != actions.end()){
        return actions[action];
    }else{
        return nullptr;
    }
    
}

vector<string> Step::getActions() const{
    vector<string>keys;
    for(auto i = actions.begin(); i != actions.end(); i++){
        keys.push_back(i->first);
    }
    return keys;
}

bool Step::checkInput(string action){
    return actions.find(action) != actions.end();
}

