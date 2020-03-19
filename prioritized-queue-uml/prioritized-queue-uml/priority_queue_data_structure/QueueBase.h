/*!
	\file
	\brief Header file containing class QueueBas
	\details This file contains template definition and implementation of the base class for the queue with priority.
*/

#ifndef QUEUEBASE_H
#define QUEUEBASE_H

/*!
\brief Base class of the private methods for the queue
\details In order to use it, you have to pass a type of container to container_type, which has to have implemented the following functions:
\code
	void push_back();
	bool empty();
	iterator begin();
	iterator end();
	iterator insert(iterator, container_node_value_type);
	iterator erase();
	unsigned int size();
\endcode
By iterator meant container_type_iterator, the iterator for container_type.
Container_node have to support function out(), not streamed.
\code
	void out();
\endcode
As well, for the iterators next functions have to be implemented:
\code
	iterator operator--();
	container_node_value_type operator*();
\endcode
If something is missing in your passed type, override functions changing missed methods
*/
template <class container_type, class container_node_value_type>
class QueueBase {
protected:
	container_type container;
public:
	void push(container_node_value_type elem);
	bool empty();
	void pop();
	container_node_value_type& front();
	container_node_value_type& back();
	unsigned int size();
	void out();
};

/*!
\brief Add elements
\details Add elements following the rules of the queue with priority
\param[in] elem Element which has to be added
*/
template <class container_type, class container_node_value_type>
void QueueBase<container_type, container_node_value_type>::push(container_node_value_type elem) {
	if (container.empty()) {
		container.push_back(elem);
	}
	else {
		for (auto it = container.begin(); it != container.end(); ++it) {
			if (*it >= elem) {
				container.insert(it, elem);
				return;
			}
		}
		container.push_back(elem);
	}
}

/*!
\brief Checks emptiness of the container
\details This method checks whether or not passed container is empty
\return True value if the container is empty and false value otherwise
*/
template <class container_type, class container_node_value_type>
bool QueueBase<container_type, container_node_value_type>::empty() {
	return (container.empty()) ? true : false;
}

/*!
\brief Remove front element
\details This method removes the front value in the queue
*/
template <class container_type, class container_node_value_type>
void QueueBase<container_type, container_node_value_type>::pop() {
	container.erase(--container.end());
}

/*!
\brief Getter for the top element in the queue
\return Reference to the top element in the queue
*/
template <class container_type, class container_node_value_type>
container_node_value_type& QueueBase<container_type, container_node_value_type>::front() {
	return *--container.end();
}

/*!
\brief Getter for the last element in the queue
\return Reference to the last element in the queue
*/
template <class container_type, class container_node_value_type>
container_node_value_type& QueueBase<container_type, container_node_value_type>::back() {
	return *(container.begin());
}

/*!
\brief Get the size of the queue
\details To get the amount of elements in the queue
\return Size of the queue
*/
template <class container_type, class container_node_value_type>
unsigned int QueueBase<container_type, container_node_value_type>::size() {
	return container.size();
}

/*!
\brief Output stored information
\details Print stored fields of the queue to the console, using <iostream> library
*/
template <class container_type, class container_node_value_type>
void QueueBase<container_type, container_node_value_type>::out() {
	for (auto i = container.end(); i != container.begin(); --i) {
		if (i == container.end())
			continue;
		(*i).out();
	}

	if(container.size() >= 1)
		(*container.begin()).out();
}

#endif // !QUEUEBASE_H