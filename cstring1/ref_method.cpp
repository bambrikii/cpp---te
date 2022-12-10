#include <iostream>
using namespace std;

void square(int &);

int main() {
	int number = 1;
	cout << number << endl;
	cout << &number << endl;

	square(number);

	cout << number << endl;
	cout << &number << endl;

}

void square(int & num) {
	cout << "in square: " << &num << ", " << num << endl;
	num = 2;
}
