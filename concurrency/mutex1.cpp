#include <string>
#include <mutex>
#include <string>
#include <thread>
#include <future>
#include <iostream>
#include <chrono>

using namespace std;

void no_mutex_print(const string &str)
{
    for (char ch : str)
    {
        cout << ch;
    }
    cout << endl;
}

void no_mutex_method()
{
    cout << "Print with no mutex:" << endl;
    auto f1 = async(launch::async, no_mutex_print, "thread one");
    auto f2 = async(launch::async, no_mutex_print, "thread two");
    no_mutex_print("main thread");
}

mutex mtx;

void mutex_print(const string str)
{
    lock_guard lg(mtx); // RAII - Resource Ackuisition Is Initialization
    for (char ch : str)
    {
        cout << ch;
    }
    cout << endl;
}

void mutex_method()
{
    cout << "Print with mutex:" << endl;
    auto f1 = async(launch::async, mutex_print, "thread one");
    auto f2 = async(launch::async, mutex_print, "thread two");
    mutex_print("main thread");
}

recursive_mutex recursive_mtx;

void recursive_method1(int i)
{
    if (i > 5)
    {
        return;
    }
    lock_guard<recursive_mutex> m(recursive_mtx);
    cout << "recursive mutex " << i << endl;
    // auto f1 = async(launch::async, recursive_method1, i + 1); // this will deadlock
    recursive_method1(i + 1);
}

timed_mutex timed_mtx;

void lock_for(int i)
{
    cout << "lock for, #" << i << endl;
    timed_mtx.try_lock_for(chrono::seconds(1));
    // lock_guard<timed_mutex> m(timed_mtx);
    if (i >= 3)
    {
        return;
    }
    lock_for(i + 1);
}

mutex mutex1;
mutex mutex2;

void lock_multiple()
{
    cout << "lock multiple:" << endl;
    lock(mutex1, mutex2);
}

void try_lock_multiple()
{
    cout << "try lock multiple:" << endl;
    try_lock(mutex1, mutex2);
}

int main(int argc, char const *argv[])
{
    no_mutex_method();
    mutex_method();
    recursive_method1(0);
    lock_for(0);
    lock_multiple();
    try_lock_multiple();

    return 0;
}
