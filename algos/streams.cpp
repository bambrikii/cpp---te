#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <streambuf>
#include <fstream>

#include "create.hpp"


void istream_iterator() {
    std::cout << "istream_iterator" << std::endl;
    std::list<std::string> list = { };

    std::ifstream in("streams.cpp");
    std::copy(
        std::istream_iterator<std::string>(in),
        std::istream_iterator<std::string>(),
        std::front_inserter(list)
    );
    print(list);
}

void revers_iterator() {
    std::cout << "revers_iterator" << std::endl;
    std::list<int> list = { 1, 2, 3 };
    for (std::list<int>::reverse_iterator i = list.rbegin(); i != list.rend(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    copy(list.crbegin(), list.crend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void for_each() {
    std::cout << "for_each" << std::endl;
    std::list<int> list = { 1, 2, 3 };
    for_each(
        list.begin(),
        list.end(),
        [](int elem) {
            std::cout << elem << " " << std::endl;
        }
    );
}

class ForEachObj {
public:
    void operator () (int elem) {
        std::cout << elem << " " << std::endl;
    }
};

void for_each_obj() {
    std::cout << "for_each_obj" << std::endl;
    std::list<int> list = { 1, 2, 3 };
    for_each(
        list.begin(),
        list.end(),
        ForEachObj()
    );
}

void transform() {
    std::cout << "transform" << std::endl;
    std::list<int> list = { 1, 2, 3 };
    std::list<int> list2 = { };
    std::transform(
        list.begin(),
        list.end(),
        std::back_inserter(list2),
        [](int elem) {
            return elem << 1;
        }
    );
    print(list2);
}

int main(int argc, char const* argv[])
{
    istream_iterator();
    revers_iterator();
    for_each();
    for_each_obj();
    transform();

    return 0;
}
