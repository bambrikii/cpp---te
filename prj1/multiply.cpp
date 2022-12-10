#ifndef MULTIPLY_CPP
#define MULTIPLY_CPP

int multiply(int a, int b)
{
    return a * b;
}

int* multiplyRef(int *a, int *b)
{
    int c;
    c = (*a) * (*b);
    return &c;
}

#endif
