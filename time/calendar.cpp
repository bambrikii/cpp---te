#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

// https://stackoverflow.com/questions/52238978/creating-a-stdchronotime-point-from-a-calendar-date-known-at-compile-time

#define DAY 9
#define MONTH 1
#define YEAR 2014

int main(int argc, char** argv) {
    std::tm tm = { /* .tm_sec  = */ 0,
        /* .tm_min  = */ 0,
        /* .tm_hour = */ 0,
        /* .tm_mday = */ (DAY),
        /* .tm_mon  = */ (MONTH)-1,
        /* .tm_year = */ (YEAR)-1900,
    };
    tm.tm_isdst = -1;

    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = ctime(&t);

    std::cout << ts << std::endl;

    return 0;
}
