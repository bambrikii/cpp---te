#include <chrono>
#include <iostream>
#include <string>

std::time_t makeTime(int year, int mon, int day, int hour, int min, int sec = 0)
{
    struct std::tm t;
    t.tm_sec = sec;     // second of minute (0 .. 59 and 60 for leap seconds)
    t.tm_min = min;    // minute of hour (0 .. 59)
    t.tm_hour = hour;    // hour of day (0 .. 23)
    t.tm_mday = day;    // day of month (0 .. 31)
    t.tm_mon = mon - 1;    // month of year (0 .. 11)
    t.tm_year = year - 1900; // year since 1900
    t.tm_isdst = -1;    // determine whether daylight saving time
    std::time_t tt = std::mktime(&t);
    if (tt == -1) {
        throw "no valid system time";
    }
    return tt;
}

std::chrono::system_clock::time_point makeTimePoint(int year, int mon, int day, int hour, int min, int sec = 0)
{
    std::time_t tt = makeTime(year, mon, day, hour, min, sec);
    if (tt == -1) {
        throw "no valid system time";
    }
    return std::chrono::system_clock::from_time_t(tt);
}

int main(int argc, char const* argv[])
{
    std::chrono::system_clock::time_point timePoint = makeTimePoint(2022, 11, 23, 23, 44, 03);

    std::time_t time = makeTime(2022, 11, 23, 23, 44, 03);
    std::string timeStr = ctime(&time);
    timeStr.resize(timeStr.length() - 1);
    std::cout << timeStr << std::endl;

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(now);
    std::string nowStr = ctime(&nowTime);
    nowStr.resize(nowStr.length() - 1);
    std::cout << nowStr << std::endl;

    return 0;
}
