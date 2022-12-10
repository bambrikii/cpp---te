#include <cstddef>
#include <iostream>

void print_on_exit() {
    std::cout << "exiting" << std::endl;
}

int main(int argc, char const* argv[])
{
    void* ref1 = NULL;
    void* ref2 = nullptr;
    size_t size = 1;

    std::atexit(&print_on_exit);
    // std::abort();
    std::cout << "last line" << std::endl;

    return EXIT_SUCCESS;
}
