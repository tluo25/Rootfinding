# Rootfinding
C++ Rootfinding Project: A library of root-finding functions utilizing modern C++ to code straightforward and intuitive methods of root-finding.

## Table of Contents
* [Introduction](#introduction)
* [Installation](#installation)
* [Default Values](#defaultValues)
* [Available Functions](#functions)
  - [Steffensen's Method](#steffensen)
    - [Parameters](#steffParameters)
  - [Bisection Method](#bisection)
    - [Parameters](#biParameters)
* [References](#references)

## <a name = "introduction"></a> Introduction
With the implementation of lambdas in modern C++, it has become easier to perform operations on functions. With this library, we hope to create a library of .h header files to make rootfinding in C++ more simple and less time-consuming. The .h files included in this library do not have any other dependencies and work on any compilier.

## <a name = "installation"></a> Installation
There are no special actions needed for installation or compilation. Download the desired header file for your project and use 
```cpp 
#include "[file_name].h" 
``` 
in your .cpp or .h file to use the functions in the header file.

## <a name = "defaultValues"></a> Default Values
For all functions in this library, the assigned default value for tolerance is the square root of the machine epsilon. 
The default number of maximum iterations varies by function and is noted under the documentation for each function. 
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

### <a name = "bisection"></a> Bisection Method
The basic algorithm for the bisection method is:

x<sub>n</sub> = 

#### <a name = "biParameters"></a> Parameters
The function all for the bisection method is:
```cpp
 bisection(F f, Real a, Real b, Real tol, unsigned int maxIterations, Real guessZero)
```

## <a name = "references"></a> References
[1] R.L Burden and J. D. Faires, *Numerical Analysis*, 5th ed., PWS Publishing Company, Boston, MA, 1993

[2] K.E. Atkinson, *An Introduction to Numerical Analysis*, 2nd ed., John Wiley and Sons, Inc., Hoboken, NJ, 1989

[3] S.D. Conte and C de Boor, *Elementary Numerical Analysis: An Algorithmic Approach*, 3rd ed., McGraw-Hill Book Company, New York City, New York, 1980

[4] L. Råde and B. Westergren, *Mathematics Handbook for Science and Engineering*, 5th Ed. Springer-Verlag, Berlin, Heidelberg, 2010

[5] J. Solomon, *Numerical Algorithms: Methods for Computer Vision, Machine Learning*, and Graphics, CRC Press, Boca Raton, FL, 2015
