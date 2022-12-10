#include <stdio.h>
// #include <cstdio>
#include <iostream>
#include <fstream>

// using cout = stdin::cout
using namespace std;


void* operator new (size_t size, const char* filename, int line) {
    void* ptr = new char[size];
    cout << "size = " << size << " filename = " << filename << " line = " << line << endl;
    return ptr;
}

#define new new(__FILE__, __LINE__)


int main(int argc, char** argv) {
    printf("argc: %d", argc);
    cout << "... argc " << argc << ", argv " << (char*)argv << "\n";
    for (int i = 0; i < 100; i++) {
        //	cout << "	i: " << i << "\n";
        int* x = new int(i);
        delete x;
    }

    ofstream f1;
    f1.open("mem.log");
    for (int i = 0; i < 100; i++) {
        int* x = new int(i);
        f1 << "M, " << "" << endl;
        delete x;
    }
    f1.close();

    return 1;
}