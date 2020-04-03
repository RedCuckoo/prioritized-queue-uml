#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\AVLTree.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\List.h"
#include <string>

TEMPLATE_PRODUCT_TEST_CASE ("General test (int) for custom data structures","",
	(AVLTree, List), (int)) {
	TestType t;
	
	REQUIRE(t.size() == 0);

	SECTION("Adding and deleting one item") {
		t.push_back(5);

		REQUIRE_FALSE(t.size() == 0);
		REQUIRE(t.front() == 5);
		REQUIRE(t.back() == 5);

		t.pop_front();

		REQUIRE(t.size() == 0);
	}

	SECTION("Adding and deleting multiple items") {
		t.push_back(3);
		t.push_back(9);
		t.push_back(10);
		t.push_back(2);
		t.push_back(8);

		REQUIRE(t.front() == 3);
		REQUIRE(t.back() == 8);

		t.pop_front();

		REQUIRE(t.front() == 9);

		t.pop_front();
		REQUIRE(t.front() == 10);

		REQUIRE(t.size() == 3);

		t.pop_front();
		t.pop_front();
		t.pop_front();

		REQUIRE(t.size() == 0);
	}

	SECTION("Deleting empty tree") {
		t.pop_front();

		REQUIRE(t.size() == 0);
	}

	SECTION("Adding to tree, that was recently emptied") {
		t.push_back(2);
		t.pop_front();
		t.push_back(1);

		REQUIRE(t.front() == 1);
		REQUIRE(t.size() == 1);
	}
}

TEMPLATE_PRODUCT_TEST_CASE("General test (std::string) for custom data structures", "",
	(AVLTree, List), (std::string)) {
	TestType t;

	SECTION("Adding and deleting one item") {
		t.push_back("abc");

		REQUIRE_FALSE(t.size() == 0);
		REQUIRE(t.front() == "abc");

		t.pop_front();

		REQUIRE(t.size() == 0);
	}

	SECTION("Adding and deleting multiple items") {
		t.push_back("a");
		t.push_back("aa");
		t.push_back("aaa");
		t.push_back("aaaa");
		t.push_back("aaaaa");

		REQUIRE(t.front() == "a");
		REQUIRE(t.back() == "aaaaa");

		t.pop_front();

		REQUIRE(t.front() == "aa");

		t.pop_front();
		REQUIRE(t.back() == "aaaaa");

		REQUIRE(t.size() == 3);

		t.pop_front();
		t.pop_front();
		t.pop_front();

		REQUIRE(t.size() == 0);
	}
}