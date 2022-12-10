#include <array>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void each()
{
    cout << "for_each" << endl;
    list<int> list = {1, 2, 3};
    cout << " write" << endl;
    for_each(list.begin(), list.end(), [](int &elem)
             { 
                cout << "  " << elem;
                elem = elem + 3;
                cout << " -> " << elem << endl; });

    cout << " read" << endl;
    for_each(list.begin(), list.end(), [](int &elem)
             { cout << "  " << elem << endl; });
}

void each_const()
{
    cout << "for_each const" << endl;
    list<int> list = {1, 2, 3};
    for_each(list.cbegin(), list.cend(), [](const int &elem)
             { cout << "  " << elem << endl; });
}

void back_inserter1()
{
    cout << "back_inserter" << endl;
    list<int> list = {1, 2, 3};
    front_inserter(list) = 0;
    back_inserter(list) = 4;
    for_each(list.cbegin(), list.cend(), [](const int &elem)
             { cout << "  " << elem << endl; });
}

void copy1()
{
    cout << "copy" << endl;
    list<int> list1 = {1, 2, 3};
    list<int> list2 = {0, 0, 0, 0};
    copy(list1.begin(), list1.end(), inserter(list2, list2.begin()));
    copy(list1.begin(), list1.end(), back_inserter(list2));

    for_each(list2.cbegin(), list2.cend(), [](const int &elem)
             { cout << "  " << elem << endl; });
}

void ostream1()
{
    cout << "ostream" << endl;
    list<int> list1 = {1, 2, 3};
    copy(list1.begin(), list1.end(), ostream_iterator<int>(cout, " < "));
}

void move1()
{
    cout << "move" << endl;
    list<int> list1 = {1, 2, 3};
    for_each(list1.cbegin(), list1.cend(), [](const int &elem)
             { cout << "  " << elem << " " << &elem << endl; });

    list<int> list2(make_move_iterator(list1.begin()), make_move_iterator(list1.end()));

    cout << " source" << endl;
    for_each(list1.cbegin(), list1.cend(), [](const int &elem)
             { cout << "  " << elem << " " << &elem << endl; });

    cout << " target" << endl;
    for_each(list2.cbegin(), list2.cend(), [](const int &elem)
             { cout << "  " << elem << " " << &elem << endl; });
}

int main(int argc, char const *argv[])
{
    each();
    each_const();
    back_inserter1();
    copy1();
    ostream1();
    move1();

    return 0;
}
