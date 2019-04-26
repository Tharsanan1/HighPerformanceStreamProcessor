#include "BufferContainer.h"
BufferContainer::BufferContainer(){
}mutex BufferContainer::mutexForPopPushLock[constants::inputAttributeCount];
void BufferContainer::pushWeightBuffer(int value){
weightBuffer.push(value);
}
int BufferContainer::getFromWeightBuffer(int consumerIndex){
unique_lock<mutex> lock(mutexForPopPushLock[0]);
if(BufferLocker::canPopData(0, consumerIndex, &lock)){
return weightBuffer.pop();
}
else{
return weightBuffer.front();
}
}
void BufferContainer::pushWeighttBuffer(int value){
weighttBuffer.push(value);
}
int BufferContainer::getFromWeighttBuffer(int consumerIndex){
unique_lock<mutex> lock(mutexForPopPushLock[1]);
if(BufferLocker::canPopData(1, consumerIndex, &lock)){
return weighttBuffer.pop();
}
else{
return weighttBuffer.front();
}
}
void BufferContainer::processLogic0(){
int weight = getFromWeightBuffer(0);
Executor::executeWeight(weight );
}
void BufferContainer::processLogic1(){
int weight = getFromWeightBuffer(1);
Executor::executeTotalWeight(weight );
}
void BufferContainer::processLogic2(){
int weightt = getFromWeighttBuffer(2);
Executor::executeTotalWeightt(weightt );
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
int BufferContainer::getFromWeightOutputBuffer(){
return weightOutputBuffer.pop();

}
void BufferContainer::pushWeightOutputBuffer(int value){
weightOutputBuffer.push(value);
}
long BufferContainer::getFromTotalWeightOutputBuffer(){
return totalWeightOutputBuffer.pop();

}
void BufferContainer::pushTotalWeightOutputBuffer(long value){
totalWeightOutputBuffer.push(value);
}
long BufferContainer::getFromTotalWeighttOutputBuffer(){
return totalWeighttOutputBuffer.pop();

}
void BufferContainer::pushTotalWeighttOutputBuffer(long value){
totalWeighttOutputBuffer.push(value);
}
