//
// Created by tharsanan on 4/13/19.
//

#ifndef STREAM_PROCESSOR_ATTRIBUTETYPEMAPPER_H
#define STREAM_PROCESSOR_ATTRIBUTETYPEMAPPER_H

#include "map"

using namespace std;

class AttributeTypeMapper {
private:
    static map<string, string> inputAttributeMap;
    static map<string, string> outputAttributeMap;
public:
    static map<string, string> getInputAttributeMap();
    static void addToInputAttributeMap(string key, string value);
    static map<string, string> getOutputAttributeMap();
    static void addToOutputAttributeMap(string key, string value);
    static string getTypeForInputAttribute(string attribute);
    static string getTypeForOutputAttribute(string attribute);
};


#endif //STREAM_PROCESSOR_ATTRIBUTETYPEMAPPER_H
