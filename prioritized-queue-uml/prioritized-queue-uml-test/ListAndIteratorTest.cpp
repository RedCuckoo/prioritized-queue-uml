#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\List.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\List_iterator.h"

TEST_CASE("Adding/deleting one/multiple item/s to list(int)") {
	List<int> l;

	REQUIRE(l.size() == 0);
	REQUIRE(l.empty());
	REQUIRE(l.begin() == l.end());

	SECTION("Adding and deleting one item") {
		l.push_back(5);

		REQUIRE_FALSE(l.empty());
		REQUIRE(*l.begin() == 5);

		l.erase(l.begin());

		REQUIRE(l.empty());
	}

	SECTION("Adding and deleting multiple items") {
		//TODO: LIST HAS DIFFERENT ORDER THAN AVLTREE

		l.push_back(3);
		l.push_back(9);
		l.push_back(10);
		l.push_back(2);
		l.push_back(8);

		REQUIRE(*l.begin() == 3);
		REQUIRE(*--l.end() == 8);

		l.erase(l.begin());

		REQUIRE(*l.begin() == 9);

		l.erase(--l.end());
		REQUIRE(*--l.end() == 2);

		REQUIRE(l.size() == 3);
		REQUIRE_FALSE(l.empty());

		l.erase(l.begin());
		l.erase(l.begin());
		l.erase(l.begin());

		REQUIRE(l.size() == 0);
		REQUIRE(l.empty());
	}

	SECTION("Deleting empty tree") {
		l.erase(l.begin());

		//size and empty need to be changed
		REQUIRE(l.size() == 0);
		REQUIRE(l.empty());
	}

	SECTION("Adding to tree, that was recently emptied") {
		l.push_back(2);
		l.erase(l.begin());
		l.push_back(1);

		REQUIRE(*l.begin() == 1);
		REQUIRE(l.size() == 1);
	}
}