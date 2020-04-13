/*!
	\file
	\brief Header file containing class QueueBas
	\details This file contains template definition and implementation of the base class for the queue with priority.
*/

#ifndef QUEUEBASE_H
#define QUEUEBASE_H

#include <unordered_map>
#include <set>
#include <string>
#include <sstream>

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
//vector<int>, int
template <class container_type, class node_type>
class QueueBase {
protected:
	//container_type container;
	std::unordered_map<unsigned int, container_type> prior_container;
	std::set<unsigned int> priorities;
	void fixPriorities();
	//unsigned int maxPrior;
public:
	void push(node_type elem, unsigned int prior);
	bool empty();
	void pop();
	std::pair<node_type, unsigned int> front();
	std::pair<node_type, unsigned int> back();
	unsigned int size();
	std::string to_string();
};



/*!
\brief Add elements
\details Add elements following the rules of the queue with priority
\param[in] elem Element which has to be added
*/
template <class container_type, class node_type>
void QueueBase<container_type, node_type>::push(node_type elem, unsigned int prior) {
	//if (prior_container.count(prior)) {
		priorities.emplace(prior);
		prior_container[prior].push_back(elem);

	//}
	//else {
		//prior_container[prior] = container_type();
	//}
}

/*!
\brief Checks emptiness of the container
\details This method checks whether or not passed container is empty
\return True value if the container is empty and false value otherwise
*/
template <class container_type, class node_type>
bool QueueBase<container_type, node_type>::empty() {
	return (prior_container.empty()) ? true : false;
}

template <class container_type, class node_type>
void QueueBase<container_type, node_type>::fixPriorities() {
	if (!prior_container[*--priorities.end()].size()) {
		prior_container.erase(*--priorities.end());
		priorities.erase(--priorities.end());
	}
}

/*!
\brief Remove front element
\details This method removes the front value in the queue
*/
template <class container_type, class node_type>
void QueueBase<container_type, node_type>::pop() {
	if(priorities.size()){
		prior_container[*--priorities.end()].pop_front();
		fixPriorities();
	}
}



/*!
\brief Getter for the top element in the queue
\return Reference to the top element in the queue
*/
template <class container_type, class node_type>
std::pair<node_type, unsigned int> QueueBase<container_type, node_type>::front() {
	return std::pair<node_type, unsigned int>(prior_container[*--priorities.end()].front(), *--priorities.end());
}

/*!
\brief Getter for the last element in the queue
\return Reference to the last element in the queue
*/
template <class container_type, class node_type>
std::pair<node_type, unsigned int> QueueBase<container_type, node_type>::back() {
	return std::pair<node_type, unsigned int>(prior_container[*priorities.begin()].back(), *priorities.begin());
}

/*!
\brief Get the size of the queue
\details To get the amount of elements in the queue
\return Size of the queue
*/
template <class container_type, class node_type>
unsigned int QueueBase<container_type, node_type>::size() {
	unsigned int ans = 0;

	for (auto& x : prior_container) {
		ans += x.second.size();
	}

	return ans;
}

/*!
\brief Output stored information
\details Print stored fields of the queue to the console, using <iostream> library
*/
template <class container_type, class node_type>
std::string QueueBase<container_type, node_type>::to_string() {
	std::ostringstream ss;

	size_t set_size = priorities.size();

	for (auto i = priorities.rbegin(), end = priorities.rend(); i != end; ++i) {
		--set_size;

		for (unsigned int j = 0, size = prior_container[*i].size(); j < size; ++j) {
			ss << "("
				<< prior_container[*i][j]
				<< ", "
				<< *i
				<< ")";
		}

		if (set_size != 0) {
			ss << " ";
		}
	}

	return ss.str();
}

#endif // !QUEUEBASE_H