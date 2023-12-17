#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

class Semaphore
{
public:
    Semaphore(int m) : count(m) {}

    void acquire();
    void release();

private:
    int count;
    std::mutex mutex;
    std::condition_variable con_var;
};