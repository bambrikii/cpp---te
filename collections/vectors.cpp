#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(std::vector<int> v1) {
    for (auto i = v1.begin(); i != v1.end(); i++) { std::cout << *i << ","; }
    std::cout << std::endl;
}

int main(int argc, char const* argv[])
{
    std::vector<int> v1 = { 0, 1, 2 };
    std::vector<int> v2 = { 3, 4, 5 };
    v1.insert(v1.begin() + 1, v2.begin(), v2.end());
    print(v1);

    v1.push_back(6);
    print(v1);

    v1.resize(3);
    print(v1);

    v1.erase(v1.begin() + 1);
    print(v1);
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    v1.shrink_to_fit();
    print(v1);
    std::cout << v1.size() << " " << v1.capacity() << std::endl;

    std::cout << *v1.emplace(v1.begin() + 1, 7) << std::endl;
    print(v1);

    std::cout << *std::find(v1.begin(), v1.end(), 7) << std::endl;

    v1.resize(10);
    print(v1);
    v1.resize(3);
    v1.shrink_to_fit();

    std::cout << v1[0] << " " << v1[1] << " " << v1[9] << " " << v1[10] << ", size = " << v1.size() << ", data = " << v1.data()[0] << std::endl;

    std::copy(
        v1.cbegin(), v1.cend(),
        std::ostream_iterator<int>(std::cout, " ")
    );


    return 0;
}
