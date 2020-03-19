/*!
	\file
	\brief Main C++ file

	This file contains main function
*/

#include "demo/Demonstration.h"

int main(){
	Demonstration k;
	while (true) {
		size_t ans = 0;
		while (ans != 1 && ans != 2 && ans != 3) {
			std::cout << "\nPlease, choose mode:\n";
			std::cout << "1 - demonstration\n";
			std::cout << "2 - interaction\n";
			std::cout << "3 - exit\n";
			std::cout << "=> ";
			std::cin >> ans;
			std::cout << std::endl;
		}

		std::cout << std::endl;

		if (ans == 1)
			k.demo();
		else if (ans == 2)
			k.inter();
		else
			return 0;
	}

} 