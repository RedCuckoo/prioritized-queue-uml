/*!
	\file
	\brief C++ file containing class Line

	This file contains implementation of such figure as Line
*/

#include "Line.h"	
#include <vector>
#include "Circle.h"
#include "mathematical functions/Math.h"
#include <string>
#include <sstream>

/*!
\brief Constructor
\details Create a Line from two points.
\param [in] fPoint One of the points, which form a Line
\param [in] sPoint Another of the points, which form a Line
*/
Line::Line(std::pair<double, double> fPoint, std::pair<double, double> sPoint) {
	double x1 = fPoint.first, x2 = sPoint.first, y1 = fPoint.second, y2 = sPoint.second;
	a = y2 - y1;
	b = x1 - x2;
	c = x2 * y1 - x1 * y2;
	undef = false;
}

Line::Line(const Line& to_copy) {
	if (to_copy.undef) {
		undef = true;
	}
	else {
		a = to_copy.a;
		b = to_copy.b;
		c = to_copy.c;
		undef = false;
	}
}

/*!
\brief Intersect current Line with a provided Circle
\details The function calculates points of intersection between an object of this class and a Circle.
\param [in] to_find A Circle that this object intersects with
\return A vector of points of intersection

This function uses already defined and implemented function, from the class of Circle.
*/
std::vector<std::pair<double, double>> Line::intersection(const Circle& to_find) {
	Circle copy = to_find;
	return copy.intersection(*this);
}

/*!
\brief Intersect current Line with a provided Line
\details The function calculates points of intersection between an object of this class and a Line.
\param [in] to_find A Line that this object intersects with
\return A vector of points of intersection
*/
std::vector<std::pair<double, double>> Line::intersection(const Line& to_find) {
	double a2 = to_find.a, b2 = to_find.b, c2 = to_find.c;
	double temp = a2 * b - a * b2;
	std::vector<std::pair<double, double>> ans;
	std::pair<double, double> temp_pair;
	if (temp && b) {
		temp_pair.first = (c * b2 - c2 * b) / temp;
		temp_pair.second = (-a / b) * temp_pair.first - c / b;
		ans.push_back(temp_pair);
	}
	else if (!b && !b2) {

	}
	else if (!a && !a2) {

	}
	else if (temp && a) {
		//b == 0
		//b2 !=0
		temp_pair.first = -c / a;
		temp_pair.second = (-a2 / b2) * temp_pair.first - c2 / b2;
		ans.push_back(temp_pair);
	}
	else{
	}
	return ans;
}

/*!
\brief Symmetrical reflection of the object over given Line
\details Function finds a Line which is a symmetrical to the object over the given Line
\param baseLine The Line over which the symmetrical object is being calculated

The function checks, if the lines aren't in the form of x = const.
If they are not, the function will find the intersection points, choose a point which is not on the intersection and return a Line out of two points.
Also some trivial cases are included to prevent division on 0.
*/
void Line::reflectOverLine(const Line& baseLine) {
	std::pair<double, double> inter = intersection(baseLine)[0];
	//TODO: check this
	if (inter != std::pair<double, double>()) {
		//if they aren't paralel
		std::pair<double, double> temp = inter;
		if (a && b) {
			temp.first = inter.first + 1;
			temp.second = (-a / b) * temp.first - c / b;
		}
		else if (!a && b) {
			temp.first = inter.first + 1;
			temp.second = - c / b;
		}
		else if (a && !b) {
			temp.first = inter.first;
			temp.second = inter.second + 1;
		}
		else {
			return;
		}

		temp = findSymmetricDot(baseLine,temp);
		*this = Line(inter, temp);
	}
}

/*!
\brief Inverse of a Line
\param [in] baseCircle A Circle of inversion
\return A newly formed Circle. Circle() is returned, if the center of base Circle is laying on the Line.

If the center of the base Circle doesn't lay on the Line, the inversion of the Line will be a Circle.
The center of the base Circle will lay on the newly formed Circle. 

If the center of the base Circle lays on the Line, the inversion of the Line will be Line itself. 

The function calculates the closes point of the newly formed Circle to the Line, following the calculation on the center and radius relatively.
*/
Circle Line::inverse(const Circle& baseCircle) {
	std::pair<double, double> diamPoint;
	double x0 = baseCircle.center.first, y0 = baseCircle.center.second;
	diamPoint.first = (b * b * x0 - a * c - a * b * y0) / (b * b + a * a);
	diamPoint.second = (-a / b) * diamPoint.first - c / b;
	inversePoint(diamPoint, baseCircle);
	return Circle((x0 + diamPoint.first) / 2, (y0 + diamPoint.second) / 2, sqrt((diamPoint.first - x0) * (diamPoint.first - x0) + (diamPoint.second - y0) * (diamPoint.second - y0)) / 2);
}

/*!
\brief Output stored information
\details Print stored fields of the Line to the console, using <iostream> library
*/
std::string Line::to_string() {
	std::string ans = "";

	std::ostringstream ss;
	ss << *this;

	return ss.str();
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the Line that has to be compared with the Line passed as an lvalue
\return True value if they are equal and false value otherwise
*/
bool Line::operator==(const Line& to_compare) const{
	if (to_compare.undef) {
		if (undef) {
			return true;
		}
		else {
			return false;
		}
	}

	double a1 = to_compare.a, b1 = to_compare.b, c1 = to_compare.c;
	bool ans = 1;

	if (a && b) {
		ans *= is_equal(a1 / a, b1 / b);
	}
	else if (a1 && b1) {
		ans *= is_equal(a / a1, b / b1);
	}

	if (b && c) {
		ans *= is_equal(b1 / b, c1 / c);
	}
	else if (b1 && c1) {
		ans *= is_equal(b / b1, c / c1);
	}

	if (a && c) {
		ans *= is_equal(a1 / a, c1 / c);
	}
	else if (a1 && c1) {
		ans *= is_equal(a / a1, c / c1);
	}

	return (ans) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the Line that has to be compared with the Line passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
bool Line::operator!=(const Line& to_compare) const{
	return (*this == to_compare) ? false : true;
}
