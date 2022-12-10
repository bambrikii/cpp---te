#include <iostream>
#include <queue>

using namespace std;

void pri_queue()
{
    priority_queue<int, vector<int>, less<int>> q;
    q.push(1);
    q.push(3);
    q.push(2);

    while (!q.empty())
    {
        cout << " " << q.top() << endl;
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    pri_queue();

    return 0;
}
