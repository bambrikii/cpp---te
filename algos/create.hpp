#include <string>
#include <vector>
#include <list>
#include <set>
#include <iostream>

std::vector<int> create_vector() {
    std::vector<int> vector;
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(1);
    return vector;
}

void print(std::vector<int>& vector) {
    for (std::vector<int>::iterator iter = vector.begin(); iter != vector.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void print(std::list<int>& list) {
    for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void print(std::set<int>& set) {
    for (std::set<int>::iterator iter = set.begin(); iter != set.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void print(std::list<std::string>& list) {
    for (std::list<std::string>::iterator iter = list.begin(); iter != list.end(); iter++) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}
