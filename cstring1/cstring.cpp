#include <iostream>
#include <cstring>
using namespace std;

int count(const char * str, const char c);

int main() {
	char msg1[] = "asd";
	char * msg2 = "asd";
	cout << count(msg1, 'd') << endl;
	cout << count(msg2, 'd') << endl;
	cout << count("asd", 'd') << endl;
}



int count(const char * str, const char c) {
	int count = 0;
	while (*str) {
		if (*str == c) ++ count;
		++str;
	}
	return count;
}
