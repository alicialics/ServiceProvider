#include "Step.h"

Step::Step(){
}

//setAction function store action and nextStep to map actions
void Step::setAction(string action, Step* nextStep){
    actions[action] = nextStep;
}

//nextStep function return the next Step from private variable map actions
Step* Step::nextStep(string action){
    if(actions.find(action) != actions.end()){
        return actions[action];
    }else{
        return nullptr;
    }
    
}
//getActions function return a vector of all actions
vector<string> Step::getActions() const{
    vector<string>keys;
    for(auto i = actions.begin(); i != actions.end(); i++){
        keys.push_back(i->first);
    }
    return keys;
}
//checkInput function check if action exists
bool Step::checkInput(string action){
    return actions.find(action) != actions.end();
}

