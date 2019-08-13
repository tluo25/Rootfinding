#include "catch.hpp"
#include "Functions.h"
#include "Bisection.h"

using qdh::root_finding::bisection;
//using qdh::root_finding::bisectionWithNewtons;

TEST_CASE("Bisection Method Root-finding for polynomials", "[BiPoly]")
{
	CHECK(bisection([](double x) {return x * x + 3.0 * x + 2.0; }, -3.0, 0.0) == std::numeric_limits<double>::infinity());
	CHECK(bisection([](double x) {return x * x + 3.0 * x + 2.0; }, -3.0, -1.5) == Approx(-2.0));
	CHECK(bisection([](double x) {return x * x + 3.0 * x + 2.0; }, -30.0, -1.000001) == Approx(-2.0));
	CHECK(bisection([](double x) {return x * x + 3.0 * x + 2.0; }, 0.0, -1.0) == -1.0);
	CHECK(bisection([](double x) {return x * x * x; }, -5.0, 1.0) == Approx(0.0).scale(0.1));
	CHECK(bisection([](double x) {return x * x * x + 1; }, -10.0, 0.0) == Approx(-1.0));
	CHECK(bisection([](double x) {return std::pow(x, 7); }, -3.0, 3.0) == Approx(0.0).scale(0.1));
}
TEST_CASE("Bisection Method Root-finding for log functions", "[BiLog]")
{
	CHECK(bisection([](double x) {return std::log(x - 2); }, 2.5, 5.0) == Approx(3.0));
	CHECK(bisection([](double x) {return std::log(x - 2); }, 2.5, 500.0) == Approx(3.0));
}
TEST_CASE("Bisection Method Root-finding for trig functions", "[BiTrig]")
{

	CHECK(bisection([](double x) {return std::sin(x); }, -1.0, 3.0) == Approx(0.0).scale(0.1));
}