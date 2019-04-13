#include "common.h"
#include "Buffer.h"
#include "CommonType.h"
#include "iostream"
#include "Executor.h"

class BufferContainer {
public : 
BufferContainer();
	void pushWeight(int value);
	void processLogicweight();
	void processLogictotalWeight();
	void executeProcess(int option);
	Buffer<int> weightBuffer;
	Executor executor0;
	Executor executor1;
};
