#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "bitset" << endl;
    bitset<8> bs("01010000");
    bs.flip(0);
    cout << " count = " << bs.count() << endl;
    for (auto i = 0; i < bs.size(); i++)
    {
        cout << " " << bs[i];
    }
    cout << endl;
    return 0;
}
