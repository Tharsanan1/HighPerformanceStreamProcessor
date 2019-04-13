//
// Created by chrustkiran on 4/7/19.
//

#include <fstream>
#include "BufferGenerator.h"

std::vector<std::string> BufferGenerator::split(std::string s, std::string delimiter) {
    std::vector<std::string> arguments;

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        // std::cout << token << std::endl;
        arguments.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    // std::cout << s << std::endl;
    arguments.push_back(s);
    return arguments;
}

std::string BufferGenerator::makeFirstCapital(std::string s) {
    char capitalFirstLetter = s.c_str()[0] - 32;
    return capitalFirstLetter + s.substr(1, s.size());


}

void BufferGenerator::readArgs(std::string input_args) {
    std::vector<std::string> input_args_array = split(input_args, ", ");
    for (int i = 0; i < input_args_array.size(); i++) {
        std::vector<std::string> types_params_array = split(input_args_array[i], " ");
        BufferGenerator::input_params.push_back(types_params_array[0]);
        BufferGenerator::input_types.push_back(types_params_array[1]);
        //std::cout << input_args_array[i] << std::endl;
    }


}


void BufferGenerator::preparingVariables() {
    for (int i = 0; i < input_params.size(); ++i) {
        Variable variable;
        Method method;
        variable.dataType = "Buffer<" + input_types[i] + ">";
        variable.identifier = input_params[i] + "Buffer";
        method.returnType = "void";
        method.identifier = "push" + makeFirstCapital(input_params[i]);
        method.params.insert(pair<string, string>(input_types[i], "value"));
        method.lines.push_back(input_params[i] + "Buffer.push(value);");
        variables.push_back(variable);
        methods.push_back(method);
    }
}

void BufferGenerator::preparingExecutingFunction() {
    Method caseMethod;
    caseMethod.returnType = "void";
    caseMethod.identifier = "executeProcess";
    caseMethod.lines.push_back("switch(option) {");
    caseMethod.params.insert(pair<string,string>("int","option"));
    for (int i = 0; i < this->iomappers.size(); ++i) {

        Variable variable;
        variable.identifier = "executor"+std::to_string(i);
        variable.dataType = "Executor";
        this->variables.push_back(variable);

        caseMethod.lines.push_back("case "+std::to_string(i)+" : processLogic"+std::to_string(i)+"();");
        Method method;
        method.identifier = "processLogic"+iomappers[i].getOutput();
        method.returnType = "void";
        string args = "";
        for (int j = 0; j < iomappers[i].getDependList().size(); ++j) {
            string param = iomappers[i].getDependList()[j];
            string type = AttributeTypeMapper::getTypeForInputAttribute(iomappers[i].getDependList()[j]);
            method.lines.push_back(type+" "+param+" = "+param+"Buffer.pop();");
            args = args + type+" "+param+", ";
        }
        method.lines.push_back("executor"+std::to_string(i)+".performMathLogic("+args.substr(0,args.size()-2)+" );");
        this->methods.push_back(method);
    }
    caseMethod.lines.push_back("}");
    this->methods.push_back(caseMethod);
}

void BufferGenerator::createViaFileCreator() {
    this->producer.className = "BufferContainer";
    this->include.includes.push_back("Buffer.h");
    this->include.includes.push_back("CommonType.h");
    this->include.includes.push_back("iostream");
    this->include.includes.push_back("Executor.h");

    this->producer.include = this->include;

    preparingVariables();

    preparingExecutingFunction();
    this->producer.publicMembers.publicVariables = this->variables;

    this->producer.publicMembers.publicMethods = this->methods;


    this->producer.createCppSource();
    this->producer.createHeaderSource();


}


