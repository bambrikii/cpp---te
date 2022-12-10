#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <ostream>
#include <sstream>

using namespace std;

class Cls1
{
private:
    string prop1;

public:
    Cls1(string &&prop1) : prop1(move(prop1))
    {
    }
    string get_prop1() const
    {
        return prop1;
    }
};

template <typename charT, typename traits>
basic_ostream<charT, traits> &
operator<<(basic_ostream<charT, traits> &strm, const Cls1 &cls1)
{
    basic_ostringstream<charT, traits> s;
    s.copyfmt(strm);
    s.width(0);
    s << "Cls1[prop1=" << cls1.get_prop1() << "]";
    strm << s.str();

    return strm;
}

void ostream1()
{
    cout << "ostream" << endl;

    ostringstream ostream;
    ostream << "123" << endl;

    cout << ostream.str() << endl;
}

void ostream_template1()
{
    cout << "ostream template" << endl;

    Cls1 cls1("prop1 value");
    cout << cls1 << ", " << Cls1("prop1 2 value") << endl;
}

int main(int argc, char const *argv[])
{

    ostream1();
    ostream_template1();

    return 0;
}
