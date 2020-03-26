#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\ListPriorQueue.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\Pair.h"

TEST_CASE("Adding and deleting from ListPriorQueue (int, int)") {
	ListPriorQueue<Pair<int, int>> q;

	REQUIRE(q.empty() == true);

	//TODO: next test has to pass
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