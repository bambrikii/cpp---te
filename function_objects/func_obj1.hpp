#ifndef FUNC1
#define FUNC1 1
#include "decls.hpp"
#include "interceptor1.hpp"

class FuncObj1
{
private:
    int prop1;

public:
    FuncObj1(int &&prop1);

    int get_prop1();

    int operator()();
    int operator()(Intercetor1 &interceptor);
};

#endif