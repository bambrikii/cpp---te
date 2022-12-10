#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

#include "create.hpp"

void remove() {
    std::vector<int> vector = create_vector();
    std::vector<int>::iterator end = std::remove(vector.begin(), vector.end(), 2);
    print(vector);
    std::cout << *end << std::endl;

    vector.erase(end, vector.end());
    print(vector);
}

void erase() {
    std::set<int> set = { 1, 2, 3, 4, 5 };
    set.erase(3);

    print(set);
}

int main(int argc, char const* argv[])
{
    remove();
    erase();

    return EXIT_SUCCESS;
}
