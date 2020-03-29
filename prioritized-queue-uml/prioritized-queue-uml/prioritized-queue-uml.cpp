/*!
	\file
	\brief Main C++ file

	This file contains main function
*/

#include "priority_queue_data_structure/data_structures/AVLTree.h"
#include "priority_queue_data_structure/data_structures/List.h"
#include <iostream>
#include "priority_queue_data_structure/VectorPriorQueue.h"
#include "priority_queue_data_structure/TreePriorQueue.h"
#include "priority_queue_data_structure/ListPriorQueue.h"

int main(){
	//List<int> a;
	//a.push_back(3);
	//a.push_back(0);
	//a.push_back(2);
	//a.push_back(8);
	//a.push_back(9);
	//a.push_back(1);
	//a.push_back(11);
	//a.push_back(7);
	//
	////a.out();
	//std::cout << '\n';

 //	a.pop_front();
	//a.pop_front();
	//std::cout << a[0] << " " << a[6];



	ListPriorQueue<int> a;
	a.push(3, 2);
	a.push(6, 2);
	a.push(2, 8);
	a.push(6, 1);
	a.push(6, 9);
	std::cout << a.to_string() << "\n";
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.push(3, 6);
	std::cout << a.to_string();
	a.pop();
	a.pop();

	std::cout<<a.to_string();
} 