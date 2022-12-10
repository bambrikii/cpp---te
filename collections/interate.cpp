#include <vector>
#include <iostream>

int main(int argc, char const* argv[])
{
    std::vector vector1 = { 1, 2, 3 };
    for (const auto i : vector1)
    {
        std::cout << i << std::endl;
    }

    for (const auto& i : vector1)
    {
        std::cout << i << std::endl;
    }

    for (const auto& i : vector1)
    {
        std::cout << ((int*)i) << std::endl;
    }

    return 0;
}
