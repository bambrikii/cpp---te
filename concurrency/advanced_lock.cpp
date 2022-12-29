#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <chrono>
#include <future>

using namespace std;

bool flag1;
mutex mutex1;

void thread1()
{
    lock_guard<mutex> guard(mutex1);
    cout << "thread1: setting flag..." << endl;
    flag1 = true;
    cout << "thread1: flag set..." << endl;
}

void thread2()
{
    unique_lock<mutex> lock1(mutex1);
    cout << "thread2: starting..." << endl;
    while (!flag1)
    {
        cout << "thread2: unlocking..." << endl;
        lock1.unlock();
        cout << "thread2: yielding..." << endl;
        this_thread::yield();
        cout << "thread2: sleeping..." << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "thread2: locking..." << endl;
        lock1.lock();
    }
    cout << "thread2: done..." << endl;
}

void advanced_threads()
{
    auto f2 = async(launch::async, thread2);
    auto f1 = async(launch::async, thread1);
}

int main(int argc, char const *argv[])
{
    advanced_threads();

    return 0;
}
