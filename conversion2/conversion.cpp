// Convert between inches and cm
#include <iostream>
#include "length.hpp"
#include "length.cpp"

using namespace std;

int main(int argc, char** argv) {
    length l;
    double x;

    char choice;
    cout << "Choose units to enter: (c) or (i): ";
    cin >> choice;
    cout << "Enter value in ";
    switch (choice) {
    case 'c': cout << "centimeters: "; break;
    case 'i': cout << "inches: "; break;
    }

    cin >> x;
    switch (choice) {
    case 'c': l.cm(x); break;
    case 'i': l.inches(x); break;
    }

    switch (choice) {
    case 'c': cout << x << " centimeters is "
        << l.inches() << " inches." << endl;
        break;
    case 'i': cout << x << " inches is "
        << l.cm() << " centimeters." << endl;
        break;
    }

    return 0;
}
