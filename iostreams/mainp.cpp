#include <iostream>
#include <iomanip>
#include <ctime>
#include "manip_templates.hpp"

void fill_width()
{
    std::cout << std::setw(6) << std::setfill('_');
    std::cout << "012" << std::endl;
}

void overfill()
{
    std::cout << std::setw(6) << std::setfill('_');
    std::cout << "0123456" << std::endl;

    std::cout << "345" << std::endl;
}

void sci_fill_left()
{
    std::cout << std::setw(32) << std::left << std::scientific << std::setfill('_');
    std::cout << 1.23 << std::endl;
}

void sci_fill_right_hex()
{
    std::cout << std::setw(32) << std::right << std::internal << std::hexfloat << std::setfill('_');
    std::cout << 1.23 << std::endl;
}

void time1()
{
    std::time_t now = std::time(nullptr);
    std::tm time = *std::localtime(&now);

    std::cout << std::put_time(&time, "%c %Z") << std::endl;

    std::cout.imbue(std::locale("ru_RU.utf8"));
    std::cout << std::put_time(&time, "%c %Z") << std::endl;
}

void custom_out()
{
    std::cout << "some_string / " << print_ws << " / " << print_now << " / " << std::endl;
}

void bool1()
{
    bool b = true;
    std::cout << std::noboolalpha << b << " == "
              << std::boolalpha << b << std::endl;
}

int main(int argc, char const *argv[])
{
    fill_width();
    overfill();
    sci_fill_left();
    sci_fill_right_hex();
    time1();

    custom_out();

    bool1();

    std::cout << std::flush;

    return 0;
}
