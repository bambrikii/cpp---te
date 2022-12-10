#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "create.hpp"

void sort() {
    std::vector<int> vector = create_vector();
    std::sort(vector.begin(), vector.end());
    print(vector);
}

void reverse() {
    std::vector<int> vector = create_vector();
    std::reverse(vector.begin(), vector.end());
    print(vector);
}

void find() {
    std::vector<int> vector = create_vector();
    std::vector<int>::const_iterator found = std::find(vector.cbegin(), vector.cend(), 2);
    std::cout << "found " << *found << ", " << &found << " " << &vector << std::endl;
}

void find_if() {
    std::vector<int> vector = create_vector();
    std::vector<int>::const_iterator found = std::find_if(vector.cbegin(), vector.cend(), [](int i) { return i == 2; });
    std::cout << "found if " << *found << ", " << &found << " " << &vector << std::endl;
}

void min() {
    std::vector<int> vector = create_vector();
    std::vector<int>::const_iterator min = std::min_element(vector.cbegin(), vector.cend());
    std::cout << "min " << *min << ", " << &min << " " << &vector << std::endl;
}

void max() {
    std::vector<int> vector = create_vector();
    std::vector<int>::const_iterator max = std::max_element(vector.cbegin(), vector.cend());
    std::cout << "max " << *max << ", " << &max << " " << &vector << std::endl;
}

void copy() {
    std::vector<int> vector1 = create_vector();
    std::vector<int> vector2 = { 1, 1, 1, 1, 1 };
    std::copy(vector1.begin(), vector1.end(), vector2.begin());
    print(vector2);
    vector2.resize(vector1.size());
    print(vector2);
}

int main(int argc, char const* argv[])
{
    sort();
    reverse();
    find();
    find_if();
    min();
    max();
    copy();

    return 0;
}
