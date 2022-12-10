#include <iostream>

template <typename charT, typename traits>
inline std::basic_ostream<charT, traits> &
print_ws(std::basic_ostream<charT, traits> &strm)
{
    strm.write("www", 3);
    return strm;
}

template <typename charT, typename traits>
inline std::basic_ostream<charT, traits> &
print_now(std::basic_ostream<charT, traits> &strm)
{
    std::time_t now = std::time(nullptr);
    const std::tm time = *std::localtime(&now);
    char buffer[32];

    std::strftime(buffer, 32, "%Y-%m-%d_%H:%M:%S (%a, %Z)" + '\0', &time);

    strm.write(buffer, sizeof(buffer));
    return strm;
}
