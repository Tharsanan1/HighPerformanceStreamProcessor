//
// Created by tharsanan on 4/5/19.
//

#ifndef PRODUCERCONSUMER_BUFFER_H
#define PRODUCERCONSUMER_BUFFER_H


#include <queue>
#include <thread>
#include <cstdlib>
#include <stdexcept>
#include <mutex>
#include <condition_variable>
#include <zconf.h>
#include "iostream"

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
        throw out_of_range("Queue<>::back(): empty Queue");
    }
    return bufferQueue->back();
}

template <class T>
T Buffer<T>::pop(){
    unique_lock<mutex> locker(mutexForPopPushLock);
    if(bufferQueue->empty()){
        cout << "thread is going to wait\n";

        m_condVar.wait(locker);
        cout << "thread has been notified\n";
    }
    T value = bufferQueue->front();
    bufferQueue->pop();
    cout << value << " is popped size is : " << bufferQueue->size() << "\n";
    locker.unlock();
    //usleep(13);
    return value;
}

template <class T>
void Buffer<T>::push(T const& value){
    unique_lock<mutex> locker(mutexForPopPushLock);
    bufferQueue->push(value);
    cout << value << " going to notify " << "\n";
    locker.unlock();
    m_condVar.notify_all();
    //usleep(10);
}


#endif //PRODUCERCONSUMER_BUFFER_H
