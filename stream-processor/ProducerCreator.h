//
// Created by chrustkiran on 4/7/19.
//

#ifndef BUFFERCREATOR_PRODUCERCREATOR_H
#define BUFFERCREATOR_PRODUCERCREATOR_H

#include "stdio.h"
#include "iostream"
#include "vector"


class ProducerCreator {
private:
    std::vector<std::string> split(std::string s, std::string delimiter);
    std::vector<std::string> input_types;
    std::vector<std::string> input_params;
    std::vector<std::string> bufferInitializing();

public:
    void readArgs(std::string input_args);
    const std::vector<std::string> &getInput_types() const;
    const std::vector<std::string> &getInput_params() const;
    void createFile();

};


#endif //BUFFERCREATOR_PRODUCERCREATOR_H
