#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    stringstream ss;
    ss << "012345678901234567890123456789012345" << endl;

    string str2;
    ss >> str2;

    cout << "read string = " << str2 << ", length = " << str2.length() << ", capacity = " << str2.capacity() << endl;

    return 0;
}
