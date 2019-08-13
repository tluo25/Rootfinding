#include "Functions.h"
#include <cmath>

Quadratic::Quadratic(double a, double b, double c): a_(a), b_(b), c_(c) { }

double Quadratic::operator() (double x) const
{
	return a_ * x * x + b_ * x + c_;
}

Log::Log(double a, double b) : a_(a), b_(b) { }

double Log::operator() (double x) const
{
	if (x - b_ > epsilon_)
	{
		return a_ * std::log(x - b_);
	}
	else
	{
		//Since we cannot take the natural log of a nonpositive number, any input resulting in a nonpositive number will return "nan"
		return std::numeric_limits<double>::quiet_NaN();
	}
}

Trig::Trig(double a, double b) : a_(a), b_(b) { }

double Trig::operator() (double x) const
{
	return std::sin(a_ * x) - std::cos(b_ * x);
}