#include <iostream>
#include <string>

void method1(std::string* str1) {
    delete str1;
}

int main(int argc, char const* argv[])
{
    {
        std::string* str1 = new std::string("123");
        std::string str2 = std::string("123");
        std::cout << "str1: " << str1 << " " << *str1 << std::endl;
        std::cout << "str2: " << &str2 << " " << str2 << std::endl;
        method1(str1);
        // method1(&str2);
        std::cout << "str1: " << str1 << " " << std::endl;
    }

    return EXIT_SUCCESS;
}
