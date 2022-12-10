#include <iostream>
#include <fstream>
#include <fstream>

using namespace std;

void write_1()
{
    cout << "write" << endl;
    ofstream f1("file1-2.txt", ios::ate);
    f1 << "line1" << endl;
    f1 << "line2" << endl;
    // f1.seekp(0);
    f1 << "line3" << endl;
    // f1.pword("line1\n");
    f1.close();
}

void read_1()
{
    cout << "read" << endl;
    ifstream f2("file1-2.txt");
    string line;
    while (getline(f2, line))
    {
        cout << line << endl;
    }
    f2.close();
}

void read_2()
{
    cout << "read by chars" << endl;
    fstream f;
    f.open("file1-2.txt");
    while (!f.eof())
    {
        char ch;
        f >> ch;
        cout << ch;
    }
    f.close();
}

void read_buf_1()
{
    cout << "read into buffer" << endl;
    ifstream is("file1-2.txt", ifstream::binary);
    is.seekg(0, is.end);
    int len = is.tellg();
    is.seekg(0, is.beg);

    int buf_size = 50;
    char *buf = new char[buf_size];

    is.read(buf, buf_size);
    is.close();

    cout << "print buffer" << endl;
    cout << buf << endl;

    cout << "print buffer 2" << endl;
    cout.write(buf, 50) << endl;
    delete[] buf;
}

void rw_random()
{
    cout << "write on random position" << endl;
    ofstream f1("file2.txt", fstream::binary);
    f1 << "line1" << endl;
    f1 << "line2" << endl;
    f1.seekp(-6, f1.end);
    f1 << "l3";
    f1.flush();
    f1.close();

    ifstream f2("file2.txt", fstream::binary);
    string str;
    f2.seekg(-6, f2.end);
    f2 >> str;
    f2.close();
    cout << str << endl;
}

int main(int argc, char const *argv[])
{
    write_1();
    read_1();
    read_2();
    read_buf_1();
    rw_random();

    return 0;
}
