#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include "constructors.hpp"

HeapClass1::HeapClass1(std::string *name0)
{
    name = std::string(*name0);

    std::cout << "Creating: " << name << " " << &name << " " << this << std::endl;
}

HeapClass1::HeapClass1(HeapClass1 &other) // : name(other.name)
{
    name = other.name;
    std::cout << "Copying: " << name << " " << &name << " " << this << std::endl;
}

HeapClass1::HeapClass1(HeapClass1 &&other)
{
    name = std::move(other.name);
    std::cout << "Moving: " << name << " " << &name << " <- " << &other.name << " " << this << std::endl;
}
HeapClass1::~HeapClass1()
{
    std::cout << "Destroying: " << name << " " << &name << " " << this << std::endl;
    // delete &name;
}
void HeapClass1::print()
{
    std::cout << name << " " << this << std::endl;
}

void constructorsMain()
{
    std::string str1 = "copy";
    std::string str2 = "move";
    {
        std::cout << "--- Explicit constructor with ref " << str1 << std::endl;
        HeapClass1 cls1 = HeapClass1(&str1);
    }
    {
        std::cout << "--- Implicit constructor with ref " << str1 << std::endl;
        HeapClass1 cls2 = &str1;
    }
    {
        std::cout << "--- Implicit constructor with ref " << str2 << std::endl;
        HeapClass1 cls3 = &str2;

        std::cout << "--- Copy constructor with ref " << str2 << std::endl;
        HeapClass1 cls4 = HeapClass1(cls3);

        std::cout << "--- Move constructor with ref " << str2 << std::endl;
        HeapClass1 cls5 = HeapClass1((HeapClass1 &&) cls3);
    }
}
