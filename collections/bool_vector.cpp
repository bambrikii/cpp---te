#include <vector>
#include <iostream>
#include <algorithm>

void print(std::vector<bool> v1) {
    for (auto i : v1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}

int main(int argc, char const* argv[])
{
    std::vector<bool> v1 = { true, false, true };
    print(v1);

    v1.flip();
    print(v1);

    v1[0].flip();
    v1[1] = false;
    print(v1);

    return 0;
}
