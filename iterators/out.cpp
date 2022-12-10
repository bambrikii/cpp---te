#include <array>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void out()
{
    cout << "output iterator" << endl;
    array<int, 3> arr = {1, 2, 3};
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        *i = *i + 3;
    }

    for (auto i = arr.cbegin(); i != arr.cend(); i++)
    {
        cout << " " << *i << endl;
    }

    cout << " value on pos 2: " << arr[2] << endl;
}

void move1()
{
    list<int> list = {1, 2, 3};
    cout << "advance" << endl;
    for (auto i = list.begin(); i != list.end(); advance(i, 1))
    {
        cout << " val = " << *i << ", next val = " << *next(i) << ", distance = " << distance(i, list.end()) << endl;
    }
}

int main(int argc, char const *argv[])
{
    out();
    move1();

    return 0;
}
