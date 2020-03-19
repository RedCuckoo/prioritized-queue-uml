/*!
	\file
	\brief C++ file containing definitions of class Demonstration
*/

#include "Demonstration.h"
#include "..//figures/Circle.h"
#include "..//figures/Line.h"
#include "..//figures/base figure/Figure.h"
#include "..//priority_queue_data_structure/data_structures/Pair.h"
#include "..//priority_queue_data_structure/ListPriorQueue.h"
#include "..//priority_queue_data_structure/VectorPriorQueue.h"
#include "..//priority_queue_data_structure/TreePriorQueue.h"
#include <iostream>
#include <string>

/*!
\brief Get a pair with random value and priority
\details A custom implemented randomizer for Pair
\param [in] topVal The highest possible element for the value
\param [in] topPrior The highest possible element for the priority
\param [in] negativeValue True if you would like to include negative values in the randomizer, false value otherwise
\return The randomized Pair<int>
*/
Pair<int> Demonstration::randIntPair(unsigned int topVal, unsigned int topPrior, bool negativeValue) {
	return Pair<int>(rand() % topVal - negativeValue * topVal / 2, rand() % topPrior + 1);
}

/*!
\brief To get a random integer
\details custom implemented randomizer for int
\param [in] topVal The highest possible element for the value
\param [in] negativeValue True if you would like to include negative values in the randomizer, false value otherwise
*/
int Demonstration::randInt(unsigned int topVal, bool negativeValue) {
	return (rand() % topVal - negativeValue * topVal / 2);
}

/*!
\brief To get a random line of characters
\details custom implemented randomizer for std::string
\param [in] topSize A size of the longest possible string
\param [in] topPrior The highest possible element for the priority
\return The randomized Pair<std::string>
*/
Pair<std::string> Demonstration::randString(unsigned int topSize, unsigned int topPrior) {
	std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string ans;
	unsigned int size = rand() % topSize;

	for (unsigned int i = 0; i < size; i++) {
		ans.push_back(characters[randInt(characters.size())]);
	}

	return Pair<std::string>(ans, rand() % topPrior + 1);
}

/*!
\brief Pause demonstration
\details Waits for the Enter or alternative to continue
*/
void Demonstration::wait() {
	std::cin.ignore();
	//std::cin.clear();
	std::cin.get();
}

/*!
\brief Get a number ignoring wrong input
*/
template <typename value_type>
void Demonstration::get_num(value_type& data)
{
	while (!(std::cin >> data))
	{
		std::cin.clear(); //clear errors (like the failbit flag) 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //throw away the rest of the line 
		std::cout << "\n\nWrong input, please enter your choice again: ";
	}
}

/*!
\brief Main function for demonstration
\details Runs a function for demonstrating the laboratory work to the user
*/
void Demonstration::demo() {
	std::cout << "Welcome to the demonstration of the Lab #1\n\n";
	std::cout << "If demonstration stopped, press Enter to continue (unless something else specified).\n";

	unsigned int ans1, ans2;
	std::cout << "Choose which data type would you like to use:\n";
	std::cout << "1 - integer value\n";
	std::cout << "2 - string value\n";
	std::cout << "3 - Line\n";
	std::cout << "4 - Circle\n";
	std::cout << "5 - exit\n";
	std::cout << "Enter your choice, please: ";
	get_num(ans1);
	std::cout << "\nChoose which implementation of the priority queue would you like to use:\n";
	std::cout << "1 - double linked list\n";
	std::cout << "2 - dynamic array\n";
	std::cout << "3 - self-balanced binary tree (AVL)\n";
	std::cout << "5 - exit\n";
	std::cout << "Enter your choice, please: ";
	get_num(ans2);

	if (ans1 == 1 && ans2 == 1)
		show_int<ListPriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 1)
		show_string<ListPriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 1)
		show_line<ListPriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 1)
		show_circle<ListPriorQueue<Pair<Circle>>>();
	else if (ans1 == 1 && ans2 == 2)
		show_int<VectorPriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 2)
		show_string<VectorPriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 2)
		show_line<VectorPriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 2)
		show_circle<VectorPriorQueue<Pair<Circle>>>();
	else if (ans1 == 1 && ans2 == 3)
		show_int<TreePriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 3)
		show_string<TreePriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 3)
		show_line<TreePriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 3)
		show_circle<TreePriorQueue<Pair<Circle>>>();
	else if (ans1 == 5 || ans2 == 5)
		return;
	else {
		std::cin.clear();
	}
}

/*!
\brief Main function for interaction
\details Runs a function for interactive mode of the laboratory work for the user
*/
void Demonstration::inter() {
	std::cout << "Welcome to the interactive mode of the Lab #1\n\n";
	std::cout << "If mode stopped, press Enter to continue (unless something else specified).\n";

	unsigned int ans1, ans2;
	std::cout << "Choose which data type would you like to use:\n";
	std::cout << "1 - integer value\n";
	std::cout << "2 - string value\n";
	std::cout << "3 - Line\n";
	std::cout << "4 - Circle\n";
	std::cout << "5 - exit\n";
	std::cout << "Enter your choice, please: ";
	get_num(ans1);
	std::cout << "\nChoose which implementation of the priority queue would you like to use:\n";
	std::cout << "1 - double linked list\n";
	std::cout << "2 - dynamic array\n";
	std::cout << "3 - self-balanced binary tree (AVL)\n";
	std::cout << "5 - exit\n";
	std::cout << "Enter your choice, please: ";
	get_num(ans2);

	if (ans1 == 1 && ans2 == 1)
		do_int<ListPriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 1)
		do_string<ListPriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 1)
		do_line<ListPriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 1)
		do_circle<ListPriorQueue<Pair<Circle>>>();
	else if (ans1 == 1 && ans2 == 2)
		do_int<VectorPriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 2)
		do_string<VectorPriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 2)
		do_line<VectorPriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 2)
		do_circle<VectorPriorQueue<Pair<Circle>>>();
	else if (ans1 == 1 && ans2 == 3)
		do_int<TreePriorQueue<Pair<int>>>();
	else if (ans1 == 2 && ans2 == 3)
		do_string<TreePriorQueue<Pair<std::string>>>();
	else if (ans1 == 3 && ans2 == 3)
		do_line<TreePriorQueue<Pair<Line>>>();
	else if (ans1 == 4 && ans2 == 3)
		do_circle<TreePriorQueue<Pair<Circle>>>();
	else if (ans1 == 5 || ans2 == 5)
		return;
	else {
		std::cin.clear();
	}
}