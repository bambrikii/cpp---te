#include <vector>
#include <list>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
#include "create.hpp"


void inserter() {
    std::list<int> list1 = { 1, 2, 3 };
    std::list<int> list2;
    std::copy(list1.begin(), list1.end(), std::front_inserter(list2));
    print(list2);
}

void front_inserter() {
    std::list<int> list1 = { 1, 2, 3 };
    std::list<int> list2 = { 5 };
    std::copy(list1.begin(), list1.end(), std::front_inserter(list2));
    print(list2);
}

void back_inserter() {
    std::list<int> list1 = { 1, 2, 3 };
    std::list<int> list2 = { 5 };
    std::copy(list1.begin(), list1.end(), std::back_inserter(list2));
    print(list2);
}

int main(int argc, char const* argv[])
{
    // inserter iterator
    inserter();
    front_inserter();
    back_inserter();
    return 0;
}
