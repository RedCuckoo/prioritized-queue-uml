/*!
	\file
	\brief Header file containing class ListPriorQueue
	\details This file contains an implementation of the priority queue based on the double linked list
*/

#ifndef LISTPRIORQUEUE_H
#define LISTPRIORQUEUE_H

#include "data_structures/List.h"
#include "QueueBase.h"

/*!
	\brief Priority queue based on the double linked list
	\details In order of this function to work properly, you should pass Pair<value, priority> as a value_type.
	The class itself is inheritted from the base of the priority queue and uses custom written self balanced AVL tree.
*/
template <class value_type>
class ListPriorQueue : public QueueBase<List<value_type>, value_type> {

};

#endif // !LISTPRIORQUEUE_H
