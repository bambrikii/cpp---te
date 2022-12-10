#include <iostream>
#include <string>

// #pragma once

#ifndef CONSTRUCTORS_HPP
#define CONSTRUCTORS_HPP 1

class HeapClass1
{
private:
    std::string name;

public:
    HeapClass1(std::string *name);
    HeapClass1(HeapClass1 &other);
    HeapClass1(HeapClass1 &&other);
    void print();
    ~HeapClass1();
};

void constructorsMain();
#endif
