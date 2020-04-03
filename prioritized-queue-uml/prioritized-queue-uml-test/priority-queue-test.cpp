#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\VectorPriorQueue.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\ListPriorQueue.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\TreePriorQueue.h"

TEMPLATE_PRODUCT_TEST_CASE ("General test (int) for priority queueu on custom data structures", "",
	(VectorPriorQueue, ListPriorQueue, TreePriorQueue),
	int) {
	//TODO: write generalized test for TreePriorQueue, ListPriorQueue and VectorPriorQueue
	TestType q;

	REQUIRE(q.empty() == true);

	q.push(3, 2);
	q.push(10, 1);
	q.push(9, 5);
	q.push(7, 3);

	REQUIRE(q.front().first == 9);
	REQUIRE(q.front().second == 5);
	REQUIRE(q.back().first == 10);
	REQUIRE(q.back().second == 1);

	q.pop();

	REQUIRE(q.to_string() == "(7, 3) (3, 2) (10, 1)");

	REQUIRE(q.size() == 3);
	REQUIRE(q.empty() == false);
	REQUIRE(q.front().first == 7);
	REQUIRE(q.front().second == 3);

	q.pop();
	q.pop();

	REQUIRE(q.to_string() == "(10, 1)");

	q.pop();

	REQUIRE(q.size() == 0);
	REQUIRE(q.empty() == true);

	q.push(6, 4);
	REQUIRE(q.front().first == q.back().first);
	REQUIRE(q.front().second == 4);
	REQUIRE(q.size() == 1);
	REQUIRE(q.empty() == false);

	q.pop();
	REQUIRE(q.size() == 0);
}