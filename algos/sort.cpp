#include <iostream>
#include <vector>
#include <algorithm>

#include "create.hpp"

int main(int argc, char const* argv[])
{
    std::vector<int> vector = create_vector();
    std::sort(vector.begin(), vector.end(), [](const int left, const int right) {
        return left < right;
        });
    print(vector);

    return EXIT_SUCCESS;
}
