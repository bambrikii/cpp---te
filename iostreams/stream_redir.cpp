#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

using namespace std;

void file1()
{
    cout << "file1" << endl;

    fstream file("stream_redir-1.txt", ios::in | ios::out | ios::trunc);
    file.write("line1", 5);
    file.flush();
    file.close();
}

void os1()
{
    cout << "os1" << endl;

    ofstream os1("stream_redir-2.txt", ios::in | ios::out | ios::trunc);
    istream in(os1.rdbuf());
    os1.write("line1", 5);
    os1.flush();
    os1.close();
}

void buf1()
{
    cout << "buf1" << endl;

    filebuf buf;
    ostream os1(&buf);
    istream is1(&buf);

    buf.open("stream_redir_buf1.txt", ios::in | ios::out | ios::trunc);
    os1 << "line1" << endl;

    string str2;
    is1.seekg(0);
    is1 >> str2;
    cout << str2 << endl;

    buf.close();
}

void iter1()
{
    cout << "ostreambuf_iterator" << endl;
    string str1 = "line1";
    ostreambuf_iterator iter1(cout);
    copy(str1.begin(), str1.end(), iter1);
    cout << endl;
}

template <typename charT, typename traits = std::char_traits<charT>>
class custom_outbuffer : public basic_streambuf<charT, traits>
{
protected:
    virtual typename traits::int_type overflow(typename traits::int_type c)
    {
        if (!traits::eq_int_type(c, traits::eof()))
        {
            c = toupper(c);
            if (putchar(c) == EOF)
            {
                return traits::eof();
            }
        }
        return traits::not_eof(c);
    }
};

void custom_out1()
{
    cout << "custom outbuffer" << endl;

    custom_outbuffer<char> buf;
    ostream os1(&buf);
    istream is(&buf);

    os1 << "line1" << endl;

    is.seekg(0);
    string str;
    is >> str;
    cout << str << endl;
}

int main(int argc, char const *argv[])
{
    file1();
    os1();
    buf1();
    iter1();
    custom_out1();

    return 0;
}
