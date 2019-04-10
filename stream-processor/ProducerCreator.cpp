//
// Created by chrustkiran on 4/7/19.
//

#include <fstream>
#include "ProducerCreator.h"


std::vector<std::string> ProducerCreator::split(std::string s, std::string delimiter) {
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

void ProducerCreator::readArgs(std::string input_args) {
    std::vector<std::string> input_args_array = split(input_args, ", ");
    for (int i = 0; i < input_args_array.size(); i++) {
        std::vector<std::string> types_params_array = split(input_args_array[i], " ");
        ProducerCreator::input_params.push_back(types_params_array[0]);
        ProducerCreator::input_types.push_back(types_params_array[1]);
        //std::cout << input_args_array[i] << std::endl;
    }


}

const std::vector<std::string> &ProducerCreator::getInput_types() const {
    return input_types;
}

const std::vector<std::string> &ProducerCreator::getInput_params() const {
    return input_params;
}

std::vector<std::string> ProducerCreator::bufferInitializing() {
    std::vector<std::string> temp;
    std::string initializer = "";
    std::string methodText = "";
   // std::cout << input_params.size() << std::endl;
    for (int i = 0; i < input_params.size(); ++i) {

        initializer = initializer + "\tBuffer<" + input_types[i] + "> " + input_params[i] + "Buffer;\n";
        char capitalFirstLetter = input_params[i].c_str()[0] - 32;
        methodText = methodText + "\tvoid push" + capitalFirstLetter +input_params[i].substr(1,input_params[i].size())+ "Buffer(" + input_types[i] + " value){\n\t\t" +
                     input_params[i] + "Buffer.push(value);\n\t}\n";
    }
    // return temp;
    temp.push_back(initializer);
    temp.push_back(methodText);
    return temp;
}

void ProducerCreator::createFile() {

    std::ofstream outfile("ProducerBuffer.cpp");

    std::string top_of_file = "#include <Buffer.h>\n\n class Producer{\nprivate:\n";

    std::vector<std::string> bufferFileVector = bufferInitializing();
    std::string textForFile = top_of_file + bufferFileVector[0] + "\n\npublic:\n"+bufferFileVector[1]+"\n\n};";
    outfile << textForFile << std::endl;

    outfile.close();
}

int main() {

    ProducerCreator producerCreator;
    producerCreator.readArgs("symbol string, price float, volume int");
    producerCreator.createFile();

}