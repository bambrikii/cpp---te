#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "VectorEg.hpp"

struct VectorElem
{
    int prop1;

    VectorElem(int prop1) : prop1(prop1)
    {
        std::cout << "Constructor of VectorElem(" << prop1 << ")" << std::endl;
    }

    VectorElem(const VectorElem &elem) : prop1(elem.prop1)
    {
        std::cout << "Copy of VectorElem(" << prop1 << ")" << std::endl;
    }

    std::ostream &operator<<(std::ostream &os)
    {
        return os << "VectorElem(" << prop1 << ")";
    }
    std::string to_string()
    {
        std::string prop1str = std::to_string(prop1);
        return "VectorElem(" + prop1str + ")";
    }
};

VectorEg::VectorEg()
{
    std::cout << "Vector" << std::endl;
}

void VectorEg::add()
{
    std::vector<int> v1 = {1, 2, 3};
    v1.reserve(1);
    v1.push_back(4);
    v1.push_back(5);
    v1.emplace_back(6);

    for (int i : v1)
    {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

template <typename T>
void print(std::vector<T> *v1)
{
    for (T &i : *v1)
    {
        std::cout << " Print of " << i.to_string() << std::endl;
    }
    std::cout << std::endl;
}

void VectorEg::add2()
{
    std::vector<VectorElem> v1;
    v1.reserve(5);
    v1.push_back(VectorElem(1));
    v1.emplace_back(2);
    v1.emplace_back(3);
    v1.emplace_back(4);
    v1.emplace_back(5);

    print(&v1);
}
