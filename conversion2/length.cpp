// Convert between inches and cm
#include "length.hpp"

double length::cm() { return d*100; }
void length::cm(double x) { d = x/100; }
double length::inches() { return d*INCHES_PER_METER; }
void length::inches(double x) { d = x/INCHES_PER_METER; }
