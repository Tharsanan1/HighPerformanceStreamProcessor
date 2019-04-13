#include "BufferContainer.h"
BufferContainer::BufferContainer(){
}void BufferContainer::pushWeight(int value){
weightBuffer.push(value);
}
void BufferContainer::processLogicweight(){
int weight = weightBuffer.pop();
executor0.performMathLogic(int weight );
}
void BufferContainer::processLogictotalWeight(){
int weight = weightBuffer.pop();
executor1.performMathLogic(int weight );
}
void BufferContainer::executeProcess(int option){
switch(option) {
case 0 : processLogic0();
case 1 : processLogic1();
}
}
