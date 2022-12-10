#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Cls1
{
private:
    string prop1;
    string prop2;

public:
    Cls1(string &&prop1, string &&prop2) : prop1(move(prop1)), prop2(move(prop2))
    {
    }

    string get_prop1()
    {
        return prop1;
    }
    string get_prop2()
    {
        return prop2;
    }

    string to_string()
    {
        return prop1 + " " + prop2;
    }
};

bool cls1Less(Cls1 &left, Cls1 &right)
{
    if (left.get_prop1() < right.get_prop1())
    {
        return true;
    }
    if (left.get_prop2() < right.get_prop2())
    {
        return true;
    }
    return false;
};

void sort_objects()
{
    cout << "sort objects" << endl;
    vector<Cls1> vec1 = {
        Cls1("str1", "a"),
        Cls1("str5", "d"),
        Cls1("str4", "e"),
        Cls1("str2", "c"),
        Cls1("str2", "b")};
    sort(vec1.begin(), vec1.end(), cls1Less);
    for (auto i = vec1.begin(); i != vec1.end(); i++)
    {
        cout << " " << i->to_string() << endl;
    }
};

void print(vector<int> vec1, string &&message)
{
    cout << message << endl;
    cout << "  ";
    for (auto i = vec1.begin(); i != vec1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void union1()
{
    vector<int> vec1 = {1, 2, 3, 6, 7};
    vector<int> vec2 = {3, 4, 5};
    vector<int> vec3 = {};
    set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec3));
    print(vec3, "set_union - inserts in a sorted way");
}

void intersection1()
{
    vector<int> vec1 = {1, 2, 3, 6, 7};
    vector<int> vec2 = {
        3, 4, 5,
        1 // ignored!???
    };
    vector<int> vec3 = {};
    set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec3));
    print(vec3, "intersection of sorted vectors");
}

void difference1()
{
    vector<int> vec1 = {1, 2, 3, 6, 7};
    vector<int> vec2 = {
        3, 4, 5,
        8 // ignored!???
    };
    vector<int> vec3 = {};
    set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec3));
    print(vec3, "difference");
}

int main(int argc, char const *argv[])
{
    sort_objects();
    union1();
    intersection1();
    difference1();

    return 0;
}
