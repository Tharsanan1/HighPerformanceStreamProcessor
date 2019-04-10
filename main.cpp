#include <iostream>
#include "Consumer.h"
#include "Producer.h"
#include <thread>

using namespace std;
Buffer<int> buffer;

void thread_func_cons(){
    Consumer<int> consumer(&buffer);
    for (int i = 0; i < 1000; ++i) {
        consumer.pop();
    }
}

void thread_func_prod(){

}

int main() {
    Buffer<string> stringBuffer;
    Buffer<float> floatBuffer;


    thread consThread(thread_func_cons);
    thread prodThread(thread_func_prod);
    consThread.join();
    prodThread.join();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}