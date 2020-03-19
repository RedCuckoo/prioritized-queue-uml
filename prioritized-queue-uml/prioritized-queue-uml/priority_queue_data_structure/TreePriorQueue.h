/*!
	\file
	\brief Header file containing class TreePriorQueue
	\details This file contains an implementation of the priority queue based on the binary search tree	
*/

#ifndef TREEPRIORQUEUE_H
#define TREEPRIORQUEUE_H

#include "QueueBase.h"
#include "data_structures/AVLTree.h"

/*!
	\brief Priority queue based on the binary search tree
	\details In order of this function to work properly, you should pass Pair<value, priority> as a value_type.
	The class itself is inheritted from the base of the priority queue and uses custom written self balanced AVL tree.
*/
template <class value_type>
class TreePriorQueue : public QueueBase<AVLTree<value_type>, value_type> {
public:
	void push(value_type elem);
	void pop();
	value_type& front();
	value_type& back();
	void out();
};

/*!
\brief Method to add element to the queue
\details Overridden method of the QueueBase class, because the given there function adds elements to the list.
That way we didn't have to implement function insert, as rules of parent class states.
\param [in] elem Element to be added
*/
template <class value_type>
void TreePriorQueue<value_type>::push(value_type elem) {
	QueueBase<AVLTree<value_type>, value_type>::container.push(elem);
}

/*!
\brief Method to remove an element to the queue
\details Overridden method of the QueueBase class, because the order of the elements is different.
*/
template <class value_type>
void TreePriorQueue<value_type>::pop() {
	QueueBase<AVLTree<value_type>, value_type>::container.erase(QueueBase<AVLTree<value_type>, value_type>::container.begin());
}

/*!
\brief Get first element
\details Overridden method of the QueueBase class, to show the first element of the queue.
\return Reference to the element on the top.
*/
template<class value_type>
value_type& TreePriorQueue<value_type>::front(){
	return *QueueBase<AVLTree<value_type>, value_type>::container.begin();
}

/*!
\brief Get last element
\details Overridden method of the QueueBase class, to show the last element of the queue.
\return Reference to the element on the bottom.
*/
template<class value_type>
value_type& TreePriorQueue<value_type>::back(){
	return *--QueueBase<AVLTree<value_type>, value_type>::container.end();
}

/*!
\brief Output stored information
\details Print stored fields of the queue to the console, using <iostream> library
*/
template<class value_type>
void TreePriorQueue<value_type>::out() {
	for (auto i = QueueBase<AVLTree<value_type>, value_type>::container.begin(); i != QueueBase<AVLTree<value_type>, value_type>::container.end(); ++i) {
		(*i).out();
	}
}

#endif // !TREEPRIORQUEUE_H
