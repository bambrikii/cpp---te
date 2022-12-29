#include <locale>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <exception>

using namespace std;

int main(int argc, char const *argv[])
{
    auto &num_get1 = use_facet<num_get<char>>(locale::classic());
    double b1;
    ios_base::iostate state;
    // num_get1.get<char, true>(cin, cin, ios_base::app, &state, &b1);

    auto &num_put1 = use_facet<num_put<char>>(locale::classic());
    num_put1.put(cout, cout, '*', 123.456);

    locale loc(locale::classic());
    const moneypunct<char, true> &mp = use_facet<moneypunct<char, true>>(loc);
    const money_put<char> &mpG = use_facet<money_put<char>>(loc);
    cout << endl;
    mpG.put(cout, false, cout, ' ', 12345.678);
    cout << endl;
    mpG.put(cout, true, cout, ' ', "12345.678");
    cout << endl;

    const std::money_get<char> &mg = std::use_facet<std::money_get<char>>(loc);
    long double val;
    // mg.get(cin, end, true, fs, err, val);

    auto &time = use_facet<time_put<char>>(loc);
    auto now = chrono::system_clock::now();
    std::time_t t = chrono::system_clock::to_time_t(now);
    tm *tm = localtime(&t);
    time.put(cout, cout, ' ', tm, 'x');
    cout << endl;

    string format = "%A, %x %X, %I:%M:%S %p\n";
    time.put(cout, cout, ' ', tm, format.c_str(), format.c_str() + format.size());
    cout << endl;

    return 0;
}
