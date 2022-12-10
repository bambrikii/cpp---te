#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "string as container" << endl;
    string &&str1 = "abcdef";
    for (auto i = str1.begin(); i != str1.end(); i++)
    {
        cout << " " << *i << " " << &i << endl;
    }
    return 0;
}
