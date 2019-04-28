//
// Created by tharsanan on 4/17/19.
//

#include "BufferLocker.h"

condition_variable BufferLocker::m_condVar[constants::inputAttributeCount];
mutex BufferLocker::mutexForPopPushLock[constants::inputAttributeCount];
vector<int> BufferLocker::processedConsumerList[constants::inputAttributeCount];
mutex BufferLocker::cout_mutex;


bool BufferLocker::canPopData(int inputIndex, int consumerIndex,unique_lock<mutex>* locker){
    while(!ProcessedThreadHandler::getValueForInputAndConsumer(inputIndex, consumerIndex)){
        m_condVar[inputIndex].wait(*locker);

    }
    ProcessedThreadHandler::setValueForInputAndConsumer(inputIndex,consumerIndex,false);
    if(ProcessedThreadHandler::allSet(inputIndex)){
        ProcessedThreadHandler::setAllDefault(inputIndex);
        m_condVar[inputIndex].notify_one();

        return true;
    }
    else{
        return false;
    }
//    while(!isNew(processedConsumerList[inputIndex], consumerIndex)){
//        m_condVar[inputIndex].wait(*locker);
//
//    }
//    processedConsumerList[inputIndex].push_back(consumerIndex);
//    if(processedConsumerList[inputIndex].size() == DetailContainer::getDependentConsumerCountForInput(inputIndex)){
//        processedConsumerList[inputIndex].clear();
//        m_condVar[inputIndex].notify_one();
//
//        return true;
//    }
//    else{
//        return false;
//    }

}

bool BufferLocker::isNew(vector<int> vec, int val){
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i] == val){
            return false;
        }
    }
    return true;

}

mutex* BufferLocker::getCoutLock() {
    return &cout_mutex;
}
