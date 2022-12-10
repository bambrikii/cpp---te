#include <iostream>

#ifndef DEF1
#define DEF1 1
void method1() {
    std::cout << "DEF 1" << std::endl;
}
#else
void method1() {
    std::cout << "DEF undef" << std::endl;
}

#endif

int main(int argc, char** argv) {
    method1();
    return 0;
}