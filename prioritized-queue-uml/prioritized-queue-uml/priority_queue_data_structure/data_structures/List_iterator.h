/*!
	\file
	\brief Header file containing class List_iterator

	This file contains template definition and implementation of an iterator for such data structure as a double linked list.
*/

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "List.h"

/*!
\brief iterator
\details A custom written class which implements iterators for the class List
It has the same properties as STL library std::random_access_iterator
*/
template <class value_type>
class List_iterator {
	/*!
	\brief Friended class List
	\details Gives access to private fields of class List
	*/
	template<class U>
	friend class List;

	/*!
	\brief Overloaded left adding to the List_iterator
	\details Friended function which overloads operation of adding integer value and List_iterator object
	As the result, it will shift iterator left or right (depending on the passed parameter
	*/
	template <class U>
	friend List_iterator<U> operator+ (int val, List_iterator<U> to_add);

	List<value_type>* list;
	typename List<value_type>::Node* node;
	typename List<value_type>::Node* operator->() const;
public:
	/*!
	\brief Constructor
	\default A default constuctor which creates an empty iterator with fields that are pointing to the null value
	*/
	List_iterator() : list(nullptr), node(nullptr) {	}

	/*!
	\brief Constructor
	\details A constructor that creates iterator from the provided parameters
	\param[in] list_ptr Pointer to the list, where current iterator belongs to
	\param[in] node_ptr Pointer to the node, where current iterator has to point
	*/
	List_iterator(List<value_type>* list_ptr, typename List<value_type>::Node* node_ptr) : list(list_ptr), node(node_ptr) {	}

	/*!
	\brief Copy constructor
	\details Overloaded copy constructor to make sure that it works as supposed to
	*/
	List_iterator(const List_iterator& to_copy) : list(to_copy.list), node(to_copy.node) {	}

	List_iterator& operator++();
	List_iterator operator++(int);
	List_iterator& operator--();
	List_iterator operator--(int);
	List_iterator& operator+(int val);
	List_iterator& operator-(int val);
	bool operator== (const List_iterator& to_compare) const;
	bool operator!= (const List_iterator& to_compare) const;
	value_type& operator*() const;
};

/*!
\brief Overloaded left increment operator
\return A reference to the iterator, pointing to the next element
*/
template <class value_type>
List_iterator<value_type>& List_iterator<value_type>::operator++() {
	node = node->next;
	return *this;
}

/*!
\brief Overloaded right increment operator
\return An iterator, pointing to the next element
*/
template <class value_type>
List_iterator<value_type> List_iterator<value_type>::operator++(int) {
	List_iterator result = *this;
	node = node->next;
	return result;
}

/*!
\brief Overloaded left decrement operator
\return A reference to the iterator, pointing to the previous element
*/
template <class value_type>
List_iterator<value_type>& List_iterator<value_type>::operator--() {
	node = node->prev;
	return *this;
}

/*!
\brief Overloaded right decrement operator
\return A reference to the iterator, pointing to the previous
*/
template <class value_type>
List_iterator<value_type> List_iterator<value_type>::operator--(int) {
	List_iterator result = *this;
	node = node->prev;
	return result;
}

/*!
\brief Overloaded summing operator, shifts iterator to the left or right relatively of the parameter
\param val If this parameter is >0 then it iterator shifts to the right, else - to the left
\return A reference to the iterator, pointing to the next or previous element
*/
template <class value_type>
List_iterator<value_type>& List_iterator<value_type>::operator+(int val) {
	if (val > 0) {
		for (unsigned int i = 0; i < val; ++i) {
			node = node->next;
		}
	}
	else if (val == 0) {

	}
	else {
		for (unsigned int i = 0; i < -val; ++i) {
			node = node->prev;
		}
	}
	return *this;
}

/*!
\brief Overloaded suntracting operator, shifts iterator to the left or right relatively of the parameter
\param val If this parameter is >0 then it iterator shifts to the left, else - to the right
\return A reference to the iterator, pointing to the next or previous element
*/
template <class value_type>
List_iterator<value_type>& List_iterator<value_type>::operator-(int val) {
	if (val > 0) {
		for (unsigned int i = 0; i < val; ++i) {
			node = node->prev;
		}
	}
	else if (val == 0) {

	}
	else {
		for (unsigned int i = 0; i < -val; ++i) {
			node = node->next;
		}
	}
	return *this;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the List_iterator that has to be compared with the List_Iterator passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template <class value_type>
bool List_iterator<value_type>::operator== (const List_iterator& to_compare) const {
	return (list == to_compare.list && node == to_compare.node);
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the List_iterator that has to be compared with the List_Iterator passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template <class value_type>
bool List_iterator<value_type>::operator!= (const List_iterator& to_compare) const {
	return (list != to_compare.list || node != to_compare.node);
}

/*!
\brief Overloaded dereference operator
\return A value (of the type value_type) that is stored in the node of the list that current iterator is pointing to
*/
template <class value_type>
value_type& List_iterator<value_type>::operator*() const {
	return node->value;
}

/*!
\brief Overloaded arrow dereference operator
\details It is private, for convinient implementations of methods only
\return A gives access to the elelments of the node, to which current iterator is pointing to
*/
template <class value_type>
typename List<value_type>::Node* List_iterator<value_type>::operator->() const {
	return node;
}

//--------------------------------end-of-List_iterator-functions-implementations----------------

/*!
\brief Overloaded left adding to the List_iterator
\details Shifts iterator left or right regardles of the parameter
\param val If val > 0, then passed List_iterator<value_type> to_add will be shifted to the right val positions
Otherwise - to the left
\param to_add This parameter is passed not via reference, because it is changed in the function
\return Copy of shifted to_add iterator
*/
template <class value_type>
List_iterator<value_type> operator+ (int val, List_iterator<value_type> to_add) {
	if (val >= 0) {
		for (int i = 0; i < val; ++i) {
			to_add.node = to_add.node->next;
		}
	}
	else {
		for (int i = 0; i < -val; ++i) {
			to_add.node = to_add.node->prev;
		}
	}
	return to_add;
}

#endif // !LIST_ITERATOR_H
