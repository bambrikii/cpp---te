#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void permutate1()
{
    cout << "permutations" << endl;
    string str = "abc";
    do
    {
        cout << " " << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

int main(int argc, char **argv)
{
    permutate1();

    return 0;
}