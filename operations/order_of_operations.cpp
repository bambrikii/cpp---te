#include <iostream>

void print(int i1, int i2)
{
    std::cout << i1 << " " << i2 << std::endl;
}

void print(int i1, int i2, int i3)
{
    std::cout << i1 << " " << i2 << " " << i3 << std::endl;
}

void print(int i1, int i2, int i3, int i4, int i5)
{
    std::cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << std::endl;
}

/*

java:
    ++i,++i
    1 2
    ++i,i++
    1 1
    i++,++i
    0 2

c++:
    ++i,++i
    2 2
    ++i,i++
    2 0
    i++,++i
    1 2

*/

int main(int argc, char const *argv[])
{
    {
        std::cout << "++i,++i" << std::endl;
        int i = 0;
        print(++i, ++i);
    }
    {
        std::cout << "++i,i++" << std::endl;
        int i = 0;
        print(++i, i++);
    }
    {
        std::cout << "i++,++i" << std::endl;
        int i = 0;
        print(i++, ++i);
    }
    {
        std::cout << "i++,i++,i++" << std::endl;
        int i = 0;
        print(i++, i++, i++);
    }
    {
        std::cout << "i++,i++,i++,i++,i++" << std::endl;
        int i = 0;
        print(i++, i++, i++, i++, i++);
    }
    return 0;
}
