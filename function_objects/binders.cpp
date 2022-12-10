#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void bind1()
{
    auto op1 = bind(multiplies<int>(), placeholders::_1, placeholders::_2);
    cout << "multiplies = " << op1(2, 3) << endl;

    cout << "tramsform" << endl;
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {2, 2, 2};
    auto transformed = transform(
        vec1.cbegin(), vec1.cend(),
        vec2.begin(), vec2.end(),
        bind(multiplies<int>(), placeholders::_1, placeholders::_2) //
    );
    for (auto i = vec2.begin(); i != vec2.end(); i++)
    {
        cout << " " << *i << " " << *transformed << endl;
    }
    for_each(transformed, transformed + vec2.size(), [](int elem)
             { cout << " result2 " << elem << endl; });
}

class Cls1
{
private:
    string prop1;
    string prop2;
    string prop3;

public:
    Cls1(string &&prop1, string &&prop2, string &&prop3) : prop1(move(prop1)), prop2(move(prop2)), prop3(move(prop3)){};
    string get_prop1()
    {
        return prop1;
    }
    void print()
    {
        cout << "   Cls1.print() = " << prop1 << " " << prop2 << " " << prop3 << " " << endl;
    }

    void print2(string &&val)
    {
        cout << "   Cls1.print2() = " << prop1 << " " << val << " " << &val << endl;
    }
};

void bind2()
{
    cout << "bind method" << endl;
    vector<Cls1> vec1 = {Cls1("str1", "1", "one"),
                         Cls1("str2", "2", "two"),
                         Cls1("str3", "3", "three")};
    for_each(vec1.begin(), vec1.end(), bind(&Cls1::print, placeholders::_1));
    for_each(vec1.begin(), vec1.end(), bind(&Cls1::print2, placeholders::_1, "some val"));
}

int main(int argc, char const *argv[])
{
    bind1();
    bind2();

    return 0;
}
