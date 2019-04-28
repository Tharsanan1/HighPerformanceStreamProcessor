#ifndef STREAM_PROCESSOR_PROCESSEDTHREADHANDLER_H
#define STREAM_PROCESSOR_PROCESSEDTHREADHANDLER_H
#include "common.h"

class ProcessedThreadHandler {
public : 
ProcessedThreadHandler();
	static void setAllDefault(int consumerIndex,int  inputIndex);
	static void setValueForInputAndConsumer(bool value,int consumerIndex,int  inputIndex);
	static bool getValueForInputAndConsumer(int consumerIndex,int  inputIndex);
	static bool boolArrayWeight1[2];
	static bool boolArrayWeight2[1];
};

#endif