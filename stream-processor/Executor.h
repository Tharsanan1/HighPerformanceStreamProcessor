#ifndef STREAM_PROCESSOR_EXECUTOR_H
#define STREAM_PROCESSOR_EXECUTOR_H
#include "common.h"
#include "Sum.h"
#include "Sum.h"
#include "ExecutorCreator.h"

class Executor {
public : 
Executor();
	static void executeWeight(int weight);
	static void executeTotalWeight(int weight);
	static void executeTotalWeightt(int weightt);
	static Sum<long> sumWeightTotalWeight;
	static Sum<long> sumWeighttTotalWeightt;
};

#endif