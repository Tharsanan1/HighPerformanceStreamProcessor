cmake_minimum_required(VERSION 3.13)
project(ProducerConsumer)

set(CMAKE_CXX_STANDARD 14)


SET(CMAKE_CXX_FLAGS -pthread)

add_executable(ProducerConsumer main.cpp Buffer.cpp Consumer.cpp Producer.cpp)