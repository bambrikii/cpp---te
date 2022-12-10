#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Mean
{
private:
    long num;
    long sum;

public:
    Mean() : num(0), sum(0)
    {
    }
    void operator()(int val)
    {
        num++;
        sum += val;
    }

    double val()
    {
        return static_cast<double>(num) / static_cast<double>(sum);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec1 = {1, 2, 3, 4, 5};
    Mean mean = for_each(vec1.begin(), vec1.end(), Mean());
    cout << "mean = " << mean.val() << endl;

    return 0;
}
