#ifndef APPROXIMATION_FUNCTIONS
#define APPROXIMATION_FUNCTIONS

#include <cmath>
#include <limits>

bool is_equal(double x, double y) {
	return std::fabs(x - y) < 0.00000000001;
}

#endif //APPROXIMATION_FUNCTIONS