#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits>
#include <iostream>

class Function
{
public:
	virtual double operator() (double x) const = 0;
	virtual ~Function() = default;
};

class Quadratic :public Function
{
public:
	Quadratic(double a, double b, double c);
	virtual double operator() (double x) const override;
private:
	double a_;
	double b_; 
	double c_;
};

class Log :public Function
{
public:
	Log(double a, double b);
	virtual double operator() (double x) const override;
private:
	double a_;
	double b_;
	double epsilon_ = 10000 * std::numeric_limits<double>::epsilon();
};

class Trig :public Function
{
public:
	Trig(double a, double b);
	virtual double operator() (double x) const override;
private:
	double a_;
	double b_;
};

#endif //FUNCTIONS_H