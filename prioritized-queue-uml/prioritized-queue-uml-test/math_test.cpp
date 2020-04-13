#include "catch.hpp"
#include "..\prioritized-queue-uml\figures\mathematical functions\Math.h"
#include "..\prioritized-queue-uml\figures\mathematical functions\Math.cpp"
#include "..\prioritized-queue-uml\figures\Line.h"
#include "..\prioritized-queue-uml\figures\Line.cpp"
#include "..\prioritized-queue-uml\figures\Circle.h"
#include "..\prioritized-queue-uml\figures\Circle.cpp"
#include <vector>

TEST_CASE("Square equations solver function test") {
	std::vector<double> ans;

	SECTION("x = const") {
		ans = squareEquationSolver(0, 1, -5);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0] == 5);
	}

	SECTION("0 = 0") {
		ans = squareEquationSolver(0, 0, 0);
		REQUIRE(ans.size() == 0);
	}

	SECTION("(x-const)^2 = 0") {
		ans = squareEquationSolver(1, 2, 1);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0] == -1);
	}

	SECTION("const*x = 0") {
		ans = squareEquationSolver(0, 9, 0);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0] == 0);
	}

	SECTION("const*x^2 = 0") {
		ans = squareEquationSolver(4, 0, 0);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0] == 0);
	}

	SECTION("const = 0") {
		ans = squareEquationSolver(0, 0, 3);
		REQUIRE(ans.size() == 0);
	}

	SECTION("a*x^2 = c") {
		ans = squareEquationSolver(4, 0, -1);
		REQUIRE(ans.size() == 2);
		REQUIRE(((ans[0] == 0.5) || (ans[1] == 0.5)));
		REQUIRE(((ans[0] == -0.5) || (ans[1] == -0.5)));
	}

	SECTION("b*x = -c") {
		ans = squareEquationSolver(0, 4, 6);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0] == -(6.0 / 4.0));
	}

	SECTION("no roots full equation") {
		ans = squareEquationSolver(4, 6, 8);
		REQUIRE(ans.size() == 0);
	}

	SECTION("two roots full eqaution") {
		ans = squareEquationSolver(2, -3, 1);
		REQUIRE(((ans[0] == 0.5) || (ans[1] == 0.5)));
		REQUIRE(((ans[0] == 1) || (ans[1] == 1)));
	}
}

TEST_CASE("Find symmetric dot function test") {
	std::pair<double, double> ans;

	SECTION("x = const (b == 0)") {
		//x = 2
		Line line(3, 0, -6);
		std::pair<double, double> dot(5.0, 2.0);
		ans = findSymmetricDot(line, dot);
		REQUIRE(line.to_string() == "x = 2");
		REQUIRE(ans.first == -1.0);
		REQUIRE(ans.second == 2.0);
	}

	SECTION("y = const (a == 0)") {
		//y = -3
		Line line(0, -3, -9);
		std::pair<double, double> dot(-4.0, 1.0);
		ans = findSymmetricDot(line, dot);
		REQUIRE(line.to_string() == "y = -3");
		REQUIRE(ans.first == -4.0);
		REQUIRE(ans.second == -7.0);
	}

	SECTION("y = x") {
		Line line(1, -1, 0);
		std::pair<double, double> dot(0.0, 0.0);
		ans = findSymmetricDot(line, dot);
		REQUIRE(line.to_string() == "y = 1 * x");
		REQUIRE(ans.first == 0.0);
		REQUIRE(ans.second == 0.0);

		dot.first = 3.0;
		dot.second = 4.0;
		ans = findSymmetricDot(line, dot);
		REQUIRE(ans.first == 4.0);
		REQUIRE(ans.second == 3.0);
	}

	SECTION("1, 2, 3 quarters") {
		Line line(std::pair<double, double>(0.0, 7.0), std::pair<double, double>(-4.0, 0.0));
		std::pair<double, double>dot(0.0, 0.0);
		std::pair<double, double>symdot(-28.0 * 14.0 / 65.0, 16.0 * 14.0 / 65.0);
		ans = findSymmetricDot(line, dot);
		REQUIRE(line.to_string() == "(0,7) , (-4,0)");
		REQUIRE(ans.first == symdot.first);
		REQUIRE(ans.second == symdot.second);
	}

	SECTION("1, 2, 4 quarters") {
		Line line(-6.0 / 17.0, -6.3, 25.0);
		std::pair<double, double>dot(-2,-21);
		ans = findSymmetricDot(line, dot);
		REQUIRE(line.to_string() == "(0,3.96825) , (70.8333,0)");
		REQUIRE(ans.first == 2.0*(((-60.0/(17.0*63.0))*(25.0/6.3+21.0)+2.0)/(-(-60.0/(17.0*63.0))*(-60.0/(17.0*63.0))-1.0))+2.0);
		REQUIRE(ans.second == 2.0 * (-60.0 / (17.0 * 63.0)) * (((25.0 / 6.3 + 21) * (-60.0 / (17.0 * 63.0)) + 2) / (-(-60.0 / (17.0 * 63.0)) * (-60.0 / (17.0 * 63.0)) - 1)) + 2.0 * 25.0 / 6.3 + 21);
	}
}

TEST_CASE("Find inverse dot relatively to the circle") {
	Circle circle(0, 0, 10);
	std::pair<double, double> ans;

	SECTION("Dot same as center") {
		ans = std::make_pair<double,double>(0, 0);
		std::pair<double, double> cur = ans;
		inversePoint(ans, circle);
		REQUIRE(cur.first == ans.first);
		REQUIRE(cur.second == ans.second);
	}

	SECTION("Dot in the circle") {
		ans = std::make_pair<double,double>(5, 1);
		inversePoint(ans, circle);
		REQUIRE(ans.first == 500.0/26.0);
		REQUIRE(ans.second == 100.0/26.0);
	}


	SECTION("Dot on the circle") {
		ans = std::make_pair<double, double>(10, 0);
		inversePoint(ans, circle);
		REQUIRE(ans.first == 10.0) ;
		REQUIRE(ans.second == 0.0);
	}

	SECTION("Dot outside the circle") {
		ans = std::make_pair<double, double>(10, 10);
		inversePoint(ans, circle);
		REQUIRE(ans.first == 5.0);
		REQUIRE(ans.second == 5.0);
	}
}