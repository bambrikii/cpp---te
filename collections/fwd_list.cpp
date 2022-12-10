#include <iostream>
#include <list>
#include <forward_list>
#include <string>
#include <sstream>

void print(const std::forward_list<int> &fwd1, const std::string &&comment)
{
    std::cout << comment << std::endl;
    for (std::forward_list<int>::const_iterator i = fwd1.cbegin(); i != fwd1.cend(); i++)
    {
        std::cout << " " << *i;
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::forward_list<int> fwd1 = {1, 2, 3};
    print(fwd1, "fwd1");
    fwd1.clear();
    fwd1.push_front(1);
    fwd1.push_front(2);
    fwd1.pop_front();
    std::cout << "pop_front: " << fwd1.front() << std::endl;

    std::forward_list<int> fwd2({1, 2, 3});
    print(fwd2, "fwd2");

    std::forward_list<int> fwd3 = fwd1;
    std::string str3 = "";
    const void *s3 = (static_cast<const void *>(&fwd3));
    std::ostringstream strm3;
    strm3 << s3;
    print(fwd3, "fwd3 " + strm3.str());

    fwd3.assign(3, 5);
    print(fwd3, "assign fwd3 ");

    std::forward_list<int> fwd4 = {1, 2, 3};
    std::forward_list<int> fwd5 = {4, 5};
    fwd4.insert_after(fwd4.begin()++, fwd5.begin(), fwd5.end());
    print(fwd4, "fwd4 insert_after");

    std::forward_list<int> fwd6 = {1, 2, 3};
    fwd6.emplace_after(fwd6.begin()++, 6);
    print(fwd6, "fwd6 emplace_after");

    std::forward_list<int> fwd7 = {1, 2, 3};
    std::cout << " before_begin: " << *++fwd7.begin() << " " << *++fwd7.before_begin() << " " << std::endl;

    return 0;
}
