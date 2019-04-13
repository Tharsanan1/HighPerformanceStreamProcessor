//
// Created by tharsanan on 4/13/19.
//

#ifndef STREAM_PROCESSOR_EXECUTORCREATOR_H
#define STREAM_PROCESSOR_EXECUTORCREATOR_H

#include <thread>

using namespace std;

class ExecutorCreator {
private:
    int numberOfOutputAttributes;

public:
    ExecutorCreator();
    void createThreads();
};


#endif //STREAM_PROCESSOR_EXECUTORCREATOR_H
