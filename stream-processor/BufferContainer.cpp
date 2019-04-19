#include "BufferContainer.h"
BufferContainer::BufferContainer(){
}mutex BufferContainer::mutexForPopPushLock[constants::inputAttributeCount];
void BufferContainer::pushWeight(int value){
weightBuffer.push(value);
}
int BufferContainer::getFromWeight(int consumerIndex){
unique_lock<mutex> lock(mutexForPopPushLock[0]);
if(BufferLocker::canPopData(0, consumerIndex, &lock)){
return weightBuffer.pop();
}
else{
return weightBuffer.front();
}
}
void BufferContainer::pushWeightt(int value){
weighttBuffer.push(value);
}
int BufferContainer::getFromWeightt(int consumerIndex){
unique_lock<mutex> lock(mutexForPopPushLock[1]);
if(BufferLocker::canPopData(1, consumerIndex, &lock)){
return weighttBuffer.pop();
}
else{
return weighttBuffer.front();
}
}
void BufferContainer::processLogic0(){
int weight = getFromWeight(0);
Executor::performMathLogic0(weight );
}
void BufferContainer::processLogic1(){
int weight = getFromWeight(1);
Executor::performMathLogic1(weight );
}
void BufferContainer::processLogic2(){
int weightt = getFromWeightt(2);
//Executor::performMathLogic2(weightt );
}
void BufferContainer::executeProcess(int option){
switch(option) {
case 0 : processLogic0();
break;
case 1 : processLogic1();
break;
case 2 : processLogic2();
break;
}
}
