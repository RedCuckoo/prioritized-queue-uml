/*!
	\file
	\brief Header file containing class List

	This file contains template definition and implementation of such data structure as a double linked list
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>

/*!
	\brief Double linked list
	\details A custom implementation of STL library std::list with custom random access iterator
*/
template <class node_type>
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
		node_type value;
		Node* next, * prev;

		/*!
		\brief Constructor
		\details Constructor which creates a node from the provided parameters.
		\param[in] val The value that node will store
		\param[in] pr Pointer to the previous node (for the beginning of the list, nullptr is passed)
		\param[in] ne Pointer to the next node (for the end of the list, pointer to an empty node is passed)
		*/
		Node(node_type val, Node* pr, Node* ne) : value(val), prev(pr), next(ne) {		};
	};

	Node* head, * tail;
	unsigned int list_size;
public:
	List();
	unsigned int size();
	void push_back(node_type val);
	node_type& front();
	node_type& back();
	void pop_front();
	node_type& operator[](unsigned int i);
};

template <class node_type>
node_type& List<node_type>::operator[](unsigned int i) {
	Node* temp = head;
	if (list_size > i) {
		for (unsigned int j = 0; j != i; ++j) {
			temp = temp->next;
		}

		return temp->value;
	}

	return head->value;
}

template <class node_type>
void List<node_type>::pop_front() {
	Node* temp = head;

	if (head) {
		if (head->next == tail) {
			head = tail;
			tail = nullptr;
		}
		else {
			head = head->next;
		}
	}

	if (head)
		head->prev = nullptr;

	--list_size;
	delete temp;
}

template <class node_type>
node_type& List<node_type>::front() {
	return head->value;
}

template <class node_type>
node_type& List<node_type>::back() {
	return tail->value;
}

/*!
\brief Constructor
\details Default construct which creates a List object with no elements in it
*/
template <class node_type>
List<node_type>::List() {
	head = nullptr;
	tail = nullptr;
	list_size = 0;
}

/*!
\brief Get the size of the list
\details To get the amount of elements of the list
\return Size of the list
*/
template <class node_type>
unsigned int List<node_type>::size() {
	return list_size;
}

/*!
\brief Add elements
\details Add elements to the end of the list
\param[in] val Value which has to be added to the list
*/
template <class node_type>
void List<node_type>::push_back(node_type val) {
	if (!head) {
		head = new Node(val, nullptr, tail);
	}
	else {
		if (!tail) {
			tail = new Node(val, head, nullptr);
			head->next = tail;
		}
		else {
			tail->next = new Node(val, tail, nullptr);
			tail = tail->next;
			//tail->prev = tail->prev->next = new Node(val, tail->prev, tail);
		}
	}
	++list_size;
}

#endif // !LIST_H

