/*!
	\file
	\brief Header file containing class AVLTree_iterator

	This file contains template definition and implementation of an iterator of such data structure as a binary search AVL tree
*/

#ifndef AVLTREE_ITERATOR_H
#define AVLTREE_ITERATOR_H

#include "AVLTree.h"

/*!
\brief iterator
\details A custom written class which implements iterators for the class AVLTree.
It has the same properties as STL library std::random_access_iterator.
*/
template <class value_type>
class AVLTree_iterator {
	/*!
	\brief Friended class AVLTree
	\details Gives access to private fields of class AVLTree
	*/
	template <class U>
	friend class AVLTree;

	//allows to access elements with complexity of O(1)
	unsigned int coord;
	AVLTree<value_type>* tree;
	typename AVLTree<value_type>::Node* node;
	std::vector<typename AVLTree<value_type>::Node*> listedTree;

	AVLTree_iterator* setLast();
	AVLTree_iterator* setFirst();
	void treeToArray();
	void getCoord();
	void updateIterator();
public:
	AVLTree_iterator(AVLTree<value_type>* tree_ptr, typename AVLTree<value_type>::Node* node_ptr = nullptr);
	AVLTree_iterator(const AVLTree_iterator& to_copy);

	AVLTree_iterator& operator++();
	AVLTree_iterator operator++(int);
	AVLTree_iterator& operator--();
	AVLTree_iterator operator--(int);
	AVLTree_iterator& operator+(int val);
	AVLTree_iterator& operator-(int val);
	bool operator== (const AVLTree_iterator<value_type>& to_compare) const;
	bool operator!= (const AVLTree_iterator<value_type>& to_compare) const;
	bool operator> (const AVLTree_iterator<value_type>& to_compare);
	bool operator< (const AVLTree_iterator<value_type>& to_compare);
	value_type& operator*()const;
};

/*!
\brief Convert iterator to the end()
\details This method converts current iterator to the iterator on the end of the list, in this case on the nullptr.
\return Returns a pointer to current object but with changed fields
*/
template <class value_type>
AVLTree_iterator<value_type>* AVLTree_iterator<value_type>::setLast() {
	node = listedTree[0];
	coord = 0;
	return this;
}

/*!
\brief Convert iterator to the begin()
\details This method converts current iterator to the iterator on the beginning of the list.
\return Returns a pointer to current object but with changed fields
*/
template <class value_type>
AVLTree_iterator<value_type>* AVLTree_iterator<value_type>::setFirst() {
	coord = listedTree.size() - 1;
	node = listedTree[coord];
	return this;
}

/*!
\brief Fill listedTree field
\details Part of constructor which converts tree to the list, so you can navigate easily, helps to implement overloading of the operators.
*/
template <class value_type>
void AVLTree_iterator<value_type>::treeToArray() {
	std::stack<typename AVLTree<value_type>::Node*> temp_stack;
	typename AVLTree<value_type>::Node* temp_ptr = tree->head;
	listedTree.push_back(nullptr);
	while (!temp_stack.empty() || temp_ptr) {
		if (temp_ptr) {
			if (temp_ptr->height == 1) {
				listedTree.push_back(temp_ptr);
				temp_ptr = nullptr;
			}
			else {
				temp_stack.push(temp_ptr);
				temp_ptr = temp_ptr->left;
			}
		}
		else {
			temp_ptr = temp_stack.top();
			temp_stack.pop();
			listedTree.push_back(temp_ptr);
			temp_ptr = temp_ptr->right;
		}
	}
}

/*!
\brief Fill coord field
\details Part of constructor which gets the coordinate of the node in the tree converted to the list, helps to implement overloading of the operators
*/
template <class value_type>
void AVLTree_iterator<value_type>::getCoord() {
	for (unsigned int i = 0; i < listedTree.size(); i++) {
		if (node == listedTree[i]) {
			coord = i;
			break;
		}
	}
}

/*!
\brief Update information that iterator stores
\details The method call two functions, one to refresh tree written as the list, another to get the coordinate of the stored node in the updated list.
*/
template <class value_type>
void AVLTree_iterator<value_type>::updateIterator() {
	treeToArray();
	getCoord();
}

/*!
\brief Constructor
\details A constructor that creates iterator from the provided parameters
\param[in] tree_ptr Pointer to the list, where current iterator belongs to
\param[in] node_ptr Pointer to the node, where current iterator has to point. Assigned as nullptr automatically
*/
template <class value_type>
AVLTree_iterator<value_type>::AVLTree_iterator(AVLTree<value_type>* tree_ptr, typename AVLTree<value_type>::Node* node_ptr) {
	tree = tree_ptr;
	node = node_ptr;
	updateIterator();
}

