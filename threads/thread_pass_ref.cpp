#include <thread>
#include <future>
#include <string>
#include <iostream>
#include <chrono>

using namespace std;

future<int> func2(string &param1)
{
    string str2 = param1 + "-2";
    future<int> f2 = async([&/*=*/]() -> int
                           {
                   for (int i = 0; i < 2; i++)
                   {
                       cout << "waiting... " << i << " " << str2 << endl;
                       this_thread::sleep_for(chrono::microseconds(1));
                   }
                   cout << "returning f2... " << endl;
                   return 0; });
    this_thread::sleep_for(chrono::microseconds(1));
    cout << "exiting parent... " << endl;
    return f2;
}

void funct1()
{
    cout << "passing a reference to thread:" << endl;
    string str2 = "param1";
    future<int> f2 = func2(str2);
    cout << "funct2 " << f2.get() << endl;
}

void call_object_method1()
{
    cout << "calling object method1:" << endl;
    class Cls1
    {
    public:
        void method1(int val)
        {
            cout << "method1 " << val << endl;
        }
    };

    Cls1 cls1;
    future<void> f1 = async(&Cls1::method1, cls1, 1);
    f1.get();
}

string share_func1(shared_future<string> f)
{
    string val = f.get();
    cout << val << endl;
    return val;
}

void shared_future1()
{
    cout << "Shared future:" << endl;
    shared_future<string> f = async([]() -> string
                                    { return "str1"; })
                                  .share();
    future<string> f1 = async(launch::async, share_func1, f);
    future<string> f2 = async(launch::async, share_func1, f);
    cout << " shared result: " << f1.get() << ", " << f2.get() << endl;
}

void share_func_with_exception(shared_future<string> f)
{
    try
    {
        f.get();
    }
    catch (invalid_argument &ex)
    {
        cerr << "invalid_argument " << this_thread::get_id() << " " << ex.what() << endl;
        throw ex;
    }
}

void shared_future_with_exception1()
{
    cout << "Shared future with exception:" << endl;
    shared_future<string> f = async([]() -> string
                                    { throw invalid_argument("failed"); });
    future<void> f1 = async(launch::async, share_func_with_exception, f); // exception as return is repeated
    future<void> f2 = async(launch::async, share_func_with_exception, f); // exception as return is repeated
}

void lower_level_thread()
{
    cout << "lower level thread:" << endl;
    thread t1([]()
              {
                  cout << " in thread 1" << endl;
                  //   throw invalid_argument("in thread 1 invalid argument");
              });
    t1.join();
}

int main(int argc, char const *argv[])
{
    call_object_method1();
    shared_future1();
    shared_future_with_exception1();
    lower_level_thread();
    funct1();
    return 0;
}
