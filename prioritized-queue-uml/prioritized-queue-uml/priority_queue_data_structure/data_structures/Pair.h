/*!
	\file
	\brief Header file containing class Pair

	This file contains template definition and implementation of such data structure as a Pair, which is customized
*/

#ifndef PAIR_H
#define PAIR_H

#include <iostream>

/*!
	\brief Customized Pair
	\details A custom implementation of Pair<value_type,priority_type>, as it is used for queue with priority fields have the related names
	Currently it is possible to create a Pair only through the provided constructor
*/
template<class value_type, class priority_type = unsigned int>
class Pair {
private:
	value_type value;
	priority_type priority;

	/*!
	\brief Friended operator<<
	\details Allows to output information with the stream
	*/
	template<class value_type, class priority_type>
	friend std::ostream& operator<<(std::ostream& out, const Pair<value_type, priority_type>& to_out);
public:
	/*!
	\brief Constructor
	\details Allowing a default constructor access
	*/
	Pair() = default;
	Pair(value_type val, priority_type prior);

	value_type getVal() const;
	void setVal(const value_type& val);
	priority_type getPrior() const;

	void setPrior(const priority_type& pr);
	bool operator>(const Pair<value_type, priority_type>& to_compare) const;
	bool operator>=(const Pair<value_type, priority_type>& to_compare) const;
	bool operator<(const Pair<value_type, priority_type>& to_compare) const;
	bool operator<=(const Pair<value_type, priority_type>& to_compare) const;
	bool operator==(const Pair<value_type, priority_type>& to_compare) const;
	bool operator!=(const Pair<value_type, priority_type>& to_compare) const;

	void out();
};

/*!
\brief Constructor
\details A constructor to create a pair for the queue with priority
\param[in] val The value which queue stores
\param[in] prior The priority which provided value has
*/
template<class value_type, class priority_type>
Pair<value_type, priority_type>::Pair(value_type val, priority_type prior) {
	value = val;
	priority = prior;
}

/*!
\brief Getter method for the value
\details To get the value of the Pair
*/
template<class value_type, class priority_type>
value_type Pair<value_type, priority_type>::getVal() const {
	return value;
}

/*!
\brief Setter method for the value
\details To set the value of the Pair
*/
template<class value_type, class priority_type>
void Pair<value_type, priority_type>::setVal(const value_type& val) {
	value = val;
}

/*!
\brief Getter method for the priority
\details To get the priority of the Pair
*/
template<class value_type, class priority_type>
priority_type Pair<value_type, priority_type>::getPrior() const {
	return priority;
}

/*!
\brief Setter method for the priority
\details To set the priority of the Pair
*/
template<class value_type, class priority_type>
void Pair<value_type, priority_type>::setPrior(const value_type& pr) {
	priority = pr;
}

/*!
\brief Overloaded "is bigger than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is bigger than to_compare and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator>(const Pair<value_type, priority_type>& to_compare) const {
	return (priority > to_compare.getPrior()) ? true : false;
}

/*!
\brief Overloaded "is bigger or equal than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is bigger or equal than to_compare and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator>=(const Pair<value_type, priority_type>& to_compare) const {
	return (priority >= to_compare.getPrior()) ? true : false;
}

/*!
\brief Overloaded "is less than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is less than to_compare and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator<(const Pair& to_compare) const {
	return (priority < to_compare.getPrior()) ? true : false;
}

/*!
\brief Overloaded "is less or equal than" operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if current Pair is less or equal than to_compare and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator<=(const Pair<value_type, priority_type>& to_compare) const {
	return (priority <= to_compare.getPrior()) ? true : false;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator==(const Pair<value_type, priority_type>& to_compare) const {
	return (priority == to_compare.getPrior() && value == to_compare.getVal()) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the Pair that has to be compared with the Pair passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template<class value_type, class priority_type>
bool Pair<value_type, priority_type>::operator!=(const Pair<value_type, priority_type>& to_compare) const {
	return (priority != to_compare.getPrior() || value != to_compare.getVal()) ? true : false;
}

/*!
\brief Output stored information
\details Print stored fields of the Pair to the console, using <iostream> library
*/
template<class value_type, class priority_type>
void Pair<value_type, priority_type>::out() {
	if (this)
		std::cout << value << " " << priority << std::endl;
}

//--------------------end-of-Pair-functions-implementation----------------------------

/*!
\brief Operator<<
\detail Allows to output information with the stream
\param out Stream which is defined automatically, has to be ostream or inherited streams
\param to_out This parameter is passed on the right of "<<", not changeble, the reference to the Pair that has to be outputted
\return Reference to the ostream, to allow continous streaming, like
	\code
	Pair<int,int> a = {3,4};
	Pair<int,int> b = {6,7};
	std::cout << a << b;
	//The output will be:
	//3 4
	//6 7
	\endcode
*/
template <class value_type, class priority_type>
std::ostream& operator<<(std::ostream& out_stream, const Pair<value_type, priority_type>& to_out) {
	if (to_out != Pair<value_type, priority_type>())
		std::cout << to_out.value << " " << to_out.priority;// << std::endl;
	return out_stream;
}

#endif // !PAIR_H
