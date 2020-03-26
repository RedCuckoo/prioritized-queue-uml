#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\VectorPriorQueue.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\Pair.h"

TEST_CASE("Adding and deleting from VectorPriorQueue (int, int)") {
	//TODO: write generalized test for TreePriorQueue, ListPriorQueue and VectorPriorQueue
	VectorPriorQueue<Pair<int, int>> q;

	REQUIRE(q.empty() == true);
	//REQUIRE_NOTHROW(q.pop());

	q.push(Pair<int, int>(3, 2));
	q.push(Pair<int, int>(10, 1));
	q.push(Pair<int, int>(9, 5));
	q.push(Pair<int, int>(7, 3));

	REQUIRE(q.front() == Pair<int, int>(9, 5));
	REQUIRE(q.back() == Pair<int, int>(10, 1));

	q.pop();

	REQUIRE(q.size() == 3);
	REQUIRE(q.empty() == false);
	REQUIRE(q.front() == Pair<int, int>(7, 3));

	q.pop();
	q.pop();
	q.pop();

	REQUIRE(q.size() == 0);
	REQUIRE(q.empty() == true);
}