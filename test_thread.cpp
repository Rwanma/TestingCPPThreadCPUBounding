// TESTING A CONSUMER - PRODUCER architecture using a shared container and threads that are bound to CPUs
// TO BUILD THE PROJECT: Run make in the makefile directory
//  RUN THE PROJECT : ./test_thread in the binaries directory
// You can check CPU use climb to 100% when you remove the shared data IO.

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <mutex>

#include "DataStructure/container.hpp"


void wait(int seconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds));
}

void addDataToContainerthread()
{
  int i = 0;
  Container container;
  while(true)
  {
    // if you want to test the CPU exhaustion on your computer remove the 2 lines below. CPU work is slowed down by IO
    wait(1);
    container.addToQueue(7);
  }
}

void removeDataFromContainerThread()
{
  int i = 0;
  Container container;
  while(true)
  {
      // if you want to test the CPU exhaustion on your computer remove the 2 lines below. CPU work is slowed down by IO
     wait(1);
     container.removeFromQueue();
  }
}

int main()
{

    std::thread t1{addDataToContainerthread};
    std::thread t2{removeDataFromContainerThread};

    int core_one = 0, core_two=4;
    cpu_set_t cpuset1;
    cpu_set_t cpuset2;
    CPU_ZERO(&cpuset1);
    CPU_ZERO(&cpuset2);
    CPU_SET(core_one, &cpuset1);
    CPU_SET(core_two, &cpuset2);

    int rc1 = pthread_setaffinity_np(t1.native_handle(), sizeof(cpu_set_t), &cpuset1);
    int rc2 = pthread_setaffinity_np(t2.native_handle(), sizeof(cpu_set_t), &cpuset2);

    t1.join();
    t2.join();
}
