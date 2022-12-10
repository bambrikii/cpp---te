#include <iostream>

#include "decls.hpp"
#include "func_obj1.cpp"
#include "interceptor1.cpp"

using namespace std;

class Cls1
{
public:
    int method1(FuncObj1 &func11)
    {
        // Interceptor1 interceptor1;
        // int val = func11(interceptor1);
        int val = func11();
        cout << " in method1() " << val << endl;
        return val;
    }
};

void func1()
{
    FuncObj1 func1 = (1);
    Cls1 cls1;
    int val = cls1.method1(func1);
    cout << " in func1() " << val << endl;
    val = cls1.method1(func1);
    cout << " in func1() " << val << endl;
}

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}
