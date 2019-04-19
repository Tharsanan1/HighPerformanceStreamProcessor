//
// Created by tharsanan on 4/13/19.
//

#ifndef STREAM_PROCESSOR_EXECUTORCREATOR_H
#define STREAM_PROCESSOR_EXECUTORCREATOR_H

#include <thread>
#include "BufferContainer.h"

using namespace std;

class ExecutorCreator {
private:
    int numberOfOutputAttributes;
    BufferContainer* bufferContainer;
public:
    ExecutorCreator();
    void createThreads(ExecutorCreator* executorCreator);
    void run(int consumerIndex);
    void tempFunc();
};


#endif //STREAM_PROCESSOR_EXECUTORCREATOR_H
