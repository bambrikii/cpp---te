#include <iostream>
#include <set>

using namespace std;

#ifndef PRINT_COLL
#define PRINT_COLL 1

template <typename T>
void print(const string &comment, const set<T> &coll)
{
    cout << " - " << comment << " - " << endl;
    for (auto i = coll.cbegin(); i != coll.cend(); i++)
    {
        cout << "   " << *i << " (" << &i << ")" << endl;
    }
}

template <typename T>
void rprint(const string &comment, const set<T> &coll)
{
    cout << " - " << comment << " - " << endl;
    for (auto i = coll.crbegin(); i != coll.crend(); i++)
    {
        cout << "   " << *i << " (" << &i << ")" << endl;
    }
}
#endif