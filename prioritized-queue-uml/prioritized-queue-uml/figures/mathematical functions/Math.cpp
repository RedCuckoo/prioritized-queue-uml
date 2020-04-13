/*!
	\file
	\brief C++ file containing implementations of Math.h
*/

#include "Math.h"
#include "..\Line.h"
#include "..\Circle.h"
#include <vector>

/*!
The function looks for a discriminant.
If it is greated than 0, then we have two answers, x1/x2 = (-b +/- sqrt(D)) / (2 * a).
If it is equal to 0, then we have one answer x = -b / (2 * a).
If it is less than 0, then we don't have rational roots.
*/
std::vector<double> squareEquationSolver(double a, double b, double c) {
	//double d = b * b - 4 * a * c;
	//std::vector<double> ans;
	//if (d > 0) {
	//	ans.push_back((-b + sqrt(d)) / (2 * a));
	//	ans.push_back((-b - sqrt(d)) /	
	//		(2 * a));
	//}
	//else if (d == 0) {
	//	ans.push_back(-b / (2 * a));
	//}
	//else {

	//}
	//return ans;

	std::vector<double> ans;

	if (a) {
		if (b) {
			if (c) {
				double d = b * b - 4 * a * c;	
				if (d > 0) {
					ans.push_back((-b + sqrt(d)) / (2 * a));
					ans.push_back((-b - sqrt(d)) / (2 * a));
				}
				else if (d == 0) {
					ans.push_back(-b / (2 * a));
				}
				else {

				}
			}
			else {
				ans.push_back(0);
				ans.push_back(-b / a);
			}
		}
		else {
			if (c) {
				if ((a >= 0 && c <= 0) || (a <= 0 && c >= 0)) {
					ans.push_back(sqrt(-c / a));
					ans.push_back(-ans[0]);
				}
			}
			else {
				ans.push_back(0);
			}
		}
	}
	else {
		if (b) {
			if (c) {
				ans.push_back(-c / b);
			}
			else {
				ans.push_back(0);
			}
		}
		else {

		}
	}


	return ans;
}

/*!
The function looks onto two general cases: coeficient near y in a standart form of the equation of the line equals 0 (b == 0 && b != 0).

In such a way, if coeficient doesn't equal 0, then we can rewrite the equation to the slope form.
Slope form allows us to write an equation of the perpendicular line and with the formula of the distance we can get the formula of the symmetric points:
x = 2 * ( (k * (l - y0) - x0) / ( - k^2 - 1) ), where k - is the slope of the given line (k = -a / b); x0, y0 - given point.
y = 2 * k * ( ((l - y0) * k - x0) / ( - k^2 - 1) ) + 2 * l - y0, where l - is the y-intersection of the given line (l = -c / b).

If b == 0, then the given line is x == const. This way, y coordinate won't change and x coordinate 2 * (- c / a ) - x0
*/
std::pair<double, double> findSymmetricDot(const Line& baseLine, const std::pair<double, double> dot) {
	double a = baseLine.a, b = baseLine.b, c = baseLine.c, x = dot.first, y = dot.second;
	std::pair<double, double> ans;
	if (b) {
		double slope = -a / b, y_intersection = -c / b;
		ans.first = 2 * ((slope * (y_intersection - y) - x) / (-slope * slope - 1)) - x;
		ans.second = 2 * slope * (((y_intersection - y) * slope - x) / (-slope * slope - 1)) + 2 * y_intersection - y;
	}
	else {
		//x = const
		if (a) {
			ans.first = 2 * (-c / a) - x;
			ans.second = y;
		}
	}
	return ans;
}

/*!
This function uses a basic formula for inversion of the point relatively to the circle.
Before applying them function have to make sure, that this point isn't a center of the basic circle.
Once ensured, function applies the following formulas:
x = x0 + (r^2 * (x1 - x0)) / ( (x1 - x0)^2 + (y1 - y0)^2 );
y = y0 + (r^2 * (y1 - y0)) / ( (x1 - x0)^2 + (y1 - y0)^2 ), where (x1, y1) is the given point, (x0, y0) - center of the base Circle and r is its' radius.
*/
void inversePoint(std::pair<double, double>& to_inverse, const Circle& baseCircle) {
	double x = to_inverse.first, y = to_inverse.second, x0 = baseCircle.center.first, y0 = baseCircle.center.second, r = baseCircle.radius;
	if (x != x0 || y != y0) {
		to_inverse.first = x0 + ((r * r * (x - x0)) / ((x - x0) * (x - x0) + (y - y0) * (y - y0)));
		to_inverse.second = y0 + ((r * r * (y - y0)) / ((x - x0) * (x - x0) + (y - y0) * (y - y0)));
	}
}

bool is_equal(double x, double y) {
	return std::fabs(x - y) < EPSILON;
}