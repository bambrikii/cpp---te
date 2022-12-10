#include <list>
#include <iostream>

using namespace std;

void iter() {
    list<char> coll;
    for (char c = 'a'; c <= 'z'; ++c) {
        coll.push_back(c);
    }

    // read-write iterator
    for (list<char>::iterator pos = coll.begin(); pos != coll.end(); ++pos) {
        *pos = *pos + 1;
        cout << *pos << " ";
        *pos = *pos - 1;
    }
    cout << endl;

    // read-only iterator
    for (list<char>::const_iterator pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    for (list<char>::const_iterator pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << &pos << " | " << pos._M_node->_M_prev << " - " << pos._M_node << " - " << pos._M_node->_M_next << " | " << endl;
    }
}

int main(int argc, char const* argv[])
{
    iter();
    return 0;
}
