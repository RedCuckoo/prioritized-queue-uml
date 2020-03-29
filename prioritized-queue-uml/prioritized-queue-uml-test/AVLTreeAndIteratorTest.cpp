#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\AVLTree.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\AVLTree_iterator.h"
#include <string>

TEST_CASE("Adding/deleting one/multiple item/s (int)") {
	AVLTree<int> t;
	
	REQUIRE(t.size() == 0);
	REQUIRE(t.empty());
	REQUIRE(t.begin() == t.end());

	SECTION("Adding and deleting one item") {
		t.push(5);

		REQUIRE_FALSE(t.empty());
		REQUIRE(*t.begin() == 5);

		t.erase(t.begin());

		REQUIRE(t.empty());
	}

	SECTION("Adding and deleting multiple items") {
		t.push(3);
		t.push(9);
		t.push(10);
		t.push(2);
		t.push(8);

		REQUIRE(*t.begin() == 10);
		REQUIRE(*--t.end() == 2);

		t.erase(t.begin());

		REQUIRE(*t.begin() == 9);

		t.erase(--t.end());
		REQUIRE(*--t.end() == 3);

		REQUIRE(t.size() == 3);
		REQUIRE_FALSE(t.empty());

		t.erase(t.begin());
		t.erase(t.begin());
		t.erase(t.begin());

		REQUIRE(t.size() == 0);
		REQUIRE(t.empty());
	}

	SECTION("Deleting empty tree") {
		t.erase(t.begin());

		REQUIRE(t.size() == 0);
		REQUIRE(t.empty());
	}

	SECTION("Adding to tree, that was recently emptied") {
		t.push(2);
		t.erase(t.begin());
		t.push(1);

		REQUIRE(*t.begin() == 1);
		REQUIRE(t.size() == 1);
	}
}

TEST_CASE("Testing iterator overloaded operators (int)") {
	AVLTree<int> t;

	//10 9 4 3 1
	t.push(3);
	t.push(9);
	t.push(1);
	t.push(10);
	t.push(4);

	REQUIRE(*t.begin() == 10);
	REQUIRE(*++t.begin() == 9);
	REQUIRE(*--++t.begin() == 10);
	REQUIRE(*(t.begin() + 2) == 4);
	
	AVLTree_iterator<int> i(t.begin());
	
	REQUIRE(*i++ == 10);
	REQUIRE(*i++ == 9);
	REQUIRE(*i == 4);

	AVLTree_iterator<int> j(i);
	
	j = j + 2;

	REQUIRE(*j-- == 1);
	REQUIRE(*j-- == 3);
	REQUIRE(i == j++);
	REQUIRE(i != j);
	REQUIRE((i > j) == true);
	REQUIRE((j > i) == false);
	REQUIRE((j < i) == true);
	REQUIRE((i < j) == false);

	j = j - 2;

	REQUIRE(*j == 9);
}

TEST_CASE("Adding/deleting one/multiple item/s (std::string)") {
	AVLTree<std::string> t;

	SECTION("Adding and deleting one item") {
		t.push("abc");

		REQUIRE_FALSE(t.empty());
		REQUIRE(*t.begin() == "abc");

		t.erase(t.begin());

		REQUIRE(t.empty());
	}

	SECTION("Adding and deleting multiple items") {
		t.push("a");
		t.push("aa");
		t.push("aaa");
		t.push("aaaa");
		t.push("aaaaa");

		REQUIRE(*t.begin() == "aaaaa");
		REQUIRE(*--t.end() == "a");

		t.erase(t.begin());

		REQUIRE(*t.begin() == "aaaa");

		t.erase(--t.end());
		REQUIRE(*--t.end() == "aa");

		REQUIRE(t.size() == 3);
		REQUIRE_FALSE(t.empty());

		t.erase(t.begin());
		t.erase(t.begin());
		t.erase(t.begin());

		REQUIRE(t.size() == 0);
		REQUIRE(t.empty());
	}
}