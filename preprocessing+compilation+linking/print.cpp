#include <iostream>

#include "print.hpp"
#include "guarded.hpp"


#ifdef __cplusplus
using namespace std;

void printSumInt(int val1, int val2) {
    cout << (val1 + val2) << endl;
}

void printSumFloat(float val1, float val2) {
    cout << (val1 + val2) << endl;
}
#endif

int main(int argc, char* argv[]) {
    printSumInt(1, 2);
    printSumFloat(1.5f, 2.5f);
    return 0;
}
