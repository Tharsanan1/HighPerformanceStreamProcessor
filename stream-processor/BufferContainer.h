#include "common.h"
#include "Buffer.h"
#include "iostream"
#include "Executor.h"
#include "BufferLocker.h"

class BufferContainer {
public : 
BufferContainer();
	void pushWeight(int value);
	int getFromWeight(int consumerIndex);
	void pushWeightt(int value);
	int getFromWeightt(int consumerIndex);
	void processLogic0();
	void processLogic1();
	void processLogic2();
	void executeProcess(int option);
	Buffer<int> weightBuffer;
	Buffer<int> weighttBuffer;
	static mutex mutexForPopPushLock[constants::inputAttributeCount];
	Executor executor0;
	Executor executor1;
	Executor executor2;
};
