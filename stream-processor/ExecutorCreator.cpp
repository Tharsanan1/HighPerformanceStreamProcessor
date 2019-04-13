//
// Created by tharsanan on 4/13/19.
//

#include "ExecutorCreator.h"

ExecutorCreator::ExecutorCreator(){
    numberOfOutputAttributes = DetailContainer.getNumberOfOutputAttributes();
}

void ExecutorCreator::createThreads(){
    BufferContainer* bufferContainer = new BufferContainer();
    std::thread t[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(&BufferContainer::executeProcess, bufferContainer, i);
    }
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }
    delete bufferContainer;

}