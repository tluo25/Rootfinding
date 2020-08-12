//(C) Copyright Tania Luo, 2019 with supervision from Daniel Hanson
// Steffenson.h contains the functions needed to execute the Steffenson method of rootfinding in C++

#ifndef STEFFENSON_H
#define STEFFENSON_H

#include <cmath>
#include <limits>

namespace qdh 
{
	namespace root_finding 
	{

		using Real = double;

		template<class F>
		auto steffensonMethod(F f, Real initialGuess, Real tol = std::sqrt(std::numeric_limits<Real>::epsilon()), unsigned int maxIterations = 100000, 
			Real guessZero = std::sqrt(std::numeric_limits<Real>::epsilon()))
		{
			//We first check to see if the initial guess is already a root of the target function
			if (std::abs(f(initialGuess)) < guessZero)
			{
				return initialGuess;
			}

			Real x_n_1 = initialGuess;
			Real x_n = 0.0;

			for (unsigned int i = 0; i < maxIterations; ++i)
			{
				//Formula for Steffensen's method from An Introduction to Numerical Analysis, 2nd ed., Atkinson 1989
				Real D = f(x_n_1 + f(x_n_1)) - f(x_n_1);
				x_n = x_n_1 - ((f(x_n_1)*f(x_n_1)) / D);
				if (std::abs(x_n_1 - x_n) < tol)
				{
					return x_n;
				}
				x_n_1 = x_n;
			}

			return x_n;
			return std::numeric_limits<Real>::infinity();
		}

	} 
}

#endif // !STEFFENSON_H

