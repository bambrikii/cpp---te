#include <string>
#include <iostream>
#include <utility>

class Cls1 {
private:
    int prop1 = 1;
    std::string str1;
public:
    Cls1(int prop1, std::string str1) : prop1(prop1), str1(str1) {

    }
    void print() {
        std::cout << this->prop1 << " " << this->str1 << std::endl;
    }
    ~Cls1() {
    }
};

struct Struct1 {
    int prop1 = 1;
    std::string str1;
    void print() {
        std::cout << this->prop1 << " " << this->str1 << std::endl;
    }
};

void print2(Cls1& cls1) {
    cls1.print();
}

void print2(Cls1* cls1) {
    cls1->print();
}

int main(int argc, char** argv) {
    std::string ch1 = "123";
    Cls1 cls1 = { 1, ch1 };
    cls1.print();
    print2(cls1);
    print2(&cls1);

    Struct1 struct1 = { 1, "2" };
    cls1.print();

    return 0;
}