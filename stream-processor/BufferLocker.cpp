//
// Created by tharsanan on 4/17/19.
//

#include <iostream>
#include "BufferLocker.h"
#include "BufferContainer.h"


condition_variable BufferLocker::m_condVar[constants::inputAttributeCount];
mutex BufferLocker::mutexForPopPushLock[constants::inputAttributeCount];
vector<int> BufferLocker::processedConsumerList[constants::inputAttributeCount];
mutex BufferLocker::cout_mutex;


bool BufferLocker::canPopData(int inputIndex, int consumerIndex,unique_lock<mutex>* locker){
    //unique_lock<mutex> locker(BufferContainer::mutexForPopPushLock[inputIndex]);
    while(!isNew(processedConsumerList[inputIndex], consumerIndex)){
        m_condVar[inputIndex].wait(*locker);

    }
    processedConsumerList[inputIndex].push_back(consumerIndex);
    if(processedConsumerList[inputIndex].size() == DetailContainer::getDependentConsumerCountForInput(inputIndex)){
        processedConsumerList[inputIndex].clear();
//        cout << this_thread::get_id() << " this thread will pop." << "\n";
        m_condVar[inputIndex].notify_all();

        return true;
    }
    else{
//        cout << this_thread::get_id() << " this thread will read." << "\n";
        return false;
    }
}

bool BufferLocker::isNew(vector<int> vec, int val){
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i] == val){
            return false;
        }
    }
    return true;

}