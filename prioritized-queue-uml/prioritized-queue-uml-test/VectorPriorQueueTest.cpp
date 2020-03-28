#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\VectorPriorQueue.h"

TEST_CASE("Adding and deleting from VectorPriorQueue (int, int)") {
	//TODO: write generalized test for TreePriorQueue, ListPriorQueue and VectorPriorQueue
	VectorPriorQueue<int> q;

	REQUIRE(q.empty() == true);
	//REQUIRE_NOTHROW(q.pop());

	q.push(3, 2);
	q.push(10, 1);
	q.push(9, 5);
	q.push(7, 3);

	REQUIRE(q.front() == std::make_pair(9, (unsigned int) 5));
	REQUIRE(q.back() == std::make_pair(10, (unsigned int) 1));

	q.pop();

	REQUIRE(q.to_string() == "(7, 3) (3, 2) (10, 1)");

	REQUIRE(q.size() == 3);
	REQUIRE(q.empty() == false);
	REQUIRE(q.front() == std::make_pair(7, (unsigned int) 3));

	q.pop();
	q.pop();

	REQUIRE(q.to_string() == "(10, 1)");

	q.pop();

	REQUIRE(q.size() == 0);
	REQUIRE(q.empty() == true);
}