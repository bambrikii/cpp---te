#ifndef INTERCEPTOR1
#define INTERCEPTOR1 1
#include "decls.hpp"
#include "func_obj1.hpp"

class Intercetor1
{
public:
    // Intercetor1();
    void intercept(FuncObj1 &func1);
};

#endif