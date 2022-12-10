#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

void unordered_map() {
    std::cout << "unordered_map" << std::endl;
    std::string str1 = "1";
    std::string str2 = "2";
    std::string str3 = "3";
    std::unordered_map<std::string, int> map1;
    map1[str1] = 10;
    map1[str2] = 40;
    map1[str3] = 50;
    map1[str1] = 100;
    std::for_each(map1.begin(), map1.end(), [](std::pair<std::string, int> i) {
        std::cout << i.first << " - " << i.second << std::endl;
        });
}

struct Struct1 {
    std::string prop1;
    std::string prop2;
    Struct1(const std::string str) : prop1(std::move(str)) {

    }

    Struct1(const std::string str, const std::string prop2) : prop1(std::move(str)), prop2(std::move(prop2)) {

    }

    bool operator==(const Struct1& o) const {
        return prop1 == o.prop1;
    }

    bool operator<(const Struct1& o) const {
        return prop1 < o.prop1;
    }
};

struct Struct1Hasher {
    std::size_t operator() (const Struct1& obj) const
    {
        std::size_t h1 = std::hash<std::string>()(obj.prop1);
        std::size_t h2 = std::hash<std::string>()(obj.prop2);

        return h1 ^ h2;
    }
};

void map() {
    std::cout << "map" << std::endl;
    Struct1 str1 = Struct1("1");
    Struct1 str2 = Struct1("2");
    Struct1 str3 = Struct1("3");
    std::map<Struct1, int> map1;
    map1[str1] = 10;
    map1[str2] = 40;
    map1[str3] = 50;
    map1[str1] = 100;
    std::for_each(map1.begin(), map1.end(), [](std::pair<Struct1, int> i) {
        std::cout << i.first.prop1 << " - " << i.second << std::endl;
        });
}

void unordered_map_with_hashing() {
    std::cout << "unordered_map_with_hashing" << std::endl;
    Struct1 str1 = Struct1("1", "a");
    Struct1 str2 = Struct1("2", "b");
    Struct1 str3 = Struct1("3", "c");
    std::unordered_map<Struct1, int, Struct1Hasher> map1;
    map1[str1] = 10;
    map1[str2] = 40;
    map1[str3] = 50;
    map1[str1] = 100;
    std::for_each(map1.begin(), map1.end(), [](std::pair<Struct1, int> i) {
        std::cout << i.first.prop1 << " - " << i.second << std::endl;
        });
}

int main(int argc, char const* argv[])
{
    unordered_map();
    map();
    unordered_map_with_hashing();
    return 0;
}
