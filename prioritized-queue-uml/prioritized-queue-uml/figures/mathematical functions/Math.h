/*!
	\file
	\brief Header file containing definitions of some mathemetical functions
*/

#ifndef MATH_H
#define MATH_H

#include <vector>

class Circle;
class Line;

/*!
\brief Solver of square equation
\details Solves a kvadratic equation, with data types of double. The following parameters are: a * x^2 + b * x + c = 0
\param double a Coeficient near x^2
\param double b Coeficient near x^1
\param double c Coeficient near x^0
\return A vector which contains either none, one or two Pair of numbers. First number is the solution of the equation, second number is not defined.
*/
std::vector<double> squareEquationSolver(double a, double b, double c);

/*!
\brief Reflect dot over a line
\param [in] baseLine The line, relatively to which the function will find symmetric point
\param [in] dot The starting point, which symmetrical reflection you would like to find
\return The symmetric point to the given with the parameter dot
*/
std::pair<double, double> findSymmetricDot(const Line& baseLine, const std::pair<double, double> dot);

/*!
\brief Inverse a point relatively to the given Circle
\param [out] to_inverse A reference to the point, which will be inversed as the answer.=
\param [in] baseCircle A Circle, relatively to which the function will find an inversion
*/
void inversePoint(std::pair<double, double>& to_inverse, const Circle& baseCircle);

#endif // !MATH_H
