#include <iostream>
#include <chrono>
#include <thread>

void print_time() {
    auto now = std::chrono::system_clock::now();
    auto now_t = std::chrono::system_clock::to_time_t(now);
    auto now_str = ctime(&now_t);
    std::cout << now_t << " - " << now_str << std::endl;
}

int main(int argc, char const* argv[])
{
    using namespace std::chrono_literals;

    print_time();

    // Sleep for
    std::cout << "sleeping for 3000 ms" << std::endl;
    std::this_thread::sleep_for(3000ms);

    print_time();

    // Sleep until
    auto now = std::chrono::system_clock::now();
    auto now_tp = now += std::chrono::seconds(3);
    auto now_t = std::chrono::system_clock::to_time_t(now_tp);
    auto now_str = ctime(&now_t);
    std::cout << "sleeping until " << now_str << " ms, " << now_t << std::endl;
    std::this_thread::sleep_until(now_tp);

    print_time();

    return 0;
}
