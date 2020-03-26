/*!
	\file
	\brief C++ file containing implementations of Math.h
*/

#include "Math.h"
#include "..\Line.h"
#include "..\Circle.h"
#include "..\..\priority_queue_data_structure\data_structures\Pair.h"
#include <vector>

/*!
The function looks for a discriminant.
If it is greated than 0, then we have two answers, x1/x2 = (-b +/- sqrt(D)) / (2 * a).
If it is equal to 0, then we have one answer x = -b / (2 * a).
If it is less than 0, then we don't have rational roots.
*/
std::vector<Pair<double, double>> squareEquationSolver(double a, double b, double c) {
	double d = b * b - 4 * a * c;
	std::vector<Pair<double, double>> ans;
	if (d > 0) {
		Pair<double, double> p1, p2;
		p1.setVal((-b + sqrt(d)) / (2 * a));
		p2.setVal((-b - sqrt(d)) / (2 * a));
		ans.push_back(p1);
		ans.push_back(p2);
	}
	else if (d == 0) {
		Pair<double, double> p;
		p.setVal(-b / (2 * a));
		ans.push_back(p);
	}
	else {

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
Pair<double, double> findSymmetricDot(const Line& baseLine, const Pair<double, double> dot) {
	double a = baseLine.a, b = baseLine.b, c = baseLine.c, x = dot.getVal(), y = dot.getPrior();
	Pair<double, double> ans;
	if (b) {
		double slope = -a / b, y_intersection = -c / b;
		ans.setVal(2 * ((slope * (y_intersection - y) - x) / (-slope * slope - 1)) - x);
		ans.setPrior(2 * slope * (((y_intersection - y) * slope - x) / (-slope * slope - 1)) + 2 * y_intersection - y);
	}
	else {
		//x = const
		if (a) {
			ans.setVal(2 * (-c / a) - x);
			ans.setPrior(y);
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
void inversePoint(Pair<double, double>& to_inverse, const Circle& baseCircle) {
	double x = to_inverse.getVal(), y = to_inverse.getPrior(), x0 = baseCircle.center.getVal(), y0 = baseCircle.center.getPrior(), r = baseCircle.radius;
	if (x != x0 || y != y0) {
		to_inverse.setVal(x0 + ((r * r * (x - x0)) / ((x - x0) * (x - x0) + (y - y0) * (y - y0))));
		to_inverse.setPrior(y0 + ((r * r * (y - y0)) / ((x - x0) * (x - x0) + (y - y0) * (y - y0))));
	}
}