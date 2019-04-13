//
// Created by tharsanan on 4/13/19.
//

#include "AttributeTypeMapper.h"


map<string, string> AttributeTypeMapper::inputAttributeMap;
map<string, string> AttributeTypeMapper::outputAttributeMap;

map<string, string> AttributeTypeMapper::getInputAttributeMap(){
    return inputAttributeMap;
}

map<string, string> AttributeTypeMapper::getOutputAttributeMap(){
    return outputAttributeMap;
}

void AttributeTypeMapper::addToInputAttributeMap(string key, string value){
    inputAttributeMap.insert(pair<string, string>(key,value));
}

void AttributeTypeMapper::addToOutputAttributeMap(string key, string value){
    outputAttributeMap.insert(pair<string, string>(key,value));
}

string AttributeTypeMapper::getTypeForInputAttribute(string attribute){
    auto it = inputAttributeMap.find(attribute);
    if(it == inputAttributeMap.end()){
       return "";
    }
    else{
        return it->second;
    }
}
string AttributeTypeMapper::getTypeForOutputAttribute(string attribute){

}