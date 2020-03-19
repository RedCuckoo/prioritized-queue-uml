/*!
	\file
	\brief Header file containing class List

	This file contains template definition and implementation of such data structure as a double linked list
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "List_iterator.h"

/*!
	\brief Double linked list
	\details A custom implementation of STL library std::list with custom random access iterator
*/
template <class value_type>
class List {
private:
	/*!
		\brief A node of double linked list
		\details This class stores pointers to the previous and next node.
		The value stored depends on the type given to the class List.
		As well it is possible to create an empty node, which will serve as the end of the list.
		Such possibility is provided by the "type" field.
	*/
	struct Node {
	public:
		value_type value;
		Node* next, * prev;
		bool type = 1;

		Node();
		Node(value_type val, Node* pr, Node* ne);
		void out();
		bool operator==(const Node& to_compare) const;
		bool operator!=(const Node& to_compare) const;
	};

	Node* head, * tail;

	/*!
	\brief Friended class List_iterator
	\details Gives access to private fields of class List
	*/
	template <class U>
	friend class List_iterator;

public:
	List_iterator<value_type> begin();
	List_iterator<value_type> end();
	List();
	bool empty();
	unsigned int size();
	void push_back(value_type val);
	List_iterator<value_type> insert(const List_iterator<value_type>& it, const value_type& to_insert);
	List_iterator<value_type> erase(List_iterator<value_type> it);
	bool operator==(List<value_type>& to_compare);
	bool operator!=(List<value_type>& to_compare);
};

/*!
\brief Constructor
\details Constructor which creates an empty node, which is used as the end of the list (iterator on the end of the list)
*/
template <class value_type>
List<value_type>::Node::Node() {
	type = 0;
	next = nullptr;
	prev = nullptr;
}

/*!
\brief Constructor
\details Constructor which creates a node from the provided parameters.
\param[in] val The value that node will store
\param[in] pr Pointer to the previous node (for the beginning of the list, nullptr is passed)
\param[in] ne Pointer to the next node (for the end of the list, pointer to an empty node is passed)
*/
template <class value_type>
List<value_type>::Node::Node(value_type val, Node* pr, Node* ne) {
	value = val;
	prev = pr;
	next = ne;
}

/*!
\brief Output stored information
\details Print stored value of the node to the console, using <iostream> library
*/
template <class value_type>
void List<value_type>::Node::out() {
	std::cout << value << std::endl;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the node that has to be compared with the node passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template <class value_type>
bool List<value_type>::Node::operator==(const Node& to_compare) const {
	return (type == to_compare.type && value == to_compare.value && next == to_compare.next && prev == to_compare.prev) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the node that has to be compared with the node passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template <class value_type>
bool List<value_type>::Node::operator!=(const Node& to_compare) const {
	return (type != to_compare.type || value != to_compare.value || next != to_compare.next || prev != to_compare.prev) ? true : false;
}

/*!
\brief Get iterator on the beginning
\details Method that returns the iterator to the beginning of the list
\return Iterator to the beginning of the list
*/
template <class value_type>
List_iterator<value_type> List<value_type>::begin() {
	return List_iterator<value_type>(this, head);
}

/*!
\brief Get iterator on the end
\details Method that returns the iterator to the end of the list
\return Iterator to the end of the list
*/
template <class value_type>
List_iterator<value_type> List<value_type>::end() {
	return List_iterator<value_type>(this, tail);
}

/*!
\brief Constructor
\details Default construct which creates a List object with no elements in it
*/
template <class value_type>
List<value_type>::List() {
	head = new Node();
	tail = head;
}

/*!
\brief Checks emptiness of the list
\details This method checks whether or not current list is empty
\return True value if the list is empty and false value otherwise
*/
template <class value_type>
bool List<value_type>::empty() {
	return (head == tail) ? true : false;
}

/*!
\brief Get the size of the list
\details To get the amount of elements of the list
\return Size of the list
*/
template <class value_type>
unsigned int List<value_type>::size() {
	Node* temp = head;
	unsigned int size = 0;
	while (temp != tail) {
		size++;
		temp = temp->next;
	}
	return size;
}

/*!
\brief Add elements
\details Add elements to the end of the list
\param[in] val Value which has to be added to the list
*/
template <class value_type>
void List<value_type>::push_back(value_type val) {
	if (head == tail) {
		head = new Node(val, nullptr, tail);
		tail->prev = head;
	}
	else {
		tail->prev = tail->prev->next = new Node(val, tail->prev, tail);
	}
}

/*!
\brief Insert elelment
\details Insert an element in the iterated position in the list
\param[in] it Iterator to the position where the element has to be inserted
\param[in] to_insert Reference to the element which has to be inserted
\return A valid iterator to the same value that passed parameter was pointing to

The value is interted on the left of the iterator.
\code
//If we are given the following sequence with the iterator to the second element
//
//1 2 3 4 5 6
//  ^
//
//If we call the function insert(second_position_iterator, 0) our sequence will have the following look:
//
//1 0 2 3 4 5 6
//    ^
//
\endcode
The passed iterator will NOT be valid, though it will be returned as the return value.
*/
template <class value_type>
List_iterator<value_type> List<value_type>::insert(const List_iterator<value_type>& it, const value_type& to_insert) {
	if (it == begin()) {
		it->prev = new Node(to_insert, nullptr, head);
		head = head->prev;
	}
	else {
		Node* temp = it->prev;
		it->prev = new Node(to_insert, it->prev, it.node);
		temp->next = it->prev;
	}
	return it;
}

/*!
\brief Erase element
\details Erases element on the iterated position in the list
\param[in] it Iterator to the position where the element has to be erased
\return A valid iterator to the same position that passed parameter was pointing to

The value is erased, making the iterator invalid.
\code
//If we are given the following sequence with the iterator to the second element
//
//1 2 3 4 5 6
//  ^
//
//If we call the function erase(second_position_iterator) our sequence will have the following look:
//
//1 3 4 5 6
//  ^
//
//Where "^" is the iterator returned as a return value
//
\endcode
*/
template <class value_type>
List_iterator<value_type> List<value_type>::erase(List_iterator<value_type> it) {
	Node* temp = it.node;
	if (it == begin()) {
		head = head->next;
		it = begin();
	}
	else {
		it = List_iterator<value_type>(this, temp->next);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	delete temp;
	return it;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the list that has to be compared with the list passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template <class value_type>
bool List<value_type>::operator==(List<value_type>& to_compare) {
	Node* temp1 = head;
	Node* temp2 = to_compare;

	while (temp1 != tail || temp2 != to_compare->tail) {
		if (temp1 == temp2) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else {
			return false;
		}
	}
	return (temp1 == temp2) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the list that has to be compared with the list passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template <class value_type>
bool List<value_type>::operator!=(List<value_type>& to_compare) {
	return (*this == to_compare) ? false : true;
}

#endif // !LIST_H

