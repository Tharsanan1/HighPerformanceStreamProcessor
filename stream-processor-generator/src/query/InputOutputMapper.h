//
// Created by tharsanan on 4/10/19.
//

#ifndef STREAM_PROCESSOR_TEST_H
#define STREAM_PROCESSOR_TEST_H


#include <string>
#include "vector"

using namespace std;

class InputOutputMapper {
private:
    vector<string> dependOnList;
    string output;
public:
    void addToDependOn(string input);
    vector<string> getDependList();
    void setOutput(string outputM);
    string getOutput();
};


#endif //STREAM_PROCESSOR_TEST_H
