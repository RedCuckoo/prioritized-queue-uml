#include "catch.hpp"
#include "..\prioritized-queue-uml\figures\Line.h"
#include "..\prioritized-queue-uml\figures\Circle.h"
#include <cmath>
#include <string>

TEST_CASE("Line contructors") {
	Line line1(3, 6, 7);
	Line line2(std::pair<double, double>(0, -7 / 6.0), std::pair<double, double>(-7 / 3.0, 0));
	Line line3 = line1;

	REQUIRE(line1 == line2);
	REQUIRE(line3 == line2);
	REQUIRE_FALSE(line1 != line3);
}

TEST_CASE("Circle constructor") {
	Circle circle1(7, 3, 2);
	Circle circle2(7, 3, 2);

	REQUIRE(circle1 == circle2);
	REQUIRE_FALSE(circle1 != circle2);
	REQUIRE("(7, 3), radius = 2" == circle1.to_string());
}

TEST_CASE("Intersection functions tests") {
	Circle circle1(7, 3, 2);
	Circle circle2(0, 0, 5);
	Line line1(3, 6, 7);
	Line line2(5, 5, 0);
	std::vector<std::pair<double, double>> ans;

	SECTION("Vise verse intersection") {
		REQUIRE(line1.intersection(circle1) == circle1.intersection(line1));
	}

	SECTION("Zero-circle with y = -x") {
		ans = circle2.intersection(line2);
		REQUIRE(ans.size() == 2);
		REQUIRE((is_equal(ans[0].first, -5 / sqrt(2)) || is_equal(ans[0].first, 5 / sqrt(2))));
		REQUIRE((is_equal(ans[0].second, 5 / sqrt(2)) || is_equal(ans[0].second, -5 / sqrt(2))));
		REQUIRE((is_equal(ans[1].first, 5 / sqrt(2)) || is_equal(ans[1].first, -5 / sqrt(2))));
		REQUIRE((is_equal(ans[1].second, -5 / sqrt(2)) || is_equal(ans[1].second, 5 / sqrt(2))));
	}

	SECTION("No points") {
		ans = line1.intersection(circle1);
		REQUIRE(ans.size() == 0);
	}

	SECTION("Line with circle") {
		ans = line1.intersection(circle2);
		REQUIRE(ans.size() == 2);

		std::vector <double> y_point = squareEquationSolver(5, 28.0 / 3.0, -176.0 / 9.0);
		REQUIRE(y_point.size() == 2);
		std::vector<double> x_point = { -2.0 * y_point[0] - 7.0 / 3.0,-2.0 * y_point[1] - 7.0 / 3.0 };

		REQUIRE((is_equal(ans[0].first, x_point[0]) || is_equal(ans[0].first, x_point[1])));
		REQUIRE((is_equal(ans[0].second, y_point[0]) || is_equal(ans[0].second, y_point[1])));
		REQUIRE((is_equal(ans[1].first, x_point[0]) || is_equal(ans[1].first, x_point[1])));
		REQUIRE((is_equal(ans[1].second, y_point[0]) || is_equal(ans[1].second, y_point[1])));
	}


	SECTION("Intersection with itself") {
		REQUIRE(circle1.intersection(circle1).size() == 0);
		REQUIRE(line1.intersection(line1).size() == 0);
	}

	SECTION("Line with line") {
		ans = line1.intersection(line2);
		REQUIRE(ans.size() == 1);
		REQUIRE(ans[0].first == 7.0 / 3);
		REQUIRE(ans[0].second == -7.0 / 3);
	}

	SECTION("Circle with circle no points of intersection") {
		ans = circle1.intersection(circle2);
		REQUIRE(ans.size() == 0);
	}

	SECTION("Circle with circle") {
		Circle circle3(7, 3, 3);
		ans = circle2.intersection(circle3);
	
		REQUIRE(ans.size() == 2);
		REQUIRE((is_equal(ans[0].first, 4.0) || is_equal(ans[1].first, 4.0)));
		REQUIRE((is_equal(ans[0].second, 3.0) || is_equal(ans[1].second, 3.0)));
	}
}

TEST_CASE("Reflection of line over line") {
	//not checking circle over line cause its just a hidden Math.h function findSymmetricDot
	//TODO: if more factoring - reflect function has to return via return value not the reference
	Line line1(1, 0, 0);
	Line line2(7, -3, 9);
	Line line3(-7, -3, 9);
	line2.reflectOverLine(line1);
	REQUIRE(line2 == line3);
}

TEST_CASE("Inversion") {
	//TODO: this test case has to be extended
	Circle circle(4, 5, 3);
	Circle cur_circle = circle;
	Line ans;

	SECTION("Inversing into itself") {
		ans = circle.inverse(circle);
		REQUIRE(ans == Line());
		REQUIRE(cur_circle == circle);
	}

	SECTION("Inversing relatively to the circle, the center of which lies on the current circle") {
		//TODO: inversion have to be fixed for special line (when one of the coefs = 0)
		Circle circle1(6.4, 3.2, 4);
		ans = circle.inverse(circle1);
		REQUIRE(ans != Line());
		circle = ans.inverse(circle1);
		REQUIRE(circle == cur_circle);
	}
}