/*!
\brief Copy constructor
\details Overloaded copy constructor to make sure that it works as supposed to
*/
template <class value_type>
AVLTree_iterator<value_type>::AVLTree_iterator(const AVLTree_iterator& to_copy) {
	tree = to_copy.tree;
	node = to_copy.node;
	coord = to_copy.coord;
	listedTree = to_copy.listedTree;
}

/*!
\brief Overloaded left increment operator
\return A reference to the iterator, pointing to the next element
*/
template <class value_type>
AVLTree_iterator<value_type>& AVLTree_iterator<value_type>::operator++() {
	updateIterator();
	node = listedTree[--coord];
	return *this;
}

/*!
\brief Overloaded right increment operator
\return An iterator, pointing to the next element
*/
template <class value_type>
AVLTree_iterator<value_type> AVLTree_iterator<value_type>::operator++(int) {
	updateIterator();
	AVLTree_iterator result = *this;
	node = listedTree[--coord];
	return result;
}

/*!
\brief Overloaded left decrement operator
\return A reference to the iterator, pointing to the previous element
*/
template <class value_type>
AVLTree_iterator<value_type>& AVLTree_iterator<value_type>::operator--() {
	updateIterator();
	node = listedTree[++coord];
	return *this;
}

/*!
\brief Overloaded right decrement operator
\return A reference to the iterator, pointing to the previous
*/
template <class value_type>
AVLTree_iterator<value_type> AVLTree_iterator<value_type>::operator--(int) {
	updateIterator();
	AVLTree_iterator result = *this;
	node = listedTree[++coord];
	return result;
}

/*!
\brief Overloaded summing operator, shifts iterator to the left or right relatively of the parameter
\param val If this parameter is >0 then it iterator shifts to the right, else - to the left
\return A reference to the iterator, pointing to the next or previous element
*/
template <class value_type>
AVLTree_iterator<value_type>& AVLTree_iterator<value_type>::operator+(int val) {
	updateIterator();
	if (val > 0) {
		coord -= val;
		node = listedTree[coord];
	}
	else if (val == 0) {

	}
	else {
		coord += val;
		node = listedTree[coord];
	}
	return *this;
}

/*!
\brief Overloaded suntracting operator, shifts iterator to the left or right relatively of the parameter
\param val If this parameter is >0 then it iterator shifts to the left, else - to the right
\return A reference to the iterator, pointing to the next or previous element
*/
template <class value_type>
AVLTree_iterator<value_type>& AVLTree_iterator<value_type>::operator-(int val) {
	updateIterator();
	if (val > 0) {
		coord += val;
		node = listedTree[coord];
	}
	else if (val == 0) {

	}
	else {
		coord -= val;
		node = listedTree[coord];
	}
	return *this;
}

/*!
\brief Overloaded equality operator
\param to_compare Const reference to the AVLTree_iterator that has to be compared with the AVLTree_Iterator passed as an lvalue
\return True value if they are equal and false value otherwise
*/
template <class value_type>
bool AVLTree_iterator<value_type>::operator== (const AVLTree_iterator<value_type>& to_compare) const {
	return (coord == to_compare.coord) ? true : false;
}

/*!
\brief Overloaded inequality operator
\param to_compare Const reference to the AVLTree_iterator that has to be compared with the AVLTree_Iterator passed as an lvalue
\return True value if they are unequal and false value otherwise
*/
template <class value_type>
bool AVLTree_iterator<value_type>::operator!= (const AVLTree_iterator<value_type>& to_compare) const{
	return (coord != to_compare.coord) ? true : false;
}

/*!
\brief Overloaded bigger than operator
\param to_compare Const reference to the AVLTree_iterator that has to be compared with the AVLTree_Iterator passed as an lvalue
\return True value if current iterator's value is bigger than passed and false value otherwise
*/
template <class value_type>
bool AVLTree_iterator<value_type>::operator> (const AVLTree_iterator<value_type>& to_compare) {
	return (coord > to_compare.coord) ? true : false;
}

/*!
\brief Overloaded smaller than operator
\param to_compare Const reference to the AVLTree_iterator that has to be compared with the AVLTree_Iterator passed as an lvalue
\return True value if current iterator's value is smaller than passed and false value otherwise
*/
template <class value_type>
bool AVLTree_iterator<value_type>::operator< (const AVLTree_iterator<value_type>& to_compare) {
	return (coord < to_compare.coord) ? true : false;
}

/*!
\brief Overloaded dereference operator
\return A value (of the value_type) that is stored in the node of the list that current iterator is pointing to
*/
template <class value_type>
value_type& AVLTree_iterator<value_type>::operator*()const {
	return node->value;
}

#endif // !AVLTREE_ITERATOR_H
