//
// Created by tharsanan on 4/10/19.
//

#include "InputOutputMapper.h"

void InputOutputMapper::addToDependOn(string input) {
    dependOnList.push_back(input);//stream-processor-generator/src/query/InputOutputMapper.cpp
}

vector<string> InputOutputMapper::getDependList(){
    return dependOnList;
}

void InputOutputMapper::setOutput(string outputM){
    output = outputM;
}

string InputOutputMapper::getOutput(){
    return output;
}

