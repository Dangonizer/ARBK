#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

void thread1()
{

    for (char c = 'a'; c <= 'z'; c++)
    {
        std::cout << c << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
}

void thread2()
{

    for (short i = 0; i <= 32; i++)
    {
        std::cout << i << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
}

void thread3()
{

    for (char c = 'A'; c <= 'Z'; c++)
    {
        std::cout << c << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;
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
