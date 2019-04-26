#include "Executor.h"
Executor::Executor(){
}Sum<long> Executor::sumWeightTotalWeight;
Sum<long> Executor::sumWeighttTotalWeightt;
void Executor::executeWeight(int weight){
ExecutorCreator::getBufferContainer()->pushWeightOutputBuffer(weight);
}
void Executor::executeTotalWeight(int weight){
ExecutorCreator::getBufferContainer()->pushTotalWeightOutputBuffer(sumWeightTotalWeight.getSum(weight));
}
void Executor::executeTotalWeightt(int weightt){
ExecutorCreator::getBufferContainer()->pushTotalWeighttOutputBuffer(sumWeighttTotalWeightt.getSum(weightt));
}
