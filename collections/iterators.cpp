#include <list>
#include <forward_list>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <algorithm>

void iterate_list()
{
    std::cout << "list" << std::endl;
    std::list<int> list1 = {1, 2};
    auto i = list1.begin();
    std::cout << (i != list1.end()) << " " << *i << " " << &i << std::endl;
    std::cout << (++i != list1.end()) << " " << *i << " " << &i << std::endl;
    std::cout << (++i != list1.end()) << " " << *i << " " << &i << std::endl;
    std::cout << (++i != list1.end()) << " " << *i << " " << &i << std::endl;
    std::cout << (++i != list1.end()) << " " << *i << " " << &i << std::endl;
    std::cout << (++i != list1.end()) << " " << *i << " " << &i << std::endl;
}

void iterate_set()
{
    std::cout << "set" << std::endl;
    std::unordered_set<int> set1 = {1, 2};
    auto i = set1.begin();
    std::cout << (i++ != set1.end()) << std::endl;
    std::cout << (i++ != set1.end()) << std::endl;
    // std::cout << (i++ != set1.end()) << std::endl;
    for (auto i = set1.begin(); i != set1.end(); i++)
    {
        std::cout << (i != set1.end()) << " " << *i << " " << &i << std::endl;
    }
}

void find_before()
{
    std::forward_list<int> list = {1, 2, 3, 4, 5};
    auto posBefore = list.before_begin();
    for (; next(posBefore) != list.end(); ++posBefore)
    {
        if (*next(posBefore) % 3 == 0)
        {
            break;
        }
    }

    std::cout << "find_before: before_begin: " << *posBefore << std::endl;
}

int main(int argc, char const *argv[])
{

    iterate_list();
    iterate_set();
    find_before();

    return EXIT_SUCCESS;
}
