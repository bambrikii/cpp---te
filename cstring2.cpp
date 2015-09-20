#include <iostream>
#include <cstring>
using namespace std;

char * ref(char * str);

int main() {
	char msg1[] = "asd";
	cout << "1: " << & msg1 <<endl;

	char * cstr = ref(msg1);
	cout << "2: " << &cstr << endl;
	cout << "3: " << *cstr << endl;

	cout << "4: " << msg1 << endl;

	cstr--; cstr--; cstr--;
	cout << "5: " << cstr << endl;

	cstr++;cstr++;cstr++;cstr++;
	cout << "6: " << &cstr << endl;
}



char * ref(char * str) {
	int count = 0;
	while (*str) {
	    ++str;
	}
	return str;
}
