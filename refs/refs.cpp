#include <iostream>

void method1(char* str1);

void method2(char*& str1) {
    std::cout << (str1) << std::endl;
}

int main(int argc, char** argv) {
    char* str1 = "str1";
    method1(str1);

    char* str2 = "str2";

    method2(str2);
    return 0;
}

void method1(char* str1) {
    std::cout << (str1) << std::endl;
}