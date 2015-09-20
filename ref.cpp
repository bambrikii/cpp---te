#include <iostream>

using namespace std;

int main() {
	int num = 1;
	int * pNum = &num;
	int & rNum = num;
	cout << num << endl;
	cout << pNum << endl;
	cout << rNum <<endl;
	cout << &rNum <<endl;

	rNum = 2;
	cout << num << endl;
	cout << rNum <<endl;
	cout << &rNum <<endl;

	int num2 = 3;

	rNum = num2;
	cout << num << endl;
	cout << rNum <<endl;
	cout << &rNum <<endl;

}

