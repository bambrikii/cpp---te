#include <iostream>

#include <list>
#include <forward_list>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

#include <set>
#include <unordered_set>

#include <map>
#include <unordered_map>

#include <algorithm>

#define ARRAY_SIZE1 3
void array() {
    std::cout << "array" << std::endl;
    std::array<int, ARRAY_SIZE1> arr1 = { 1, 2, 3 };
    std::cout << "  iterator loop" << std::endl;
    for (auto& i : arr1)
    {
        std::cout << i << std::endl;
    }
    std::cout << "  explicit iterator loop" << std::endl;
    for (std::array<int, ARRAY_SIZE1>::iterator i = arr1.begin(); i != arr1.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "  for loop" << std::endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << std::endl;
    }
}

void list() {
    std::cout << "list" << std::endl;
    std::list<int> list1 = { 4, 5, 6 };
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++) {
        std::cout << *i << std::endl;
    }

}

void forward_list() {
    std::cout << "forward_list" << std::endl;
    std::forward_list<int> list1 = { 4, 5, 6 };
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    for (std::forward_list<int>::iterator i = list1.begin(); i != list1.end(); i++) {
        std::cout << *i << std::endl;
    }

}

void vector() {
    std::cout << "vector" << std::endl;
    std::vector<int> v1 = std::vector<int>();
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
}

void dequeue() {
    std::cout << "dequeue" << std::endl;
    std::deque<int> v1 = std::deque<int>();
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
}

void queue() {
    std::cout << "queue" << std::endl;
    std::queue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    while (!queue1.empty()) {
        std::cout << queue1.front() << " - " << queue1.back() << std::endl;
        queue1.pop();
    }
}

void priority_queue() {
    std::cout << "priority_queue" << std::endl;
    std::priority_queue<int, std::vector<int>, std::less<int>> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    while (!queue1.empty()) {
        std::cout << queue1.top() << std::endl;
        queue1.pop();
    }
}

void stack() {
    std::cout << "stack" << std::endl;
    std::stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    while (!stack1.empty()) {
        std::cout << stack1.top() << std::endl;
        stack1.pop();
    }
}

void set() {
    std::cout << "set" << std::endl;
    std::set<int> set1 = { 1, 2, 3 };
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);
    for (std::set<int>::iterator i = set1.begin(); i != set1.end(); i++) {
        std::cout << *i << std::endl;
    }
}

void unordered_multiset() {
    std::cout << "unordered_multiset" << std::endl;
    std::unordered_multiset<int> set1 = { 1, 1,  2, 3 };
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);
    for (std::unordered_multiset<int>::iterator i = set1.begin(); i != set1.end(); i++) {
        std::cout << *i << std::endl;
    }
}

void map() {
    std::cout << "map" << std::endl;
    std::map<int, int> map1 = {
        { 1, 1 },
        { 2, 2 },
        { 3, 3 }
    };
    map1[1] = 10;
    map1[4] = 40;
    map1[5] = 50;
    std::for_each(map1.begin(), map1.end(), [](std::pair<int, int> i) {
        std::cout << i.first << " - " << i.second << std::endl;
        });
}

void multimap() {
    std::cout << "multimap" << std::endl;
    std::multimap<int, int> map1 = {
        { 1, 1 },
        { 1, 2 },
        { 2, 2 },
        { 3, 3 }
    };
    map1.emplace(1, 10);
    map1.emplace(4, 40);
    map1.emplace(5, 50);
    std::for_each(map1.begin(), map1.end(), [](std::pair<int, int> i) {
        std::cout << i.first << " - " << i.second << std::endl;
        });
}

void unordered_map() {
    std::cout << "unordered_map" << std::endl;
    std::unordered_map<int, int> map1 = {
        { 1, 1 },
        { 2, 2 },
        { 3, 3 }
    };
    map1[1] = 10;
    map1[4] = 40;
    map1[5] = 50;
    std::for_each(map1.begin(), map1.end(), [](std::pair<int, int> i) {
        std::cout << i.first << " - " << i.second << std::endl;
        });
}

int main(int argc, char** argv) {

    // array based
    array(); // fixed size array
    vector(); // array
    dequeue();

    // node based
    list(); // linked list
    forward_list(); // singly linked list
    set(); // sorted tree
    map(); // sorted tree
    multimap(); // tree with duplicates allowed

    queue();
    priority_queue();
    stack();


    // hash based
    unordered_multiset(); // hash set
    unordered_map(); // hash table

    return 0;
}
