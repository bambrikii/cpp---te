#include <iostream>
#include <set>
#include <map>
#include "print_coll.hpp"
#include <algorithm>
#include <string>

using namespace std;

class Cls1
{
private:
    int int1;
    string str1;

    bool less(const Cls1 &rhs) const
    {
        if (int1 < rhs.int1)
        {
            return true;
        }
        if (str1 < rhs.str1)
        {
            return true;
        }
        return false;
    }

public:
    Cls1(const int &&int1, const string &&str1) : int1(move(int1)), str1(move(str1)) {}

    bool operator<(const Cls1 &rhs) const
    {
        return less(rhs);
    }

    bool operator>(const Cls1 &rhs) const
    {
        return !less(rhs);
    }

    string to_string()
    {
        return "" + std::to_string(int1) + " - " + str1;
    }
};

void print(set<Cls1> &set1)
{
    for (set<Cls1>::iterator i = set1.begin(); i != set1.end(); i++)
    {
        Cls1 i2 = *i;
        cout << "   " << i2.to_string() << endl;
    }
}
void print(set<Cls1, greater<Cls1>> &set1)
{
    for (set<Cls1>::iterator i = set1.begin(); i != set1.end(); i++)
    {
        Cls1 i2 = *i;
        cout << "   " << i2.to_string() << endl;
    }
}

void print(multiset<Cls1> &set1)
{
    for (set<Cls1>::iterator i = set1.begin(); i != set1.end(); i++)
    {
        Cls1 i2 = *i;
        cout << "   " << i2.to_string() << endl;
    }
}

void set2_custom_class()
{
    cout << "set2 custom class" << endl;
    set<Cls1> set2 = {};
    Cls1 cls1 = {1, "str1"};
    set2.insert(cls1);
    set2.insert(cls1); // won't be added? or replaced
    set2.insert(Cls1(2, "str2"));
    set2.insert({3, "str3"});

    print(set2);
}

void multiset1()
{
    cout << "multiset1" << endl;
    multiset<Cls1> set1 = {
        {1, "str1"},
        {1, "str1"}, // will be added
        {2, "str2"},
        {3, "str3"}};

    print(set1);
}

void set1()
{
    set<float> set1 = {1, 1, 2, 3};
    set1.insert(4);

    print<float>("set1", set1);
    rprint<float>("set1", set1);

    cout << " count: " << set1.count(1) << endl;
    cout << " find(2): " << *set1.find(2) << endl;
    cout << " find(-1): " << *set1.find(-1) << endl;

    cout << " lower_bound(-1): " << *set1.lower_bound(-1) << endl;
    cout << " lower_bound(0): " << *set1.lower_bound(0) << endl;

    cout << " lower_bound(1): " << *set1.lower_bound(1) << endl;
    cout << " upper_bound(1): " << *set1.upper_bound(1) << endl;

    cout << " lower_bound(2): " << *set1.lower_bound(2) << endl;
    cout << " upper_bound(2): " << *set1.upper_bound(2) << endl;

    cout << " lower_bound(4): " << *set1.lower_bound(4) << endl;
    cout << " lower_bound(9): " << *set1.lower_bound(9) << endl;

    auto eq1 = set1.equal_range(1);
    cout << " equal_range(1): " << *eq1.first << " " << *eq1.second << endl;
};

void set3_sorted()
{
    cout << "sorted set greater" << endl;
    set<Cls1, less<Cls1>> set1 = {
        {1, "str1"},
        {2, "str2"},
        {3, "str3"},
    };
    print(set1);

    cout << "sorted set less" << endl;
    set<Cls1, greater<Cls1>> set2 = {
        {1, "str1"},
        {2, "str2"},
        {3, "str3"},
    };
    print(set2);
}

void sorted_map()
{
    cout << "sorted map greater" << endl;
    std::map<float, std::string, std::greater<float>> map;
    map[1] = "11";
    map[1] = "12";
    map[2] = "22";
    map[3] = "33";
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first << " - " << i->second << endl;
    }

    cout << " found 1: " << map.find(1)->second << endl;
}

void sorted_multimap1()
{
    cout << "multimap greater" << endl;
    std::multimap<float, std::string, std::greater<float>> map;
    map.insert(map.begin(), pair<float, string>(1, "11"));
    map.insert(map.begin(), {1, "12"}); // will overwrite previous value
    map.insert(map.begin(), {2, "22"});
    map.insert(map.begin(), {3, "33"});
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first << " - " << i->second << endl;
    }

    cout << " found 1: " << map.find(1)->second << endl;
}

int main(int argc, char const *argv[])
{
    // node based containers
    set1();
    set2_custom_class();
    multiset1();
    set3_sorted();

    sorted_map();
    sorted_multimap1();

    return 0;
}
