#include <iostream>
#include <string>

using namespace std;

void words_in_reverse(string &&str)
{
    cout << "words in reverse. input = " << str << endl;
    string delim = " ,.";
    int start = str.find_first_not_of(delim);
    while (start != string::npos)
    {
        int end = str.find_first_of(delim, start);
        if (end == string::npos)
        {
            end = str.length();
        }

        for (int i = end - 1; i >= start; i--)
        {
            cout << str[i];
        }
        if (str[end] == '.' || str[end] == ',')
        {
            cout << str[end];
        }

        cout << " ";

        start = str.find_first_not_of(delim, end);
    }
    cout << endl;
}

void reserve1()
{
    string str;
    str.reserve(5);
    str[1] = 'a';
    str.shrink_to_fit();
}

int main(int argc, char const *argv[])
{
    string str1 = "abcde";
    size_t pos1 = str1.find("f");
    if (pos1 == string::npos)
    {
        cout << " not found 1" << endl;
    }

    size_t pos2 = str1.find("c");
    if (pos2 != string::npos)
    {
        cout << " pos 2 " << pos2 << endl;
    }

    string str2 = str1;
    cout << " replace    " << str1.replace(pos2, 1, "_1_2_3_") << endl;
    cout << " original   " << str1 << endl;
    cout << " copied     " << str2 << endl;
    cout << " substr 2   " << str1.substr(2) << endl;
    cout << " substr 2-3 " << str1.substr(2, 3) << endl;
    string str3 = str1 + "suffix";
    cout << " append     " << str3 << endl;
    cout << " insert     " << str1.insert(1, "ins") << endl;

    words_in_reverse("abc def,    ghi, jk. a");
    reserve1();

    return 0;
}
