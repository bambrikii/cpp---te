#include <thread>
#include <future>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;

void future1()
{
    cout << "future1:" << endl;
    future<string> f2 = async([]() -> string
                              { 
                                    cout << "Thread 2 started" << endl;
                                    return "456"; });

    future<string> f1 = async([]() -> string
                              { 
                                cout << "Thread 1 started" << endl;
                                return "123"; });
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "Main thread" << endl;
    cout << f1.get() << f2.get() << endl;
}

void defer1()
{
    cout << "defer1:" << endl;
    future<string> f1 = async(launch::async, []() -> string
                              { 
                                cout << "Thread 1 started" << endl;
                                this_thread::sleep_for(chrono::microseconds(5));
                                return "123"; });

    future<string> f2 = async(launch::deferred, []() -> string
                              { 
                                    cout << "Thread 2 started" << endl;
                                this_thread::sleep_for(chrono::microseconds(5));
                                    return "456"; });

    while (f1.wait_for(chrono::seconds(0)) != future_status::ready &&
           f2.wait_for(chrono::seconds(0)) != future_status::ready)
    {
        cout << "Not ready" << endl;
        if (f1.wait_for(chrono::seconds(0)) != future_status::deferred ||
            f2.wait_for(chrono::seconds(0)) != future_status::deferred)
        {
            cout << "Not deferred" << endl;
        }
        else
        {
            cout << "Yeild" << endl;
            this_thread::yield();
        }
    }

    cout << "Completed" << endl;
    cout << f1.get() << f2.get() << endl;
}

int main(int argc, char const *argv[])
{
    future1();
    defer1();
    return 0;
}
