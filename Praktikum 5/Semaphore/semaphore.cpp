#include "semaphore.h"

void Semaphore::release()
{

    std::unique_lock<std::mutex> lock(mutex);

    count++;

    std::cout << "Thread finished" << std::endl;

    con_var.notify_one();
}

void Semaphore::acquire()
{

    std::unique_lock<std::mutex> lock(mutex);

    if (count == 0)
    {
        std::cout << "Thread waiting: ";
        con_var.wait(lock);
        std::cout << "Thread starting: " << std::endl;
    }

    count--;
}