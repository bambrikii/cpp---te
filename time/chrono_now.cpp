#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

std::string toString(const std::chrono::system_clock::time_point& tp) {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&time);
    ts.resize(ts.size() - 1);
    return ts;
}


int main(int argc, char** argv) {
    std::chrono::system_clock::time_point tp;

    std::cout << "def: " << toString(tp) << std::endl;

    tp = std::chrono::system_clock::now();
    std::cout << "now: " << toString(tp) << std::endl;

    tp = std::chrono::system_clock::time_point::min();
    std::cout << "min: " << toString(tp) << std::endl;

    tp = std::chrono::system_clock::time_point::max();
    std::cout << "max: " << toString(tp) << std::endl;

    return 0;
}