#ifndef INTERCEPTOR1_CPP
#define INTERCEPTOR1_CPP 1
#include <iostream>
#include "decls.hpp"
#include "interceptor1.hpp"

using namespace std;

// Interceptor1::Interceptor1(){
// };

void Intercetor1::intercept(FuncObj1 &func1)
{
    cout << " in intercept " << func1.get_prop1() << endl;
};
#endif