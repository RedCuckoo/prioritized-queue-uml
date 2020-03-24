#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\Pair.h"

TEST_CASE("Adding elements to empty object (int, int)") {
	Pair<int, int> p;
	p.setVal(10);
	p.setPrior(1);

	REQUIRE(p.getVal() == 10);
	REQUIRE(p.getPrior() == 1);
}

TEST_CASE("Changing elements of constructed object (int, int)") {
	Pair<int, int> p(4, 10);

	REQUIRE(p.getVal() == 4);
	REQUIRE(p.getPrior() == 10);

	p.setVal(20);
	p.setPrior(2);

	REQUIRE(p.getVal() == 20);
	REQUIRE(p.getPrior() == 2);
}

TEST_CASE("Testing overloaded operators (int, int)") {
	Pair<int, int> p(2, 3);
	Pair<int, int> r(4, 2);

	REQUIRE((p < r) == false);
	REQUIRE((r < p) == true);
	REQUIRE((p > r) == true);
	REQUIRE((r > p) == false);

	p.setPrior(2);
	REQUIRE((p <= r) == true);
	REQUIRE((r <= p) == true);
	REQUIRE((p >= r) == true);
	REQUIRE((r >= p) == true);

	REQUIRE_FALSE(p == r);
	REQUIRE_FALSE(r == p);
	REQUIRE(p != r);
	REQUIRE(r != p);

	p.setVal(4);

	REQUIRE(p == r);
	REQUIRE(r == p);
	REQUIRE_FALSE(p != r);
	REQUIRE_FALSE(r != p);
}