#include "container.hpp"
#include <iostream>

std::vector<int> Container::vectData;
std::queue<int> Container::myQueue;
std::mutex Container::mutex;


// Date constructor
Container::Container()
{}


void Container::addToVector(int number)
{
    using std::this_thread::get_id;
    std::lock_guard<std::mutex> lock{mutex};
    Container::vectData.push_back(number);
    std::cout << "Thread " << get_id() << ": " << number << ": on CPU " << sched_getcpu()  << " ---- size : " << Container::vectData.size() << std::endl;
}


void Container::addToQueue(int number)
{


    using std::this_thread::get_id;
    std::lock_guard<std::mutex> lock{mutex};
    Container::myQueue.push(number);
    std::cout << "Thread " << get_id() << ": " << number << ": on CPU " << sched_getcpu()  << " adding data  ---- size : " << Container::myQueue.size() << std::endl;
}


int Container::removeFromQueue()
{
    using std::this_thread::get_id;
    std::lock_guard<std::mutex> lock{mutex};
    std::cout << "Thread " << get_id() << ": " << ": on CPU " << sched_getcpu() << " removing data ---- size : " << Container::myQueue.size() << std::endl;

    if (!Container::myQueue.empty())
    {
        Container::myQueue.pop();
    }
    return 0;
}


int Container::getSize()
{
    std::lock_guard<std::mutex> lock{mutex};
    return Container::vectData.size();
}
