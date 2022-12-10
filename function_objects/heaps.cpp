#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_vector(vector<T> vec1, string &&message)
{
    cout << message << endl;
    cout << "  ";
    for (auto i = vec1.begin(); i != vec1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void heap_asc()
{
    vector<int> vec1 = {1, 2, 3};
    print_vector<int>(vec1, "heap asc before");

    make_heap(vec1.begin(), vec1.end(), greater<int>());
    print_vector<int>(vec1, "after heapify greater");
}

void heap_desc()
{
    vector<int> vec1 = {1, 2, 3};
    print_vector(vec1, "heap desc before");

    make_heap(vec1.begin(), vec1.end(), less<int>());
    print_vector<int>(vec1, "after heapify");

    pop_heap(vec1.begin(), vec1.end(), less<int>());
    vec1.pop_back();
    print_vector<int>(vec1, "after pop_back " + to_string(vec1.front()));

    pop_heap(vec1.begin(), vec1.end(), less<int>());
    vec1.pop_back();
    print_vector<int>(vec1, "after pop_back " + to_string(vec1.front()));

    vec1.push_back(5);
    push_heap(vec1.begin(), vec1.end());
    print_vector<int>(vec1, "after push_heap " + to_string(vec1.front()));

    pop_heap(vec1.begin(), vec1.end(), less<int>());
    vec1.pop_back();
    print_vector<int>(vec1, "after pop_back " + to_string(vec1.front()));

    pop_heap(vec1.begin(), vec1.end(), less<int>());
    vec1.pop_back();
    print_vector<int>(vec1, "after pop_back " + to_string(vec1.front()));
}

int main(int argc, char const *argv[])
{
    heap_asc();
    heap_desc();

    return 0;
}
