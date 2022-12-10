#include <iostream>
#include "multiply.hpp"
#include "heap/constructors.hpp"

int main(int argc, char **argv)
{
    int a = 2, b = 2;
    // std::cin >> a;
    // std::cin >> b;
    int c = multiply(a, b);
    std::cout << &a << std::endl
              << &b << std::endl
              << &c << std::endl
              << c << std::endl;

    int *a1 = &a;
    int *b1 = &b;
    int *d = multiplyRef(a1, b1);

    std::string str = "string1";

    std::cout << d << std::endl
              << d << std::endl;

    // std::cout << str << std::endl;
}