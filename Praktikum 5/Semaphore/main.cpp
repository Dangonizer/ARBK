#include "semaphore.h"
#include <unistd.h>

Semaphore s(1);

void thread1()
{
    s.acquire();
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        std::cout << letter << ", ";
        sleep(0.01);
    }

    std::cout << std::endl;

    s.release();
}

void thread2()
{
    s.acquire();

    for (short number = 0; number <= 32; number++)
    {
        std::cout << number << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;

    s.release();
}

void thread3()
{
    s.acquire();

    for (char letter = 'A'; letter <= 'Z'; letter++)
    {
        std::cout << letter << ", ";
        sleep(0.01);
    }
    std::cout << std::endl;

    s.release();
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
