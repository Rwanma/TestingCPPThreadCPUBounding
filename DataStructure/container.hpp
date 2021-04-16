#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <mutex>


class Container
{
private:
    static std::vector<int> vectData;
    static std::queue<int> myQueue;
    static std::mutex mutex;

public:

    //static int addToVectorStatic() { return s_value; } // static member function

    Container();
    void addToVector(int);
    void addToQueue(int);
    int removeFromQueue();
    int getSize();
};


#endif