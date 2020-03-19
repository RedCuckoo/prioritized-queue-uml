/*!
	\file
	\brief C++ file containing class Line

	This file contains implementation of such figure as Line
*/

#include "Line.h"	
#include <vector>
#include "Circle.h"
#include "..//priority_queue_data_structure/data_structures/Pair.h"
#include "mathematical functions/Math.h"

/*!
\brief Constructor
\details Create a Line from two points.
\param [in] fPoint One of the points, which form a Line
\param [in] sPoint Another of the points, which form a Line
*/
Line::Line(Pair<double, double> fPoint, Pair<double, double> sPoint) {
	double x1 = fPoint.getVal(), x2 = sPoint.getVal(), y1 = fPoint.getPrior(), y2 = sPoint.getPrior();
	a = y2 - y1;
	b = x1 - x2;
	c = x2 * y1 - x1 * y2;
}

/*!
\brief Intersect current Line with a provided Circle
\details The function calculates points of intersection between an object of this class and a Circle.
\param [in] to_find A Circle that this object intersects with
\return A vector of points of intersection

This function uses already defined and implemented function, from the class of Circle.
*/
std::vector<Pair<double, double>> Line::intersection(const Circle& to_find) {
	Circle copy = to_find;
	return copy.intersection(*this);
}

/*!
\brief Intersect current Line with a provided Line
\details The function calculates points of intersection between an object of this class and a Line.
\param [in] to_find A Line that this object intersects with
\return A vector of points of intersection
*/
std::vector<Pair<double, double>> Line::intersection(const Line& to_find) {
	double a2 = to_find.a, b2 = to_find.b, c2 = to_find.c;
	double temp = a2 * b - a * b2;
	std::vector<Pair<double, double>> ans;
	Pair<double, double> temp_pair;
	if (temp && b) {
		temp_pair.setVal((c * b2 - c2 * b) / temp);
		temp_pair.setPrior((-a / b)* temp_pair.getVal() - c / b);
		ans.push_back(temp_pair);
	}
	else if (!b && !b2) {

	}
	else if (!a && !a2) {

	}
	else if (temp && a) {
		//b == 0
		//b2 !=0
		temp_pair.setVal(-c / a);
		temp_pair.setPrior((-a2 / b2) * temp_pair.getVal() - c2 / b2);
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
	Pair<double, double> inter = intersection(baseLine)[0];
	if (inter != Pair<double, double>()) {
		//if they aren't paralel
		Pair<double, double> temp = inter;
		if (a && b) {
			temp.setVal(inter.getVal() + 1);
			temp.setPrior((-a / b) * temp.getVal() - c / b);
		}
		else if (!a && b) {
			temp.setVal(inter.getVal() + 1);
			temp.setPrior(- c / b);
		}
		else if (a && !b) {
			temp.setVal(inter.getVal() );
			temp.setPrior(inter.getPrior() + 1);
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
	Pair<double, double> diamPoint;
	double x0 = baseCircle.center.getVal(), y0 = baseCircle.center.getPrior();
	diamPoint.setVal((b * b * x0 - a * c - a * b * y0) / (b * b + a * a));
	diamPoint.setPrior((-a / b) * diamPoint.getVal() - c / b);
	inversePoint(diamPoint, baseCircle);
	return Circle((x0 + diamPoint.getVal()) / 2, (y0 + diamPoint.getPrior()) / 2, sqrt((diamPoint.getVal() - x0) * (diamPoint.getVal() - x0) + (diamPoint.getPrior() - y0) * (diamPoint.getPrior() - y0)) / 2);
}

/*!
\brief Output stored information
\details Print stored fields of the Line to the console, using <iostream> library
*/
void Line::out() {
	double x1 = 0, y1 = ((b) ? (-c / b) : 0);
	double x2 = ((a) ? (-c/a) : 0), y2 = 0;
	if (a && b) {
		std::cout << "(" << x1 << "," << y1 << ") , (" << x2 << "," <<y2<< ")";
	}
	else if (a) {
		std::cout << "x = " << (-c / a);
	}
	else if (b){
		std::cout << "y = " << (-c / b);
	}
	else {
		std::cout << "Line isn't correct";
	}
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the Line that has to be compared with the Line passed as an lvalue
\return True value if they are equal and false value otherwise
*/
bool Line::operator==(const Line& to_compare) const{
	double a1 = to_compare.a, b1 = to_compare.b, c1 = to_compare.c;
	return (a == a1 && b == b1 && c == c1) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the Line that has to be compared with the Line passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
bool Line::operator!=(const Line& to_compare) const{
	return (*this == to_compare) ? false : true;
}
