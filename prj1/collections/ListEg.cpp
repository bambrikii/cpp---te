#include <algorithm>
#include <iostream>
#include <list>

#include "ListEg.hpp"

ListEg::ListEg()
{
    std::cout << "List" << std::endl;
}

void ListEg::add()
{
    std::list<int> l = {1, 2, 3};

    l.push_back(4);
    l.push_front(-1);
    l.remove(2);

    for (int n : l)
    {
        std::cout << " " << n;
    }
    std::cout << std::endl;
}

void printFound(std::list<int>::iterator *l2, std::list<int> *l)
{
    if ((*l2) != (*l).end())
    {
        std ::cout << "Element is present. " << std ::endl;
    }
    else
    {
        std ::cout << "Element is not present. " << std ::endl;
    }
}

void ListEg::find()
{
    std::list<int> l = {1, 5, 10};

    std::list<int>::iterator l2 = std::find(l.begin(), l.end(), 5);
    printFound(&l2, &l);

    std::list<int>::iterator l3 = std::find(l.begin(), l.end(), 6);
    printFound(&l3, &l);

    std::cout << " " << std::endl;
}