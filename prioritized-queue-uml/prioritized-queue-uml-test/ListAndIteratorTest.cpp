#include "catch.hpp"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\List.h"
#include "..\prioritized-queue-uml\priority_queue_data_structure\data_structures\List_iterator.h"
#include <string>

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

	SECTION("Adding/inserting and deleting multiple items") {
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

		l.insert(++l.begin(), 7);
		
		REQUIRE(l.size() == 4);
		REQUIRE_FALSE(l.empty());
		REQUIRE(*++l.begin() == 7);

		l.erase(l.begin());
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

	SECTION("Adding to the list, that was recently emptied") {
		l.push_back(2);
		l.erase(l.begin());
		l.push_back(1);

		REQUIRE(*l.begin() == 1);
		REQUIRE(l.size() == 1);
	}
}

TEST_CASE("Testing iterator overloaded operators in list (int)") {
	List<int> l;

	l.push_back(3);
	l.push_back(9);
	l.push_back(1);
	l.push_back(10);
	l.push_back(4);

	REQUIRE(*l.begin() == 3);
	REQUIRE(*++l.begin() == 9);
	REQUIRE(*--++l.begin() == 3);
	REQUIRE(*(l.begin() + 2) == 1);

	List_iterator<int> i(l.begin());

	REQUIRE(*i++ == 3);
	REQUIRE(*i++ == 9);
	REQUIRE(*i == 1);

	List_iterator<int> j(i);

	j = j + 2;

	REQUIRE(*j-- == 4);
	REQUIRE(*j-- == 10);
	REQUIRE(i == j++);
	REQUIRE(i != j);

	j = j - 2;

	REQUIRE(*j == 9);
}

TEST_CASE("Adding/deleting one/multiple item/s in list (std::string)") {
	List<std::string> l;

	SECTION("Adding and deleting one item") {
		l.push_back("abc");

		REQUIRE_FALSE(l.empty());
		REQUIRE(*l.begin() == "abc");

		l.erase(l.begin());

		REQUIRE(l.empty());
	}

	SECTION("Adding and deleting multiple items") {
		l.push_back("a");
		l.push_back("aa");
		l.push_back("aaa");
		l.push_back("aaaa");
		l.push_back("aaaaa");

		REQUIRE(*l.begin() == "a");
		REQUIRE(*--l.end() == "aaaaa");

		l.erase(l.begin());

		REQUIRE(*l.begin() == "aa");

		l.erase(--l.end());
		REQUIRE(*--l.end() == "aaaa");

		REQUIRE(l.size() == 3);
		REQUIRE_FALSE(l.empty());

		l.erase(l.begin());
		l.erase(l.begin());
		l.erase(l.begin());

		REQUIRE(l.size() == 0);
		REQUIRE(l.empty());
	}
}