//
// Created by tharsanan on 4/13/19.
//

#include "ExecutorCreator.h"

ExecutorCreator::ExecutorCreator(){
    numberOfOutputAttributes = DetailContainer::getNumberOfOutputAttributes();
}

void ExecutorCreator::run(int consumerIndex){
    while(DetailContainer::getExecutionFlag()){
        bufferContainer->executeProcess(consumerIndex);
    }
}

void ExecutorCreator::tempFunc(){
    for (int i = 0; i < 100; ++i) {
        bufferContainer->pushWeight(i);
        bufferContainer->pushWeightt(i+1000);
//        usleep(10);
    }

}

void ExecutorCreator::createThreads(ExecutorCreator* executorCreator){
    bufferContainer = new BufferContainer();
    std::thread t[numberOfOutputAttributes];
    for (int i = 0; i < numberOfOutputAttributes; ++i) {
        t[i] = std::thread(&ExecutorCreator::run, executorCreator, i);
    }
    thread th = thread(&ExecutorCreator::tempFunc, executorCreator);
    for (int i = 0; i < numberOfOutputAttributes; ++i) {
        t[i].join();
    }
    th.join();
    delete bufferContainer;

}