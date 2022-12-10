#include <list>
#include <iostream>

void print(const std::list<int> &l1, const std::string &&comment)
{
    std::cout << " " << comment << ": ";
    for (auto i = l1.begin(); i != l1.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::list<int> l1 = {1, 2, 3};
    std::list<int> l2 = {4, 5};
    print(l1, "l1");
    print(l2, "l2");

    std::cout << "splice l2 into l1" << std::endl;
    l1.splice(l1.begin(), l2);

    print(l1, "l1");
    print(l2, "l2");

    std::cout << "push back 2 and 3 into l2" << std::endl;
    l2.push_back(2);
    l2.push_back(3);
    print(l2, "l2");

    std::cout << "sort l1" << std::endl;
    l1.sort([](int left, int right)
            { return left < right; });
    print(l1, "l1");

    std::cout << "merge l2 into l1" << std::endl;
    l1.merge(l2);
    print(l1, "l1");
    print(l2, "l2");

    std::cout << "remove 3 from l1" << std::endl;
    l1.remove(3);
    print(l1, "l1");

    std::cout << "remove if i < 3 from l1" << std::endl;
    l1.remove_if([](int val)
                 { return val < 3; });
    print(l1, "l1");

    std::cout << "erase all except last in l1" << std::endl;
    l1.erase(l1.begin(), --l1.end());
    print(l1, "l1");

    return 0;
}
