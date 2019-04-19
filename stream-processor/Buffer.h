//
// Created by tharsanan on 4/5/19.
//

#ifndef STREAM_PROCESSOR_BUFFER_H
#define STREAM_PROCESSOR_BUFFER_H


#include <queue>
#include <thread>
#include <cstdlib>
#include <stdexcept>
#include <mutex>
#include <condition_variable>
#include <zconf.h>
#include "iostream"
#include "BufferLocker.h"

using namespace std;

template <class T>
class Buffer{
private:
    condition_variable m_condVar;
    mutex mutexForPopPushLock;
    queue<T>* bufferQueue;

public:
    Buffer();
    T back();
    T front();
    T pop();
    void push(T const&);
};

template <class T>
Buffer<T>::Buffer(){
    bufferQueue = new queue<T>();
}

template <class T>
T Buffer<T>::back(){
    if (bufferQueue->empty()) {
        //throw out_of_range("Queue<>::back(): empty Queue");
        cout << "minus one is read size is : " << bufferQueue->size() << "\n";
        return -1;
    }
    BufferLocker::cout_mutex.lock();
    cout << bufferQueue->back() << " is read size is : " << bufferQueue->size() << "\n";
    BufferLocker::cout_mutex.unlock();
    return bufferQueue->back();
}

template <class T>
T Buffer<T>::front(){
    unique_lock<mutex> locker(mutexForPopPushLock);
    while(bufferQueue->empty()){
        m_condVar.wait(locker);
    }
    T value = bufferQueue->front();
    BufferLocker::cout_mutex.lock();
    cout << this_thread::get_id() << " this thread have read " << value << "\n";
    BufferLocker::cout_mutex.unlock();
//    cout << value << " is front, size is : " << bufferQueue->size() << "\n";
    locker.unlock();
    return value;
}

template <class T>
T Buffer<T>::pop(){
    unique_lock<mutex> locker(mutexForPopPushLock);
    while(bufferQueue->empty()){
        m_condVar.wait(locker);
    }
    T value = bufferQueue->front();
    bufferQueue->pop();
    BufferLocker::cout_mutex.unlock();
    cout << this_thread::get_id() << " this thread have popped " << value << "\n";
    BufferLocker::cout_mutex.unlock();
//        if(value == 99999) {
//            cout << value << " is popped size is : " << bufferQueue->size() << "\n";
//}
    locker.unlock();
    return value;
}

template <class T>
void Buffer<T>::push(T const& value){
    unique_lock<mutex> locker(mutexForPopPushLock);
    bufferQueue->push(value);
    locker.unlock();
    m_condVar.notify_all();
}


#endif //STREAM_PROCESSOR_BUFFER_H
