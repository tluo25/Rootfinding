#ifndef BISECTION_H
#define BISECTION_H

#include <cmath>
#include <limits>

namespace qdh {
	namespace root_finding {

		using Real = double;

		template<class F>
		auto bisection(F f, Real a, Real b, Real tol = std::sqrt(std::numeric_limits<Real>::epsilon()),
			unsigned int maxIterations = 1000, Real guessZero = std::sqrt(std::numeric_limits<Real>::epsilon()))
		{
			//Check that the two inital guesses are not zeroes already
			if (std::abs(f(a)) < guessZero)
			{
				return a;
			}
			if (std::abs(f(b)) < guessZero)
			{
				return b;
			}
			if (f(b) * f(a) > 0)
			{
				return std::numeric_limits<Real>::infinity();
			}
			//Algorithm for bisection method adapted from Numerical Analysis, 5th Edition, Burden and Faires, 1993
			// and An Introduction to Numerical Analysis, 2nd Eidtion, K. Atkinson, 1989
			for (unsigned int i = 0; i < maxIterations; ++i)
			{
				Real c = (a + b) / 2;
				if ((std::abs(b-c)/std::abs(b)) < tol)
				{
					return c;
				}

				if (f(b) * f(c) <= 0)
				{
					a = c;
				}
				else
				{
					b = c;
				}
			}
			return std::numeric_limits<Real>::infinity();
		}
} }

#endif // !BISECTION_H

