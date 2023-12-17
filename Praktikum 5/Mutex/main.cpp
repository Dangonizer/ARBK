#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

std::mutex mutex;

void thread1()
{
    mutex.lock();

    for (char c = 'a'; c <= 'z'; c++)
    {
        std::cout << c << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
    mutex.unlock();
}

void thread2()
{
    mutex.lock();

    for (short i = 0; i <= 32; i++)
    {
        std::cout << i << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
    mutex.unlock();
}

void thread3()
{
    mutex.lock();

    for (char c = 'A'; c <= 'Z'; c++)
    {
        std::cout << c << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
    mutex.unlock();
}

int main()
{

    std::cout << "Start Threads" << std::endl;

    std::thread T1(thread1);
    std::thread T2(thread2);
    std::thread T3(thread3);

    T1.join();
    T2.join();
    T3.join();

    std::cout << "Threads finished" << std::endl;

    return 0;
}
