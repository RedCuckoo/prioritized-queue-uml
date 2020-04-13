/*!
	\file
	\brief Header file containing class Figure

	This file contains template definition and implementation of geometry figure, a base class
*/

#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

/*!
\brief A base class for figures
\details An implementation of the Figure, base class
*/
class Figure {
public:
	virtual std::string to_string() = 0;
};

#endif //FIGURE_H