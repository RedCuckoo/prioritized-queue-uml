/*!
	\file
	\brief Header file containing class Circle

	This file contains template definition and implementation of geometry figure, circle
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "base figure/Figure.h"
#include "mathematical functions/Math.h"
#include "Line.h"
#include <vector>

/*!
\brief A figure Circle
\details An implementation of the circle, given in a standart form: two points for center and radius
*/
class Circle : public Figure {
private:
	//constuructor sets radius to positive value
	double radius;
	std::pair<double, double> center;
	
	bool centerBelongToCircle(const Circle& to_check);

	/*!
	\brief Friended class Line
	\details Gives access to private fields of class Line
	*/
	friend class Line;

	/*!
	\brief Friended operator<<
	\details Allows to output information with the stream
	*/
	friend std::ostream& operator<<(std::ostream& out, const Circle& to_out);

	/*!
	\brief Friended function of the inverse of the point
	\details Function inversePoint(Pair<double, double>&, const Circle&) gets access to the private field of the Circle
	*/
	friend void inversePoint(std::pair<double, double>&, const Circle&);
public:
	/*!
	\brief Default constructor
	\details Creates an uninitialized object of class Circle, doesn't store any data, only for comparison
	*/
	Circle() = default;
	
	/*!
	\brief Constructor
	\detais Create an object from the given parametes
	\param [in] x The x coordinate of the center of the newly created Circle.
	\param [in] y The y coordinate of the center of the newly created Circle.
	\param [in] rad The radius of the newly created Cycle
	*/
	Circle(double x, double y, double rad) : radius((rad > 0) ? rad : -rad), center(std::pair<double, double>(x, y)) {		}
	Circle(const Circle& to_copy) : radius(to_copy.radius), center(to_copy.center)  {		}

	std::vector<std::pair<double, double>> intersection(const Line& to_find);
	std::vector<std::pair<double, double>> intersection(const Circle& to_find);
	void reflectOverLine(const Line& baseLine);
	Line inverse(const Circle& baseCircle);

	bool operator== (const Circle& to_compare) const;
	bool operator!= (const Circle& to_compare) const;

	std::string to_string();
};

inline std::ostream& operator<<(std::ostream& out_stream, const Circle& to_out) {

	out_stream << "(" << to_out.center.first << ", " << to_out.center.second << "), radius = " << to_out.radius;// << " = 0";
	return out_stream;
}

#endif // !CIRCLE_H
