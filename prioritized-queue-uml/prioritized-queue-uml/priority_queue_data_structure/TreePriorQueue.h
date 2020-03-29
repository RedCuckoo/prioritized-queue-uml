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
};


#endif // !TREEPRIORQUEUE_H
