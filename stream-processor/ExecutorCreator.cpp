//
// Created by tharsanan on 4/13/19.
//

#include "ExecutorCreator.h"
BufferContainer* ExecutorCreator::bufferContainer = nullptr;

ExecutorCreator::ExecutorCreator(){
    numberOfOutputAttributes = DetailContainer::getNumberOfOutputAttributes();
}

void ExecutorCreator::run(int consumerIndex){
    while(DetailContainer::getExecutionFlag()){
        bufferContainer->executeProcess(consumerIndex);
    }
}

void ExecutorCreator::tempFunc(){
    PerformanceMonitor::setStart();
    for (int i = 0; i < 100; ++i) {
        bufferContainer->pushWeightBuffer(i);
        bufferContainer->pushWeighttBuffer(i+1000);
//        usleep(10);
    }

}

void ExecutorCreator::outputThreadFunc(){
    OutputEmitter outputEmitter;
    while(DetailContainer::getExecutionFlag()) {
        outputEmitter.emitData(bufferContainer);
    }
}

void ExecutorCreator::createThreads(ExecutorCreator* executorCreator){
    bufferContainer = new BufferContainer();
    thread t[numberOfOutputAttributes];
    for (int i = 0; i < numberOfOutputAttributes; ++i) {
        t[i] = std::thread(&ExecutorCreator::run, executorCreator, i);
    }
    thread th = thread(&ExecutorCreator::tempFunc, executorCreator);
    thread outputThread = thread(&ExecutorCreator::outputThreadFunc,executorCreator);
    for (int i = 0; i < numberOfOutputAttributes; ++i) {
        t[i].join();
    }
    th.join();
    //outputThread.join();
    delete bufferContainer;

}

BufferContainer* ExecutorCreator::getBufferContainer() {
    return bufferContainer;
}
