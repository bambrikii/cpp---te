#include <iostream>

class Test
{
public:
    Test() { std::cout << "Created    " << this << "\n"; }
    ~Test() { std::cout << "Destroyed  " << this << "\n"; }
    Test(Test const& rhs) { std::cout << "Copied     " << this << "\n"; }
    Test& operator=(Test const& rhs) { std::cout << "Assigned   " << this << "\n"; }
};

void method1(Test* test) {
    std::cout << "Method1    " << test << std::endl;
}

void method2(Test test) {
    std::cout << "Method2    " << &test << std::endl;
}

int main(int argc, char const* argv[])
{
    Test test1 = Test();
    {
        Test test4 = Test();
    }
    Test test2 = test1;
    Test* test3 = &test2;
    method1(test3);
    method2(test1);
    return 0;
}
