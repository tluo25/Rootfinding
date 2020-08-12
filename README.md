# Rootfinding
C++ Rootfinding Project: A library of root-finding functions utilizing modern C++ to code straightforward and intuitive methods of root-finding.

## Table of Contents
* [Introduction](#introduction)
* [Installation](#installation)
* [Default Values](#defaultValues)
* [Available Functions](#functions)
  - [Steffensen's Method](#steffensen)
    - [Parameters](#steffParameters)
    - [Conditions](#steffConditions)
  - [Bisection Method](#bisection)
    - [Parameters](#biParameters)
* [References](#references)

## <a name = "introduction"></a> Introduction
With the implementation of lambdas in modern C++, it has become easier to perform operations on functions. With this library, we hope to create a library of .h header files to make rootfinding in C++ more simple and less time-consuming. The .h files included in this library do not have any other dependencies and work on any compilier.

The functions in this library are not meant to be used to solve for roots haphazardly. The user should have an estimate of where the roots are.

## <a name = "installation"></a> Installation
There are no special actions needed for installation or compilation. Download the desired header file for your project and use 
```cpp 
#include "[file_name].h" 
``` 
in your .cpp or .h file to use the functions in the header file.

## <a name = "defaultValues"></a> Default Values
For all functions in this library, the assigned default value for tolerance is the square root of the machine epsilon. A derivation from Numerical Recipes [6] shows this tolerance value to allow for floating point arithmetic errors. 

The default number of maximum iterations varies by function and is noted under the documentation for each function. Some functions require a higher default numer of maximum iterations than others. 

We also use the alias
```cpp
using double = Real
```
as we will be working with real numbers exclusively.

## <a name = "functions"></a> Available functions
### <a name = "steffensen"></a> Steffensen's Method
The basic algorithm for Steffensen's Method is:

x<sub>n</sub> = x<sub>n-1</sub>

#### <a name = "steffParameters"></a> Parameters
The function call for Steffensen's method is:

```cpp
steffensonMethod(F f, Real initialGuess, Real tol, unsigned int maxIterations, Real guessZero)
```

`f` is a templated parameter which can be taken in as either a lambda or a pre-defined function call to a mathematical expression created by the user. `initialGuess` is a real value which represents an initial guess of what the root of the function might be. 

The default values for `tol` and `guessZero` are the square root of machine epsilon. `tol` is used as the convergence tolerance while `guessZero` is used to determine if `initialGuess` yields a value which is close enough to 0. If `initalGuess` is close enough to zero, the function returns the value of `initialGuess` as the root.

#### <a name = "steffConditions"></a> Conditions
* for f(&alpha;) = 0, f'(&alpha;) &NotEqual; 0, f'(&alpha;) &isin; (-1,0) must be true.

### <a name = "bisection"></a> Bisection Method
The basic algorithm for the bisection method is:

c = 

#### <a name = "biParameters"></a> Parameters
The function all for the bisection method is:
```cpp
 bisection(F f, Real a, Real b, Real tol, unsigned int maxIterations, Real guessZero)
```

## <a name = "references"></a> References
[1] R.L. Burden and J. D. Faires, *Numerical Analysis*, 5th Ed., PWS Publishing Company, Boston, MA, 1993

[2] K.E. Atkinson, *An Introduction to Numerical Analysis*, 2nd Ed., John Wiley and Sons, Inc., Hoboken, NJ, 1989

[3] S.D. Conte and C de Boor, *Elementary Numerical Analysis: An Algorithmic Approach*, 3rd Ed., McGraw-Hill Book Company, New York City, New York, 1980

[4] L. Råde and B. Westergren, *Mathematics Handbook for Science and Engineering*, 5th Ed. Springer-Verlag, Berlin, Heidelberg, 2010

[5] J. Solomon, *Numerical Algorithms: Methods for Computer Vision, Machine Learning, and Graphics*, CRC Press, Boca Raton, FL, 2015

[6] W.H. Press, S.A. Teukolsky, W.T. Vetterling, and B. P. Flannery, *Numerical Recipes*, 3rd Ed., Cambridge University Press, New York City, New York, 2007 
