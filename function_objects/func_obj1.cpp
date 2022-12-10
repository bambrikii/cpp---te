#ifndef FUNC_OBJ1_CPP
#define FUNC_OBJ1_CPP 1
#include <iostream>
#include "func_obj1.hpp"

using namespace std;

int FuncObj1::get_prop1()
{
    return prop1;
}

int FuncObj1::operator()()
{
    prop1++;
    cout << " in operator() " << prop1 << endl;
    return prop1;
};

int FuncObj1::operator()(Intercetor1 &interceptor)
{
    prop1++;
    cout << " in operator() " << prop1 << endl;
    // interceptor.intercept(this);
    return prop1;
};

FuncObj1::FuncObj1(int &&prop1) : prop1(prop1){};
#endif