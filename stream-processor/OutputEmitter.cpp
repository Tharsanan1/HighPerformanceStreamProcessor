#include "OutputEmitter.h"
OutputEmitter::OutputEmitter(){
}void OutputEmitter::emitData(BufferContainer* bufferContainer){
long totalWeight = bufferContainer->getFromTotalWeightOutputBuffer();
long totalWeightt = bufferContainer->getFromTotalWeighttOutputBuffer();
int weight = bufferContainer->getFromWeightOutputBuffer();
    PerformanceMonitor::getElapsedTime();
//if(weight == 99999){
//    PerformanceMonitor::getElapsedTime();
//}
}