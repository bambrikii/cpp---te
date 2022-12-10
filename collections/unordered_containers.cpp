#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void set1()
{
    cout << "unordered set" << endl;
    unordered_set<int> set = {2, 1, 3};
    for (auto i = set.begin(); i != set.end(); i++)
    {
        cout << " " << *i << endl;
    }
}

void map1()
{
    cout << "unordered map" << endl;
    unordered_map<int, string> set = {
        pair<int, string>(2, "22"),
        pair<int, string>(1, "11"),
        pair<int, string>(3, "33"),
    };
    for (auto i = set.begin(); i != set.end(); i++)
    {
        cout << " " << i->first << " - " << i->second << endl;
    }
}

void multimap1()
{
    cout << "unordered map" << endl;
    unordered_multimap<int, string> set = {
        pair<int, string>(2, "22"),
        pair<int, string>(1, "11"),
        pair<int, string>(1, "12"),
        pair<int, string>(3, "33"),
    };
    for (auto i = set.begin(); i != set.end(); i++)
    {
        cout << " " << i->first << " - " << i->second << endl;
    }
    auto pos = set.find(1);
    cout << "   found " << pos->first << " - " << pos->second << endl;

    auto range = set.equal_range(1);
    for (auto i = range.first; i != range.second; i++)
    {
        cout << "   equal range " << i->first << " - " << i->second << endl;
    }
}

class Cls1
{
private:
    int prop1;
    string prop2;
    string prop3;

public:
    Cls1(const int &prop1, const string &prop2) : prop1(move(prop1)), prop2(move(prop2))
    {
    }
    int get_prop1() const
    {
        return prop1;
    }
    string get_prop2() const
    {
        return prop2;
    }

    string get_prop3() const
    {
        return prop3;
    }

    void set_prop3(const string &prop3)
    {
        this->prop3 = move(prop3);
    }

    string to_string()
    {
        return prop1 + "-" + prop2;
    }
};

class Cls1Hash
{
public:
    bool operator()(const Cls1 &obj) const
    {
        return hash<int>()(obj.get_prop1()) + hash<string>()(obj.get_prop2());
    }
};
class Cls1Equals
{
public:
    bool operator()(const Cls1 &left, const Cls1 &right) const
    {
        return left.get_prop1() == right.get_prop1() && left.get_prop2() == right.get_prop2();
    }
};

void map_with_hash()
{
    cout << "unordered map:" << endl;
    unordered_map<Cls1, string, Cls1Hash, Cls1Equals> map;
    map.insert(make_pair<Cls1, string>({2, "2"}, "12"));
    map.insert(make_pair<Cls1, string>({1, "1"}, "11"));
    map.insert(make_pair<Cls1, string>({3, "3"}, "13"));
    map.insert(make_pair<Cls1, string>({4, "4"}, "13"));

    cout << " insert duplicates:" << endl;
    map.insert(make_pair<Cls1, string>({1, "1"}, "111")); // will not replace value "111"
    map.insert(make_pair<Cls1, string>({1, "3"}, "113")); // will add another pair
    auto found = map.find({4, "4"});
    if (found != map.end())
    {
        map.erase(found);
    }

    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first.get_prop1() << " - " << i->second << endl;
    }

    string byPos = map.at({1, "1"});
    cout << " found " << byPos << endl;
}

void multimap_with_hash()
{
    cout << "unordered multimap:" << endl;
    unordered_multimap<Cls1, string, Cls1Hash, Cls1Equals> map;
    map.insert(make_pair<Cls1, string>({2, "12"}, "12"));
    map.insert(make_pair<Cls1, string>({1, "11"}, "11"));
    map.insert(make_pair<Cls1, string>({3, "13"}, "13"));

    cout << " insert duplicates:" << endl;
    map.insert(make_pair<Cls1, string>({1, "11"}, "11"));
    map.insert(make_pair<Cls1, string>({1, "11"}, "111"));
    map.insert(make_pair<Cls1, string>({1, "13"}, "113"));

    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first.get_prop1() //
             << " " << i->first.get_prop2()   //
             << " " << i->first.get_prop3()   //
             << " - " << i->second << endl;
    }

    cout << " update value:" << endl;
    for_each(map.begin(), map.end(), [](pair<const Cls1, string> &pair)
             { 
                // pair.first.set_prop3(pair.first.get_prop2() + "-");
                pair.second = pair.first.get_prop2() + "a"; });
    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first.get_prop1() //
             << " " << i->first.get_prop2()   //
             << " " << i->first.get_prop3()   //
             << " - " << i->second << endl;
    }
}

/**
 * https://ianyepan.github.io/posts/cpp-custom-hash/
 **/
void lambda_hash()
{
    cout << "lambda hash:" << endl;
    auto hash1 = [](const Cls1 &obj)
    {
        return hash<int>()(obj.get_prop1()) + hash<string>()(obj.get_prop2());
    };
    auto eq1 = [](const Cls1 &left, const Cls1 &right)
    {
        return left.get_prop1() == right.get_prop1() && left.get_prop2() == right.get_prop2();
    };
    unordered_map<Cls1, string, decltype(hash1), decltype(eq1)> map(1, hash1, eq1);
    map.insert(make_pair<Cls1, string>({2, "12"}, "12"));
    map.insert(make_pair<Cls1, string>({1, "11"}, "11"));
    map.insert(make_pair<Cls1, string>({3, "13"}, "13"));
    map.insert(make_pair<Cls1, string>({1, "11"}, "12")); // will not overwrite

    for (auto i = map.begin(); i != map.end(); i++)
    {
        cout << "   " << i->first.get_prop1() //
             << " " << i->first.get_prop2()   //
             << " " << i->first.get_prop3()   //
             << " - " << i->second << endl;
    }
}

int main(int argc, char const *argv[])
{
    set1();
    map1();
    multimap1();

    map_with_hash();
    multimap_with_hash();

    lambda_hash();

    return 0;
}
