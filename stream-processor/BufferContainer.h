#ifndef STREAM_PROCESSOR_BUFFERCONTAINER_H
#define STREAM_PROCESSOR_BUFFERCONTAINER_H
#include "common.h"
#include "Buffer.h"
#include "iostream"
#include "Executor.h"
#include "BufferLocker.h"

class BufferContainer {
public : 
BufferContainer();
	void pushWeightBuffer(int value);
	int getFromWeightBuffer(int consumerIndex);
	void pushWeighttBuffer(int value);
	int getFromWeighttBuffer(int consumerIndex);
	void processLogic0();
	void processLogic1();
	void processLogic2();
	void executeProcess(int option);
	int getFromWeightOutputBuffer();
	void pushWeightOutputBuffer(int value);
	long getFromTotalWeightOutputBuffer();
	void pushTotalWeightOutputBuffer(long value);
	long getFromTotalWeighttOutputBuffer();
	void pushTotalWeighttOutputBuffer(long value);
	Buffer<int> weightBuffer;
	Buffer<int> weighttBuffer;
	static mutex mutexForPopPushLock[constants::inputAttributeCount];
	Buffer<int> weightOutputBuffer;
	Buffer<long> totalWeightOutputBuffer;
	Buffer<long> totalWeighttOutputBuffer;
};

#endif