#include <iostream>
#include <regex>
#include <string>

using namespace std;

void match1(const string &str, const regex &re)
{
    smatch m;
    // bool found = regex_search(str, m, re);
    // if (found)
    auto pos = str.cbegin();
    auto end = str.cend();
    for (; regex_search(pos, end, m, re); pos = m.suffix().first)
    {
        cout << "details: " << m.str() << endl;
        cout << "  .prefix()    : " << m.prefix().str() << endl;
        cout << "  .postfix()   : " << m.suffix().str() << endl;
        for (int i = 0; i < m.size(); i++)
        {
            cout << " match         : " << m.str(i) << endl;
            cout << "  [" << i << "]          : "
                 << "" << i << "" << endl;
            cout << "  [" << i << "].str()    : " << m[i].str() << endl;
            cout << "  .position(" << i << ") : " << m.position(i) << endl;
            cout << endl;
        }

        cout << "matches:" << endl;
        for (auto pos = m.begin(); pos != m.end(); pos++)
        {
            cout << " " << pos->length() << " " << pos->str() << " " << pos->matched << "" << endl;
        }
    }
}

void print_matches(const smatch &m)
{
    cout << " match      : " << m.str() << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << "    match[" << i << "]: " << m.str(i) << endl;
    }
}

void match2(const string &str, const regex &re)
{
    cout << "all matches" << endl;
    auto pos = str.cbegin();
    auto end = str.cend();
    smatch m;
    for (; regex_search(pos, end, m, re); pos = m.suffix().first)
    {
        print_matches(m);
    }
}

void iter1(const string &str, const regex &re)
{
    cout << "iterator" << endl;
    sregex_iterator pos(str.begin(), str.end(), re);
    sregex_iterator end;
    for (; pos != end; pos++)
    {
        cout << " match: " << pos->str() << endl;
        for (auto i = pos->begin(); i != pos->end(); i++)
        {
            cout << "    match[" << *i << "]: " << pos->str() << endl;
        }
    }
}
void for_each1(const string &str, const regex &re)
{
    cout << "for_each" << endl;
    sregex_iterator beg(str.begin(), str.end(), re);
    sregex_iterator end;
    for_each(beg, end, [](const smatch &m)
             { print_matches(m); });
}

int main(int argc, char const *argv[])
{
    string str = "tag 1 <tag1>str1</tag1> tag 2 <tag2>str 2</tag2> tag 3 <tag3>str 3</tag3> end";
    auto re = regex("<([^>]+)>([^<]*)</(\\1)>");
    match1(str, re);
    match2(str, re);
    iter1(str, re);
    for_each1(str, re);

    return 0;
}
