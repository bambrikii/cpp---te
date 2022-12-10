#include <list>
#include <algorithm>
#include <iostream>

int main(int argc, char const* argv[])
{
    std::list<int> list1({ 1, 2, 3 });
    std::cout << "list1: " << &list1 << std::endl;

    //
    std::initializer_list<int>&& arr2 = { 1, 2, 3 };
    std::list<int> list2(std::move(arr2));
    std::cout << "arr2: " << &arr2 << std::endl;
    std::cout << "list2: " << &list2 << std::endl;
    for (auto i = arr2.begin(); i != arr2.end(); i++) {
        std::cout << *i << " ";
    };
    std::cout << std::endl;

    //
    std::list<int> list3(list1);
    for (std::list<int>::iterator i = list1.begin(); i != list1.end(); i++) {
        std::cout << *i << " ";
    };
    std::cout << std::endl;

    std::cout << "list3: " << &list3 << std::endl;

    //
    int arr4[] = { 1, 2, 3 };
    std::list<int> list4(
        std::make_move_iterator(std::begin(arr4)),
        std::make_move_iterator(std::end(arr4))
    );
    std::cout << "arr4: " << &arr4 << std::endl;
    std::cout << "list4: " << &list4 << std::endl;
    for (int i = 0; i < 3; i++) { std::cout << arr4[i] << " "; }
    std::cout << std::endl;
    for (auto i = list4.cbegin(); i != list4.cend(); i++) { std::cout << *i << " "; }
    std::cout << std::endl;

    std::list<int> list5 = { 1, 2, 3 };
    std::list<int> list6 = std::move(list5);
    std::cout << "list5: " << &list5 << " " << list5.size() << std::endl;
    for (auto i = list5.cbegin(); i != list5.cend(); i++) { std::cout << *i << " "; }
    std::cout << "list6: " << &list6 << std::endl;
    for (auto i = list6.cbegin(); i != list6.cend(); i++) { std::cout << *i << " "; }



    return EXIT_SUCCESS;
}
