#include <locale>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    const numpunct<char> &fac = use_facet<numpunct<char>>(locale::classic()); // de
    cout << "true in Classic: " << fac.truename() << endl;                    // ERROR

    std::locale loc(locale(""));

    std::cout.imbue(loc);
    std::cout << std::boolalpha << true << std::endl;

    return 0;
}
