#include "catch.hpp"
#include "Steffenson.h"
#include "Functions.h"

using qdh::root_finding::steffensonMethod;

Quadratic c(1.0, 3.0, 2.0); //x= -2, x = -1
Log d(1.0, 2.0); // x = 3
unsigned int defaultIterations = 100000;

TEST_CASE("Steffenson's Method Root-finding for Polynomials", "[Steffpoly]")
{
	CHECK(steffensonMethod(c, -1.999) == Approx(-2.0));
	CHECK(steffensonMethod(c, -2.001) == Approx(-2.0));
	CHECK(steffensonMethod(c, -1.001) == Approx(-1.0));
	CHECK(steffensonMethod(c, -0.999) == Approx(-1.0));


	CHECK(steffensonMethod([](double x) {return x * x * x + 1; }, -1.001) == Approx(-1.0));
	CHECK(steffensonMethod([](double x) {return x * x * x + 1; }, -1.0001) == Approx(-1.0));
	CHECK(steffensonMethod([](double x) {return x * x * x + 1; }, -1.00001) == Approx(-1.0));
	CHECK(steffensonMethod([](double x) {return x * x * x + 1; }, -1.000001) == Approx(-1.0));
	CHECK(steffensonMethod([](double x) {return x * x * x + 1; }, -1.0000001) == Approx(-1.0));

	CHECK(steffensonMethod([](double x) {return (x - 2) * (x + 2); }, 1.999) == Approx(2.0));
	CHECK(steffensonMethod([](double x) {return (x - 2) * (x + 2); }, 2.001) == Approx(2.0));
	CHECK(steffensonMethod([](double x) {return (x - 2) * (x + 2); }, -1.999) == Approx(-2.0));
	CHECK(steffensonMethod([](double x) {return (x - 2) * (x + 2); }, -2.001) == Approx(-2.0));

	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.1); }, -0.0999) == Approx(-0.1));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.1); }, -0.1001) == Approx(-0.1));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.1); }, 0.0999) == Approx(0.1));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.1); }, 0.1001) == Approx(0.1));

	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.2); }, 0.099) == Approx(0.1));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.2); }, 0.101) == Approx(0.1));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.2); }, -0.199) == Approx(-0.2));
	CHECK(steffensonMethod([](double x) {return (x - 0.1) * (x + 0.2); }, -0.201) == Approx(-0.2));

	CHECK(steffensonMethod([](double x) {return x * x; }, 0.001) == Approx(0.0).scale(0.1));
}
TEST_CASE("Steffenson's Method Root-finding for Log Functions", "[SteffLog]")
{
	CHECK(steffensonMethod(d, 2.99) == Approx(3.0));
	CHECK(steffensonMethod(d, 2.999) == Approx(3.0));

	CHECK(steffensonMethod(d, 3.01) == Approx(3.0));
	CHECK(steffensonMethod(d, 3.001) == Approx(3.0));

	CHECK(steffensonMethod(d, 3.0) == Approx(3.0));
}
TEST_CASE("Steffensen's Method Root-finding for Trig Functions", "[SteffTrig]")
{
	CHECK(steffensonMethod([](double x) {return std::sin(x); }, 0.001) == Approx(0.0).scale(0.1));
}