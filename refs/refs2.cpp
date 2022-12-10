#include <string>
#include <iostream>

void print(std::string* str1) {
    std::cout << *str1 << std::endl;
}

void del(std::string* str1) {
    delete str1;
}

int main(int argc, char const* argv[])
{
    std::string* str1 = new std::string("123");

    print(str1);
    print(str1);
    del(str1);

    return 0;
}
