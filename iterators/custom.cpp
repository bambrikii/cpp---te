#include <array>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class MyIterator : public iterator<bidirectional_iterator_tag, int, ptrdiff_t, int, int &>
{
};

int main(int argc, char const *argv[])
{
    /* code */
    // TODO:
    return 0;
}
