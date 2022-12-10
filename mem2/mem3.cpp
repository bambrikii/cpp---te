#include <iostream>
#include <string>

class Cls1 {
private:
    std::string* prop1;
public:
    Cls1(std::string* prop1) : prop1(prop1) {
        std::cout << "Creating..." << std::endl;
        std::cout << *prop1 << std::endl;
    }

    ~Cls1() {
        std::cout << "Deleting..." << std::endl;
        std::cout << *prop1 << std::endl;
    }
};

int main(int argc, char const* argv[])
{
    std::string str1 = "val1";
    std::string* str2 = &str1;
    {
        Cls1 cls1 = Cls1(&str1);
    }
    std::cout << "main.1. " << str1 << std::endl;
    {
        Cls1 cls2 = Cls1(str2);
    }
    std::cout << "main.2. " << str1 << std::endl;
    return EXIT_SUCCESS;
}
