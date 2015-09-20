#include <iostream>
using namespace std;

int main() {
	int * p2 = NULL; 
	p2 = new int;
	*p2 = 1;
	cout << p2 << ", " << *p2 << endl;
	delete p2;
}

