#include <iostream>
#include <vector>

using namespace std;
#define DIV 1000 * 1000 * 100

int main(int argc, char const *argv[])
{
    vector<long long> vec1 = {};
    for (long long i = 0; i < (DIV * static_cast<long long>(1000)); i++)
    {
        if (i % DIV == 0)
        {
            cout << (i / DIV) << endl;
        }

        vec1.push_back(i);
    }

    return 0;
}